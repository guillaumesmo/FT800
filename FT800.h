/* 
 * File:   FT_Functions.h
 * Author: Guillaume Smolders
 *
 * Created on 25 novembre 2013, 0:25
 */

#ifndef FT800_H
#define	FT800_H

#include "config.h"

#define FT_FALSE           (0)
#define FT_TRUE            (1)

typedef unsigned char ft_uint8_t;
typedef char ft_char8_t;
typedef signed char ft_schar8_t;
typedef unsigned char ft_uchar8_t;
typedef int  ft_int16_t;
typedef unsigned int ft_uint16_t;
typedef unsigned long ft_uint32_t;
typedef long ft_int32_t;
typedef void ft_void_t;

typedef unsigned char ft_bool_t;

/* Definitions used for FT800 co processor command buffer */
#define FT_DL_SIZE           (8*1024)  //8KB Display List buffer size
#define FT_CMD_FIFO_SIZE     (4*1024)  //4KB coprocessor Fifo size
#define FT_CMD_SIZE          (4)       //4 byte per coprocessor command of EVE

#define FT800_VERSION "1.9.0"
#define ADC_DIFFERENTIAL     1UL
#define ADC_SINGLE_ENDED     0UL
#define ADPCM_SAMPLES        2UL
#define ALWAYS               7UL
#define ARGB1555             0UL
#define ARGB2                5UL
#define ARGB4                6UL
#define BARGRAPH             11UL
#define BILINEAR             1UL
#define BORDER               0UL

// section 4.2
#define BITMAPS              1UL
#define POINTS               2UL
#define LINES               3UL
#define LINE_STRIP          4UL
#define EDGE_R              5UL
#define EDGE_L              6UL
#define EDGE_A              7UL
#define EDGE_B              8UL
#define RECTS               9UL

#define CMDBUF_SIZE          4096UL
#define CMD_APPEND           4294967070UL
#define CMD_BGCOLOR          4294967049UL
#define CMD_BITMAP_TRANSFORM 4294967073UL
#define CMD_BUTTON           4294967053UL
#define CMD_CALIBRATE        4294967061UL
#define CMD_CLOCK            4294967060UL
#define CMD_COLDSTART        4294967090UL
#define CMD_CRC              4294967043UL
#define CMD_DIAL             4294967085UL
#define CMD_DLSTART          4294967040UL
#define CMD_DLSWAP           4294967041UL
#define CMD_EXECUTE          4294967047UL
#define CMD_FGCOLOR          4294967050UL
#define CMD_GAUGE            4294967059UL
#define CMD_GETMATRIX        4294967091UL
#define CMD_GETPOINT         4294967048UL
#define CMD_GETPROPS         4294967077UL
#define CMD_GETPTR           4294967075UL
#define CMD_GRADCOLOR        4294967092UL
#define CMD_GRADIENT         4294967051UL
#define CMD_HAMMERAUX        4294967044UL
#define CMD_IDCT             4294967046UL
#define CMD_INFLATE          4294967074UL
#define CMD_INTERRUPT        4294967042UL
#define CMD_KEYS             4294967054UL
#define CMD_LOADIDENTITY     4294967078UL
#define CMD_LOADIMAGE        4294967076UL
#define CMD_LOGO             4294967089UL
#define CMD_MARCH            4294967045UL
#define CMD_MEMCPY           4294967069UL
#define CMD_MEMCRC           4294967064UL
#define CMD_MEMSET           4294967067UL
#define CMD_MEMWRITE         4294967066UL
#define CMD_MEMZERO          4294967068UL
#define CMD_NUMBER           4294967086UL
#define CMD_PROGRESS         4294967055UL
#define CMD_REGREAD          4294967065UL
#define CMD_ROTATE           4294967081UL
#define CMD_SCALE            4294967080UL
#define CMD_SCREENSAVER      4294967087UL
#define CMD_SCROLLBAR        4294967057UL
#define CMD_SETFONT          4294967083UL
#define CMD_SETMATRIX        4294967082UL
#define CMD_SKETCH           4294967088UL
#define CMD_SLIDER           4294967056UL
#define CMD_SNAPSHOT         4294967071UL
#define CMD_SPINNER          4294967062UL
#define CMD_STOP             4294967063UL
#define CMD_SWAP             4294967041UL
#define CMD_TEXT             4294967052UL
#define CMD_TOGGLE           4294967058UL
#define CMD_TOUCH_TRANSFORM  4294967072UL
#define CMD_TRACK            4294967084UL
#define CMD_TRANSLATE        4294967079UL

#define DECR                 4UL
#define DECR_WRAP            7UL
#define DLSWAP_DONE          0UL
#define DLSWAP_FRAME         2UL
#define DLSWAP_LINE          1UL
#define DST_ALPHA            3UL
#define EQUAL                5UL
#define GEQUAL               4UL
#define GREATER              3UL
#define INCR                 3UL
#define INCR_WRAP            6UL
#define INT_CMDEMPTY         32UL
#define INT_CMDFLAG          64UL
#define INT_CONVCOMPLETE     128UL
#define INT_PLAYBACK         16UL
#define INT_SOUND            8UL
#define INT_SWAP             1UL
#define INT_TAG              4UL
#define INT_TOUCH            2UL
#define INVERT               5UL

#define KEEP                 1UL
#define L1                   1UL
#define L4                   2UL
#define L8                   3UL
#define LEQUAL               2UL
#define LESS                 1UL
#define LINEAR_SAMPLES       0UL
#define NEAREST              0UL
#define NEVER                0UL
#define NOTEQUAL             6UL
#define ONE                  1UL
#define ONE_MINUS_DST_ALPHA  5UL
#define ONE_MINUS_SRC_ALPHA  4UL
#define OPT_CENTER           1536UL
#define OPT_CENTERX          512UL
#define OPT_CENTERY          1024UL
#define OPT_FLAT             256UL
#define OPT_MONO             1UL
#define OPT_NOBACK           4096UL
#define OPT_NODL             2UL
#define OPT_NOHANDS          49152UL
#define OPT_NOHM             16384UL
#define OPT_NOPOINTER        16384UL
#define OPT_NOSECS           32768UL
#define OPT_NOTICKS          8192UL
#define OPT_RIGHTX           2048UL
#define OPT_SIGNED           256UL
#define PALETTED             8UL

#define RAM_G                0UL
#define ROM_CHIPID           786432UL
#define ROM_FONT             766524UL
#define ROM_FONT_ADDR        1048572UL
#define RAM_DL               1048576UL
#define RAM_PAL              1056768UL
#define RAM_REG              1057792UL
#define RAM_CMD              1081344UL



#define REG_ANALOG           1058104UL
#define REG_ANA_COMP         1058160UL
#define REG_CLOCK            1057800UL
#define REG_CMD_DL           1058028UL
#define REG_CMD_READ         1058020UL
#define REG_CMD_WRITE        1058024UL
#define REG_CPURESET         1057820UL
#define REG_CRC              1058152UL
#define REG_CYA0             1058000UL
#define REG_CYA1             1058004UL
#define REG_CYA_TOUCH        1058100UL
#define REG_DATESTAMP        1058108UL
#define REG_FRAMES           1057796UL
#define REG_FREQUENCY        1057804UL
#define REG_GPIO             1057936UL
#define REG_GPIO_DIR         1057932UL

#define REG_HCYCLE           1057832UL
#define REG_HOFFSET          1057836UL
#define REG_HSIZE            1057840UL
#define REG_HSYNC0           1057844UL
#define REG_HSYNC1           1057848UL
#define REG_VCYCLE           1057852UL
#define REG_VOFFSET          1057856UL
#define REG_VSIZE            1057860UL
#define REG_VSYNC0           1057864UL
#define REG_VSYNC1           1057868UL
#define REG_DLSWAP           1057872UL
#define REG_ROTATE           1057876UL
#define REG_OUTBITS          1057880UL
#define REG_DITHER           1057884UL
#define REG_SWIZZLE          1057888UL
#define REG_CSPREAD          1057892UL
#define REG_PCLK_POL         1057896UL
#define REG_PCLK             1057900UL

#define REG_ID               1057792UL
#define REG_INT_EN           1057948UL
#define REG_INT_FLAGS        1057944UL
#define REG_INT_MASK         1057952UL
#define REG_MACRO_0          1057992UL
#define REG_MACRO_1          1057996UL
#define REG_PLAY             1057928UL
#define REG_PLAYBACK_FORMAT  1057972UL
#define REG_PLAYBACK_FREQ    1057968UL
#define REG_PLAYBACK_LENGTH  1057960UL
#define REG_PLAYBACK_LOOP    1057976UL
#define REG_PLAYBACK_PLAY    1057980UL
#define REG_PLAYBACK_READPTR 1057964UL
#define REG_PLAYBACK_START   1057956UL
#define REG_PWM_DUTY         1057988UL
#define REG_PWM_HZ           1057984UL
#define REG_RENDERMODE       1057808UL
#define REG_ROMSUB_SEL       1058016UL
#define REG_SNAPSHOT         1057816UL
#define REG_SNAPY            1057812UL
#define REG_SOUND            1057924UL
#define REG_TAG              1057912UL
#define REG_TAG_X            1057904UL
#define REG_TAG_Y            1057908UL
#define REG_TAP_CRC          1057824UL
#define REG_TAP_MASK         1057828UL
#define REG_TOUCH_ADC_MODE   1058036UL
#define REG_TOUCH_CHARGE     1058040UL
#define REG_TOUCH_DIRECT_XY  1058164UL
#define REG_TOUCH_DIRECT_Z1Z2 1058168UL
#define REG_TOUCH_MODE       1058032UL
#define REG_TOUCH_OVERSAMPLE 1058048UL
#define REG_TOUCH_RAW_XY     1058056UL
#define REG_TOUCH_RZ         1058060UL
#define REG_TOUCH_RZTHRESH   1058052UL
#define REG_TOUCH_SCREEN_XY  1058064UL
#define REG_TOUCH_SETTLE     1058044UL
#define REG_TOUCH_TAG        1058072UL
#define REG_TOUCH_TAG_XY     1058068UL
#define REG_TOUCH_TRANSFORM_A 1058076UL
#define REG_TOUCH_TRANSFORM_B 1058080UL
#define REG_TOUCH_TRANSFORM_C 1058084UL
#define REG_TOUCH_TRANSFORM_D 1058088UL
#define REG_TOUCH_TRANSFORM_E 1058092UL
#define REG_TOUCH_TRANSFORM_F 1058096UL
#define REG_TRACKER          1085440UL
#define REG_TRIM             1058156UL
#define REG_VOL_PB           1057916UL
#define REG_VOL_SOUND        1057920UL


#define REPEAT               1UL
#define REPLACE              2UL
#define RGB332               4UL
#define RGB565               7UL
#define SRC_ALPHA            2UL
#define TEXT8X8              9UL
#define TEXTVGA              10UL
#define TOUCHMODE_CONTINUOUS 3UL
#define TOUCHMODE_FRAME      2UL
#define TOUCHMODE_OFF        0UL
#define TOUCHMODE_ONESHOT    1UL
#define ULAW_SAMPLES         1UL
#define ZERO                 0UL


#define VERTEX2F(x,y) ((1UL<<30)|(((x)&32767UL)<<15)|(((y)&32767UL)<<0))
#define VERTEX2II(x,y,handle,cell) ((2UL<<30)|(((x)&511UL)<<21)|(((y)&511UL)<<12)|(((handle)&31UL)<<7)|(((cell)&127UL)<<0))
#define BITMAP_SOURCE(addr) ((1UL<<24)|(((addr)&1048575UL)<<0))
#define CLEAR_COLOR_RGB(red,green,blue) ((2UL<<24)|(((red)&255UL)<<16)|(((green)&255UL)<<8)|(((blue)&255UL)<<0))
#define TAG(s) ((3UL<<24)|(((s)&255UL)<<0))
#define COLOR_RGB(red,green,blue) ((4UL<<24)|(((red)&255UL)<<16)|(((green)&255UL)<<8)|(((blue)&255UL)<<0))
#define BITMAP_HANDLE(handle) ((5UL<<24)|(((handle)&31UL)<<0))
#define CELL(cell) ((6UL<<24)|(((cell)&127UL)<<0))
#define BITMAP_LAYOUT(format,linestride,height) ((7UL<<24)|(((format)&31UL)<<19)|(((linestride)&1023UL)<<9)|(((height)&511UL)<<0))
#define BITMAP_SIZE(filter,wrapx,wrapy,width,height) ((8UL<<24)|(((filter)&1UL)<<20)|(((wrapx)&1UL)<<19)|(((wrapy)&1UL)<<18)|(((width)&511UL)<<9)|(((height)&511UL)<<0))
#define ALPHA_FUNC(func,ref) ((9UL<<24)|(((func)&7UL)<<8)|(((ref)&255UL)<<0))
#define STENCIL_FUNC(func,ref,mask) ((10UL<<24)|(((func)&7UL)<<16)|(((ref)&255UL)<<8)|(((mask)&255UL)<<0))
#define BLEND_FUNC(src,dst) ((11UL<<24)|(((src)&7UL)<<3)|(((dst)&7UL)<<0))
#define STENCIL_OP(sfail,spass) ((12UL<<24)|(((sfail)&7UL)<<3)|(((spass)&7UL)<<0))
#define POINT_SIZE(size) ((13UL<<24)|(((size)&8191UL)<<0))
#define LINE_WIDTH(width) ((14UL<<24)|(((width)&4095UL)<<0))
#define CLEAR_COLOR_A(alpha) ((15UL<<24)|(((alpha)&255UL)<<0))
#define COLOR_A(alpha) ((16UL<<24)|(((alpha)&255UL)<<0))
#define CLEAR_STENCIL(s) ((17UL<<24)|(((s)&255UL)<<0))
#define CLEAR_TAG(s) ((18UL<<24)|(((s)&255UL)<<0))
#define STENCIL_MASK(mask) ((19UL<<24)|(((mask)&255UL)<<0))
#define TAG_MASK(mask) ((20UL<<24)|(((mask)&1UL)<<0))
#define BITMAP_TRANSFORM_A(a) ((21UL<<24)|(((a)&131071UL)<<0))
#define BITMAP_TRANSFORM_B(b) ((22UL<<24)|(((b)&131071UL)<<0))
#define BITMAP_TRANSFORM_C(c) ((23UL<<24)|(((c)&16777215UL)<<0))
#define BITMAP_TRANSFORM_D(d) ((24UL<<24)|(((d)&131071UL)<<0))
#define BITMAP_TRANSFORM_E(e) ((25UL<<24)|(((e)&131071UL)<<0))
#define BITMAP_TRANSFORM_F(f) ((26UL<<24)|(((f)&16777215UL)<<0))
#define SCISSOR_XY(x,y) ((27UL<<24)|(((x)&511UL)<<9)|(((y)&511UL)<<0))
#define SCISSOR_SIZE(width,height) ((28UL<<24)|(((width)&1023UL)<<10)|(((height)&1023UL)<<0))
#define CALL(dest) ((29UL<<24)|(((dest)&65535UL)<<0))
#define JUMP(dest) ((30UL<<24)|(((dest)&65535UL)<<0))
#define BEGIN(prim) ((31UL<<24)|(((prim)&15UL)<<0))
#define COLOR_MASK(r,g,b,a) ((32UL<<24)|(((r)&1UL)<<3)|(((g)&1UL)<<2)|(((b)&1UL)<<1)|(((a)&1UL)<<0))
#define CLEAR(c,s,t) ((38UL<<24)|(((c)&1UL)<<2)|(((s)&1UL)<<1)|(((t)&1UL)<<0))
#define END() ((33UL<<24))
#define SAVE_CONTEXT() ((34UL<<24))
#define RESTORE_CONTEXT() ((35UL<<24))
#define RETURN() ((36UL<<24))
#define MACRO(m) ((37UL<<24)|(((m)&1UL)<<0))
#define DISPLAY() ((0UL<<24))

#define FT_GPU_NUMCHAR_PERFONT (128)
#define FT_GPU_FONT_TABLE_SIZE (148)

/* FT800 font table structure */
/* Font table address in ROM can be found by reading the address from 0xFFFFC location. */
/* 16 font tables are present at the address read from location 0xFFFFC */
typedef struct FT_Gpu_Fonts
{
	/* All the values are in bytes */
	/* Width of each character font from 0 to 127 */
	ft_uint8_t	FontWidth[FT_GPU_NUMCHAR_PERFONT];
	/* Bitmap format of font wrt bitmap formats supported by FT800 - L1, L4, L8 */
	ft_uint32_t	FontBitmapFormat;
	/* Font line stride in FT800 ROM */
	ft_uint32_t	FontLineStride;
	/* Font width in pixels */
	ft_uint32_t	FontWidthInPixels;
	/* Font height in pixels */
	ft_uint32_t	FontHeightInPixels;
	/* Pointer to font graphics raw data */
	ft_uint32_t	PointerToFontGraphicsData;
}FT_Gpu_Fonts_t;



#define FT800_StartTransmission() PIN_CS = 0
#define FT800_StopTransmission() PIN_CS = 1

extern unsigned short dli;
/**
 * Write the specified 32 bits display list command to RAM_DL. (see 2.5.4)
 */
#define dl(cmd) wr32(RAM_DL + dli, cmd);dli += 4

#define tr8(value)  SSPBUF = value;while(!SSPSTATbits.BF)
#define tr16(value) tr8((value) & 0xFF);tr8(((value) >> 8) & 0xFF)
#define tr32(value) tr16((value) & 0xFFFF);tr16(((value) >> 16) & 0xFFFF)

extern unsigned short cmd_offset;
/*#define cmd_increment4() cmd_offset=(cmd_offset==4092 ? 0 : cmd_offset+4)
#define cmd_increment2() cmd_offset=(cmd_offset==4094 ? 0 : cmd_offset+2)*/
//#define cmd_incrementn(n) cmd_offset=(cmd_offset+n)%4096
void cmd_incrementn(unsigned char n);
#define cmd_increment4() cmd_incrementn(4)
#define cmd_increment2() cmd_incrementn(2)
//#define cmd(command) wr32(RAM_CMD + cmd_offset, command);cmd_increment4()
void cmd(ft_uint32_t command);
#define cmd_exec() wr16(REG_CMD_WRITE, cmd_offset)
#define cmd_wait() cmd_offset=rd16(REG_CMD_WRITE);while(rd16(REG_CMD_READ) != cmd_offset)


/**
 * start a new display list
 */
#define cmd_dlstart() cmd(CMD_DLSTART)

/**
 * swap the current display list
 */
#define cmd_swap() cmd(CMD_DLSWAP)

/**
 * draw text
 */
#define cmd_text(x, y, font, options, s) cmd(CMD_TEXT);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, font);cmd_increment2();wr16(RAM_CMD+cmd_offset, options);cmd_increment2();cmd_incrementn(wr8s(RAM_CMD+cmd_offset, s))

/**
 * draw a decimal number
 */
#define cmd_number(x, y, font, options, n) cmd(CMD_NUMBER);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, font);cmd_increment2();wr16(RAM_CMD+cmd_offset, options);cmd_increment2();cmd(n)

/**
 * draw a button
 */
#define cmd_button(x, y, w, h, font, options, s) cmd(CMD_BUTTON);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, w);cmd_increment2();wr16(RAM_CMD+cmd_offset, h);cmd_increment2();wr16(RAM_CMD+cmd_offset, font);cmd_increment2();wr16(RAM_CMD+cmd_offset, options);cmd_increment2();cmd_incrementn(wr8s(RAM_CMD+cmd_offset, s))

/**
 * draw an analog clock
 */
#define cmd_clock(x, y, r, options, h, m, s, ms) cmd(CMD_CLOCK);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, r);cmd_increment2();wr16(RAM_CMD+cmd_offset, options);cmd_increment2();wr16(RAM_CMD+cmd_offset, h);cmd_increment2();wr16(RAM_CMD+cmd_offset, m);cmd_increment2();wr16(RAM_CMD+cmd_offset, s);cmd_increment2();wr16(RAM_CMD+cmd_offset, ms);cmd_increment2()

/**
 * set the foreground color
 */
#define cmd_fgcolor(c) cmd(CMD_FGCOLOR);cmd(c)

/**
 * set the background color
 */
#define cmd_bgcolor(c) cmd(CMD_BGCOLOR);cmd(c)

/**
 * set the 3D effects for CMD_BUTTON and CMD_KEYS highlight color
 */
#define cmd_gradcolor(c) cmd(CMD_GRADCOLOR);cmd(c)

/**
 * draw a gauge
 */
#define cmd_gauge(x, y, r, options, major, minor, val, range) cmd(CMD_GAUGE);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, r);cmd_increment2();wr16(RAM_CMD+cmd_offset, options);cmd_increment2();wr16(RAM_CMD+cmd_offset, major);cmd_increment2();wr16(RAM_CMD+cmd_offset, minor);cmd_increment2();wr16(RAM_CMD+cmd_offset, val);cmd_increment2();wr16(RAM_CMD+cmd_offset, range);cmd_increment2()

/**
 * draw a draw a smooth color gradient
 */
#define cmd_gradient(x0, y0, rgb0, x1, y1, rgb1) cmd(CMD_GRADIENT);wr16(RAM_CMD+cmd_offset, x0);cmd_increment2();wr16(RAM_CMD+cmd_offset, y0);cmd_increment2();cmd(rgb0);wr16(RAM_CMD+cmd_offset, x1);cmd_increment2();wr16(RAM_CMD+cmd_offset, y1);cmd_increment2();cmd(rgb1)

/**
 * draw a row of keys
 */
#define cmd_keys(x, y, w, h, font, options, s) cmd(CMD_KEYS);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, w);cmd_increment2();wr16(RAM_CMD+cmd_offset, h);cmd_increment2();wr16(RAM_CMD+cmd_offset, font);cmd_increment2();wr16(RAM_CMD+cmd_offset, options);cmd_increment2();cmd_incrementn(wr8s(RAM_CMD+cmd_offset, s))

/**
 * draw a progress bar
 */
#define cmd_progress(x, y, w, h, options, val, range) cmd(CMD_PROGRESS);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, w);cmd_increment2();wr16(RAM_CMD+cmd_offset, h);cmd_increment2();wr16(RAM_CMD+cmd_offset, options);cmd_increment2();wr16(RAM_CMD+cmd_offset, val);cmd_increment2();wr16(RAM_CMD+cmd_offset, range);cmd_increment2()

/**
 * draw a draw a scroll bar
 */
#define cmd_scrollbar(x, y, w, h, options, val, size, range) cmd(CMD_SCROLLBAR);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, w);cmd_increment2();wr16(RAM_CMD+cmd_offset, h);cmd_increment2();wr16(RAM_CMD+cmd_offset, options);cmd_increment2();wr16(RAM_CMD+cmd_offset, val);cmd_increment2();wr16(RAM_CMD+cmd_offset, size);cmd_increment2();wr16(RAM_CMD+cmd_offset, range);cmd_increment2()

/**
 * draw a slider
 */
#define cmd_slider(x, y, w, h, options, val, range) cmd(CMD_SLIDER);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, w);cmd_increment2();wr16(RAM_CMD+cmd_offset, h);cmd_increment2();wr16(RAM_CMD+cmd_offset, options);cmd_increment2();wr16(RAM_CMD+cmd_offset, val);cmd_increment2();wr16(RAM_CMD+cmd_offset, range);cmd_increment2()

/**
 * draw a rotary dial control
 */
#define cmd_dial(x, y, r, options, val) cmd(CMD_DIAL);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, r);cmd_increment2();wr16(RAM_CMD+cmd_offset, options);cmd_increment2();wr16(RAM_CMD+cmd_offset, val)

/**
 * draw a toggle switch
 */
#define cmd_toggle(x, y, w, font, options, state, s) cmd(CMD_TOGGLE);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, w);cmd_increment2();wr16(RAM_CMD+cmd_offset, font);cmd_increment2();wr16(RAM_CMD+cmd_offset, options);cmd_increment2();wr16(RAM_CMD+cmd_offset, state);cmd_incrementn(wr8s(RAM_CMD+cmd_offset, s))

/**
 * compute a CRC-32 for memory
 */
#define cmd_memcrc(ptr, num, result) cmd(CMD_MEMCRC);cmd(ptr);cmd(num);unsigned short cmd_memcrc_result_ptr=cmd_offset;cmd(result);cmd_wait();result=rd32(cmd_memcrc_result_ptr)

/**
 * write zero to a block of memory
 */
#define cmd_memzero(ptr, num) cmd(CMD_MEMCRC);cmd(ptr);cmd(num)

/**
 * fill memory with a byte value
 */
#define cmd_memset(ptr, value, num) cmd(CMD_MEMCRC);cmd(ptr);cmd(value);cmd(num)

/**
 * write bytes into memory
 */
#define cmd_memwrite(ptr, num)      cmd(CMD_MEMWRITE);cmd(ptr);cmd(num)

/**
 * copy a block of memory
 */
#define cmd_memcpy(dest, src, num) cmd(CMD_MEMCRC);cmd(dest);cmd(src);cmd(num)

/**
 * append memory to display list
 */
#define cmd_append(ptr, num)        cmd(CMD_APPEND);cmd(ptr);cmd(num)

/**
 * decompress data into memory
 */
#define cmd_inflate(ptr) cmd(CMD_INFLATE);cmd(ptr)

/**
 * set the current matrix to identity
 */
#define cmd_loadidentity() cmd(CMD_LOADIDENTITY)

/**
 * write the current matrix as a bitmap transform
 */
#define cmd_setmatrix() cmd(CMD_SETMATRIX)

/**
 * retrieves the current matrix coefficients
 */
#define cmd_getmatrix(a, b, c, d, e, f) cmd(CMD_GETMATRIX);unsigned short cmd_getmatrix_result_ptr=cmd_offset;cmd(0);cmd(0);cmd(0);cmd(0);cmd(0);cmd(0);cmd_exec();cmd_wait();a=rd32(cmd_getmatrix_result_ptr);b=rd32((cmd_getmatrix_result_ptr+4)%4096);c=rd32((cmd_getmatrix_result_ptr+8)%4096);d=rd32((cmd_getmatrix_result_ptr+12)%4096);e=rd32((cmd_getmatrix_result_ptr+16)%4096);f=rd32((cmd_getmatrix_result_ptr+20)%4096)

/**
 * Get the end memory address of inflated data
 */
#define cmd_getptr(result) cmd(CMD_GETPTR);unsigned short cmd_getptr_result_ptr=cmd_offset;cmd(0);cmd_wait();result=rd32(cmd_getptr_result_ptr)

/**
 * apply a scale to the current matrix
 */
#define cmd_scale(sx, sy) cmd(CMD_SCALE);cmd(sx);cmd(sy)

/**
 * apply a rotation to the current matrix
 */
#define cmd_rotate(a) cmd(CMD_ROTATE);cmd(a)

/**
 * apply a translation to the current matrix
 */
#define cmd_translate(tx, ty) cmd(CMD_TRANSLATE);cmd(tx);cmd(ty)

/**
 * load a JPEG image
 */
#define cmd_loadimage(ptr, options) cmd(CMD_LOADIMAGE);cmd(ptr);cmd(options)

/**
 * set co-processor engine state to default values
 */
#define cmd_coldstart()             cmd(CMD_COLDSTART)

/**
 * trigger interrupt INT_CMDFLAG
 */
#define cmd_interrupt(ms)           cmd(CMD_INTERRUPT);cmd(ms)

/**
 * read a register value
 */
#define cmd_regread(ptr, result)    cmd(CMD_REGREAD);cmd(ptr);cmd(result)

/**
 * execute the touch screen calibration routine
 */
#define cmd_calibrate() cmd(CMD_CALIBRATE);unsigned short cmd_calibrate_result_ptr=cmd_offset;cmd(0)
#define cmd_calibrate_result() rd32(cmd_calibrate_result_ptr)

/**
 * start an animated spinner
 */
#define cmd_spinner(x, y, style, scale) cmd(CMD_SPINNER);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, style);cmd_increment2();wr16(RAM_CMD+cmd_offset, scale);cmd_increment2()

/**
 * start an animated screensaver
 */
#define cmd_screensaver() cmd(CMD_SCREENSAVER)

/**
 * start a continuous sketch update
 */
#define cmd_sketch(x, y, w, h, ptr, format) cmd(CMD_SKETCH);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, w);cmd_increment2();wr16(RAM_CMD+cmd_offset, h);cmd_increment2();cmd(ptr);wr16(RAM_CMD+cmd_offset, format);cmd_increment2()

/**
 * stop any spinner, screensaver or sketch
 */
#define cmd_stop() cmd(CMD_STOP)

/**
 * set up a custom font
 */
#define cmd_setfont(font, ptr) cmd(CMD_SETFONT);cmd(font);cmd(ptr)

/**
 * track touches for a graphics object
 */
#define cmd_track(x, y, w, h, tag) cmd(CMD_TRACK);wr16(RAM_CMD+cmd_offset, x);cmd_increment2();wr16(RAM_CMD+cmd_offset, y);cmd_increment2();wr16(RAM_CMD+cmd_offset, w);cmd_increment2();wr16(RAM_CMD+cmd_offset, h);cmd_increment2();wr16(RAM_CMD+cmd_offset, tag);cmd_increment2()

/**
 * take a snapshot of the current screen
 */
#define cmd_snapshot(ptr) cmd(CMD_SNAPSHOT);cmd(ptr)

/**
 * play device logo animation
 */
#define cmd_logo() cmd(CMD_LOGO)

/**
 * send host command to FT800. Refer FT800 data sheet for more information.
 * @param command
 */
void host_command(ft_uint8_t command);

/**
 * write 8 bits to intended address location
 */
void wr8(unsigned short long addr, ft_uint8_t value);

/**
 * write 16 bits to intended address location
 */
void wr16(unsigned short long addr, ft_uint16_t value);

/**
 * write 32 bits to intended address location
 */
void wr32(unsigned short long addr, ft_uint32_t value);

/**
 * read 8 bits from intended address location
 */
ft_uint8_t rd8(unsigned short long addr);

/**
 * read 16 bits from intended address location
 */
ft_uint16_t rd16(unsigned short long addr);

/**
 * read 32 bits from intended address location
 */
ft_uint32_t rd32(unsigned short long addr);

/**
 * write 8 bits string to intended address location
 */
ft_uint8_t wr8s(unsigned short long addr, const ft_char8_t *s);

/**
 * read 8 bits string from intended address location
 */
//ft_char8_t * rd8s(unsigned short long addr, ft_uint8_t len);

/**
 * Initializes the FT800
 */
inline void FT800_Init();


#endif	/* FT800_H */

