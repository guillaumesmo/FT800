#include "xc.h"

#include "FT800.h"

#include <string.h>

unsigned short dli;
unsigned short cmd_offset = 0;

void host_command(ft_uint8_t command){
    FT800_StartTransmission();
    tr8(command);
    tr8(0);
    tr8(0);
    FT800_StopTransmission();
}

void wr8(unsigned short long addr, ft_uint8_t value){
    FT800_StartTransmission();
    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);
    tr8(value);
    FT800_StopTransmission();
}

void wr16(unsigned short long addr, ft_uint16_t value){
    FT800_StartTransmission();
    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);
    tr16(value);
    FT800_StopTransmission();
}

void wr32(unsigned short long addr, ft_uint32_t value){
    FT800_StartTransmission();
    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);
    tr32(value);
    FT800_StopTransmission();
}

ft_uint8_t wr8s(unsigned short long addr, const ft_char8_t *s)
{
    FT800_StartTransmission();
    tr8(0x80 | (addr >> 16));
    tr8(addr >> 8);
    tr8(addr);
    ft_uint8_t l = strlen(s);
    ft_uint8_t i;
    for(i=0;i<=l;i++){
        SSPBUF = s[i];
        while(!SSPSTATbits.BF);
    }
    for(;i%4>0;i++){
        SSPBUF = 0;
        while(!SSPSTATbits.BF);
    }
    FT800_StopTransmission();
    return i;
}

ft_uint8_t rd8(unsigned short long addr){
    FT800_StartTransmission();
    tr8(addr >> 16);
    tr8(addr >> 8);
    tr8(addr);
    tr8(0); // dummy byte
    tr8(0);
    FT800_StopTransmission();
    return SSPBUF;
}

ft_uint16_t rd16(unsigned short long addr){
    FT800_StartTransmission();
    tr8(addr >> 16);
    tr8(addr >> 8);
    tr8(addr);
    tr8(0); // dummy byte
    tr8(0);
    ft_uint8_t temp = SSPBUF;
    tr8(0);
    FT800_StopTransmission();
    return ((ft_uint16_t)SSPBUF << 8) | temp;
}

ft_uint32_t rd32(unsigned short long addr){
    FT800_StartTransmission();
    tr8(addr >> 16);
    tr8(addr >> 8);
    tr8(addr);
    tr8(0); // dummy byte
    tr8(0);
    ft_uint32_t temp = SSPBUF;
    tr8(0);
    temp |= (ft_uint32_t)SSPBUF << 8;
    tr8(0);
    temp |= (ft_uint32_t)SSPBUF << 16;
    tr8(0);
    FT800_StopTransmission();
    return ((ft_uint32_t)SSPBUF << 24) | temp;
}

/*
ft_char8_t * rd8s(unsigned short long addr, ft_uint8_t len)
{
    FT800_StartTransmission();
    tr8(addr >> 16);
    tr8(addr >> 8);
    tr8(addr);
    tr8(0); // dummy byte
    ft_char8_t *s = (ft_char8_t*) malloc (len+1);
    ft_uint8_t i;
    for(i=0;i<=len;i++){
        tr8(0);
        s[i] = SSPBUF;
    }
    s[len]=0;
    FT800_StopTransmission();
    return s;
}
*/

void cmd_incrementn(unsigned char n){
    cmd_offset=(cmd_offset+n)%4096;
}

void cmd(ft_uint32_t command){
    wr32(RAM_CMD + cmd_offset, command);cmd_increment4();
}

#define ACTIVE  0x00
#define STANDBY 0x41
#define SLEEP   0x42
#define PWRDOWN 0x50
#define CLKEXT  0x44
#define CLK48M  0x62
#define CLK36M  0x61
#define CORERST 0x68

inline void FT800_Init(){

    PIN_PD = 0;
    __delay_ms(20);
    PIN_PD = 1;
    __delay_ms(20);

    host_command(ACTIVE); //send host command "ACTIVE" to FT800

    host_command(CLKEXT); //send command to "CLKEXT" to FT800

    host_command(CLK48M); //send command to "CLKEXT" to FT800

    // Configure display registers - demonstration for WQVGA resolution
    wr16(REG_HSIZE, 480); // width resolution
    wr16(REG_VSIZE, 272); // height resolution
    wr16(REG_HCYCLE, 525); // number if horizontal cycles for display
    wr16(REG_HSYNC0, 0); // hsync falls
    wr16(REG_HSYNC1, 41); // hsync rise
    wr16(REG_HOFFSET, 43); // horizontal offset from starting signal
    wr16(REG_VCYCLE, 286); // number of vertical cycles for display
    wr16(REG_VSYNC0, 0); // vsync falls
    wr16(REG_VSYNC1, 10); // vsync rise
    wr16(REG_VOFFSET, 12); // vertical offset from start signal
    wr8(REG_CSPREAD, 0); // output clock spread enable
    wr8(REG_DITHER, 0); // output number of bits
    wr16(REG_OUTBITS, 0x01B6); // output bits resolution
    wr8(REG_SWIZZLE, 0x0000); // output swizzle

    //wr8(REG_RENDERMODE, 0); // 0 normal, 1 write, 2 read
    wr8(REG_PCLK_POL, 1); // clock polarity: 0 - rising edge, 1 - falling edge
    //wr32(REG_FREQUENCY, 48000000); // main clock frequency
    wr8(REG_ROTATE, 0); // rotate display 180 degrees: 1 - rotate enable, 0 - rotate disable

    /*TRISAbits.TRISA4 = 0;
    while((rd8(REG_DLSWAP) & 0b11) != DLSWAP_DONE){LATAbits.LATA4 = 1;}
    LATAbits.LATA4 = 0;*/

    // write first display list
    wr32(RAM_DL+0,CLEAR_COLOR_RGB(255,0,0));
    wr32(RAM_DL+4,CLEAR(1,1,1));
    wr32(RAM_DL+8,DISPLAY());

    wr8(REG_DLSWAP,DLSWAP_FRAME);//display list swap

    //wr8(REG_GPIO_DIR,0x80 | rd8(REG_GPIO_DIR));
    //wr8(REG_GPIO,0x080 | rd8(REG_GPIO));//enable display bit
    //wr8(REG_GPIO,0x80);
    wr8(REG_GPIO_DIR, 0xfc);
    wr8(REG_GPIO, 0xff);

    wr8(REG_PCLK,5); // clock prescaler (0: disable, >0: 48MHz/pclock)

    cmd_wait();

}