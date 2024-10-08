#pragma once

#undef QMK_ESC_OUTPUT
#undef QMK_ESC_INPUT
#undef QMK_LED
#undef QMK_SPEAKER
#undef AUDIO_VOICES
#undef AUDIO_PIN
#undef C6_AUDIO

#define WS2812_DI_PIN GP25
#define RGBLIGHT_LED_COUNT 5

#define RGBLIGHT_LIMIT_VAL 140
#define RGBLIGHT_ANIMATIONS

#define TAPPING_TERM 175
#define TAPPING_TOGGLE 2

#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#define MATRIX_ROW_PINS { GP9, GP10, GP11, GP12, GP13 }
#define MATRIX_COL_PINS { GP1, GP2, GP3, GP4, GP5, GP6, GP14, GP15, GP26, GP27, GP28, GP0 }

#define ENCODERS_PAD_A { GP7 }
#define ENCODERS_PAD_B { GP8 }
#define ENCODER_DIRECTION_FLIP

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
