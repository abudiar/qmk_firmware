#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

#define MUSIC_MASK (keycode != KC_NO)

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

#undef QMK_ESC_OUTPUT
#undef QMK_ESC_INPUT
#undef QMK_LED
#undef QMK_SPEAKER

#undef AUDIO_VOICES
#undef AUDIO_PIN

#undef BACKLIGHT_PIN

#define MATRIX_ROW_PINS { B1, F7, F6, F5, F4 }
#define MATRIX_COL_PINS { D2, D1, D0, D4, C6, D7, D3, B4, B5, B6, B2, B3 }
