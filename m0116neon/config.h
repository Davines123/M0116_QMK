#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x5559
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    neon
#define PRODUCT         m0116neon

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 18

/* key matrix pins */
#define MATRIX_ROW_PINS { F0, F1, D1, F4, F5 }
#define MATRIX_COL_PINS { B3, D0, B2, B1, B0, F6, F7, B6, B5, B4, D7, D6, D4, D2, D5, C7, C6, D3 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE


/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define AUDIO_PIN B7
#define AUDIO_ENABLE_TONE_MULTIPLEXING
#define AUDIO_TONE_MULTIPLEXING_RATE_DEFAULT 10
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_RANDOMNESS 0
