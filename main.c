/* 
 * File:   main.c
 * Author: Guillaume
 *
 * Created on 10 novembre 2013, 18:53
 */

#include <xc.h>

#if defined(_16F1454) || defined(_16F1455) || defined(_16F1459)

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = NOCLKDIV// CPU System Clock Selection Bit (NO CPU system divide)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (4x Output Frequency Selected)
#pragma config PLLEN = ENABLED  // PLL Enable Bit (3x or 4x PLL Enabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (Low-voltage programming enabled)

#endif

#include "FT800.h"

void wait3secs(){
    __delay_ms(3000);
}

void main(void) {

    // set up oscillator
    OSCCON = 0b00111100;

    // turn off all analog pins
    ANSELC = 0;

    // set up SPI (Master mode, mode=0)

    TRISCbits.TRISC0 = 0; // SPI CLOCK
    TRISCbits.TRISC1 = 1; // SPI MISO
    TRISCbits.TRISC2 = 0; // SPI MOSI
    LATCbits.LATC3 = 0; // SPI SS: tri-stated pin (pull-up in ConnectEVE)
    PIN_CS = 1;

    SSPCON1bits.SSPEN=1; // enable SPI
    SSPCON1bits.CKP=0; // clock polarity: idle low
    SSPSTATbits.CKE=1; // clock phase: propagation on rising edge

    // ConnectEVE options

    LATCbits.LATC5 = 0; // PD: tri-stated pin (pull-up in ConnectEVE)
    PIN_PD = 1;

    TRISCbits.TRISC4 = 1; // INT

    // during init, SPI clock must not exceed 10Mhz
    // FOSC/64 = 0.75MHz (<11Mhz)
    SSP1CON1bits.SSP1M1 = 1;
    SSP1CON1bits.SSP1M0 = 0;

    FT800_Init();

    // FT800 is now inited, we can go up to 30Mhz
    // FOSC/16 = 3MHz (<30Mhz)
    SSP1CON1bits.SSP1M1 = 0;
    SSP1CON1bits.SSP1M0 = 1;

    /*
    // backlight PWM animation
    for(int i=0;i<3000;i++){
        //wr8(REG_PWM_DUTY, i%129);
        //LATAbits.LATA4 = rd8(REG_PWM_DUTY)%2;
        wr8(REG_PWM_DUTY, (rd8(REG_PWM_DUTY)+1)%129);
        __delay_ms(30);
    }

    while(1);*/

    // LOGO test
    cmd(CMD_LOGO);
    cmd_exec();
    while(rd16(REG_CMD_WRITE) != 0){}
    cmd_wait();

    cmd(CMD_DLSTART);
    cmd(CLEAR_COLOR_RGB(255,0,0));
    cmd(CLEAR(1,1,1));
    cmd_text(240, 136, 27, OPT_CENTER, "Please tap the dots to calibrate the display");
    cmd_calibrate();
    cmd_exec();
    cmd_wait();
    
    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1)); // clear screen
    cmd_button(10, 10, 140, 100, 31, 0, "Press!");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_text(10, 10, 31, 0, "Hello ceci est un test!");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_button(10, 10, 50, 25, 26, 0, "One");
    cmd_button(10, 40, 50, 25, 26, 0, "Two");
    cmd_button(10, 70, 50, 25, 26, 0, "Three");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_keys(2, 2, 156, 21, 20, OPT_CENTER, "qwertyuiop");
    cmd_keys(2, 26, 156, 21, 20, OPT_CENTER, "asdfghijkl");
    cmd_keys(2, 50, 156, 21, 20, OPT_CENTER, "zxcvbnm");
    cmd_button(2, 74, 156, 21, 20, 0, "");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_keys(22, 1, 116, 28, 29, 0, "789");
    cmd_keys(22, 31, 116, 28, 29, 0, "456");
    cmd_keys(22, 61, 116, 28, 29, 0, "123");
    cmd_keys(22, 91, 116, 28, 29, 0, "0.");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_clock(80, 60, 50, 0, 8, 15, 0, 0);
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_gauge(80, 60, 50, 0, 5, 4, 30, 100);
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd_gradient(0, 0, 0x0000ff, 160, 0, 0xff0000);
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    wait3secs();

    cmd(CMD_DLSTART);
    cmd(CLEAR(1, 1, 1));
    cmd(SCISSOR_XY(20, 40));
    cmd(SCISSOR_SIZE(120, 32));
    cmd_gradient(20, 0, 0x606060, 140, 0, 0x404080);
    cmd_text(23, 40, 29, 0, "Heading 1");
    cmd(DISPLAY()); // display the image
    cmd(CMD_SWAP);
    cmd_exec();

    

    while(1){};

}

