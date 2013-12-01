/* 
 * File:   FT_Functions.h
 * Author: Guillaume Smolders
 *
 * Created on 25 novembre 2013, 0:25
 */

#ifndef FT800_H
#define	FT800_H

#include "config.h"
#include "FT_DataTypes.h"
#include "FT_Gpu.h"

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

