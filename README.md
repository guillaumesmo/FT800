FT800 C Library
=====

C Library for the FTDI FT800 GPU

[![Donate](https://www.paypalobjects.com/en_US/i/btn/btn_donate_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=29U7QJZ99LJ46)

### Goals of the library

- Works with 8-bit MCU's (as advertized by FTDI)
- Lightweight
- Easy to use

### Requirements

#### Hardware

- An 8-bit Microchip PIC with SPI support
- A compatible display (HX8257A/ConnectEVE/...)

#### Software

- Microchip XC8 compiler (version 1.21)
- (Optional) Microchip MPLAB X IDE

### How to use

1. Download/clone the library
2. Update config.h to match your MCU's values
3. Create (or update) main.c in order to initialize the MCU (SPI, GPIO's, clock, ...)
4. Read the [FT800 Programmers Guide](http://www.ftdichip.com/Support/Documents/ProgramGuides/FT800%20Programmers%20Guide.pdf) and copy examples you like
5. Compile and program your PIC
6. Enjoy!

### Further development

This repo is open for pull requests, please contribute to this project! You can also donate to pay the coffee and boost development ;)

#### Roadmap

- ~~SPI Communication abstraction~~
- ~~Memory read and write~~
- ~~Convenience functions for writing display lists~~
- ~~Convenience functions/macros for sending co-processor commands~~
- Optimization (lower the flash memory usage per command)
- Add examples
- Add support for other MCU's
- Add support for other displays
- Additional support for touch and sound
- Allow conversion of cmd_* macro's to functions with a define
