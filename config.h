#ifndef CONFIG_H
#define CONFIG_H

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

// Screen Configuration
#define SCREEN_ROTATION 1 // Screen orientation: 1 or 3 (1 = landscape, 3 = landscape flipped)
#define SCREEN_SWAP_BYTES true // Set to false if colors appear wrong
//#define TFT_PARALLEL // Uncomment this line if using parallel communication instead of SPI communication

// Touch Screen

#define XPT2046_IRQ 36   // T_IRQ
#define XPT2046_MOSI 32  // T_DIN
#define XPT2046_MISO 39  // T_OUT
#define XPT2046_CLK 25   // T_CLK
#define XPT2046_CS 33    // T_CS

// Sound sample rate
#define SAMPLE_RATE 44100

#define FRAMESKIP
#define DEBUG // Uncomment this line if you want debug prints from serial

#endif