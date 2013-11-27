/* 
 * File:   config.h
 * Author: Guillaume Smolders
 *
 * Created on 25 novembre 2013, 0:40
 */

#ifndef CONFIG_H
#define	CONFIG_H

// set your clock frequency here (used for delays)
#define _XTAL_FREQ 48000000

// set your CS and PD pins here
#define PIN_CS TRISCbits.TRISC3
#define PIN_PD TRISCbits.TRISC5

#endif	/* CONFIG_H */

