/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  XTRA,
  LOWER,
  RAISE,
};

#define _QWERTY 0
#define _XTRA 1
#define _LOWER 2
#define _RAISE 3
#define _E 4
#define _F 5
#define _G 6
#define _H 7
#define _I 8
#define _J 9
#define _K 10
#define _L 11
#define _M 12
#define _N 13

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  _QWERTY
     * -------------------------------------------------------------------------------------------------------------------------
     * |   ESC   |    1    |    2    |    3    |    4    |    5    |    6    |    7    |    8    |    9    |    0    |   DEL   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |   TAB   |    Q    |    W    |    E    |    R    |    T    |    Y    |    U    |    I    |    O    |    P    |   <-    |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  CAPS   |    A    |    S    |    D    |    F    |    G    |    H    |    J    |    K    |    L    |    ;    |    '    |
     * -------------------------------------------------------------------------------------------------------------------------
     * |ShiftTESC|    Z    |    X    |    C    |    V    |    B    |    N    |    M    |  Comma  |    .    |   UP    |RSFTTEnter|
     * -------------------------------------------------------------------------------------------------------------------------
     * |  CTRL   |   Alt   |   GUI   |   MO1   |   MO2   |   <-    |   SPC   |   TT3   |    /    |  LEFT   |  DOWN   |  RGHT   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_QWERTY] = LAYOUT_preonic_grid(
        KC_ESC,         KC_1,           KC_2,       KC_3,       KC_4,       KC_5,    KC_6,     KC_7,        KC_8,     KC_9,     KC_0,     KC_DEL,
        KC_TAB,         KC_Q,           KC_W,       KC_E,       KC_R,       KC_T,    KC_Y,     KC_U,        KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_CAPS,        KC_A,           KC_S,       KC_D,       KC_F,       KC_G,    KC_H,     KC_J,        KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        LSFT_T(KC_ESC), KC_Z,           KC_X,       KC_C,       KC_V,       KC_B,    KC_N,     KC_M,        KC_COMM,  KC_DOT,   KC_UP,    RSFT_T(KC_ENT),
        KC_LCTL,        LALT_T(OSL(4)), KC_LGUI,    TT(_XTRA),  TT(_RAISE), KC_SPC,  KC_SPC,   TT(_LOWER),  KC_SLSH,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    /*  _XTRA
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TO13   |   TO4   |   TO5   |   TO6   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  MUTE   |  VOLD   |  VOLU   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |   TO7   |   TO8   |   TO9   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  MPLY   |  MPRV   |  MNXT   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TO10   |  TO11   |  TO12   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  PGUP   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  HOME   |  PGDN   |   END   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_XTRA] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        TO(_N),   TO(_E),   TO(_F),   TO(_G),   KC_TRNS,  KC_MUTE,  KC_MPLY,  KC_TRNS,  KC_TRNS,  KC_MS_UP,  KC_TRNS,  KC_MS_WH_UP,
        KC_TRNS,  TO(_H),   TO(_I),   TO(_J),   KC_TRNS,  KC_VOLU,  KC_MNXT,  KC_TRNS,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  KC_MS_WH_DOWN,
        KC_TRNS,  TO(_K),   TO(_L),   TO(_M),   KC_TRNS,  KC_VOLD,  KC_MNXT,  KC_TRNS,  KC_MS_WH_LEFT,  KC_TRNS,  KC_PGUP,  KC_MS_WH_RIGHT,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MS_BTN1,  KC_MS_BTN2,  KC_HOME,  KC_PGDN,  KC_END
    ),

    /*  _LOWER
     * -------------------------------------------------------------------------------------------------------------------------
     * |   ESC   |   F1    |   F2    |   F3    |   F4    |  DQUO   |         |         |  EXLM   |   AT    |  HASH   |   DEL   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  BSLS   |   F5    |   F6    |   F7    |   F8    |    '    |    [    |    ]    |   DLR   |  PERC   |  CIRC   |  HOME   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |   F9    |   F10   |   F11   |   F12   |    `    |    {    |    }    |  AMPR   |  MINS   |   EQL   |   END   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |   INS   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_LOWER] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_LPRN,  KC_RPRN,  KC_DQUO,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DEL,
        KC_BSLS,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_LBRC,  KC_RBRC,  KC_QUOT,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_HOME,
        KC_TRNS,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_LCBR,   KC_RCBR,  KC_GRV,  KC_AMPR,  KC_MINS,  KC_EQL,   KC_END,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_INS
    ),

    /*  _RAISE
     * -------------------------------------------------------------------------------------------------------------------------
     * |   TO0   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |    *    |    /    |   P7    |   P8    |   P9    |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |    +    |    -    |   P4    |   P5    |   P6    |  NLCK   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |   EQL   |   P1    |   P2    |   P3    |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |    .    |   P0    |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_RAISE] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PPLS,  KC_PMNS,  KC_P4,    KC_P5,    KC_P6,    KC_NLCK,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_EQL,   KC_P1,    KC_P2,    KC_P3,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PDOT,  KC_P0,    KC_TRNS,  KC_TRNS
    ),

    /*  _E
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |CTRLCTRL |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  MUTE   |  VOLD   |  VOLU   |   TO0   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  MPLY   |  MPRV   |  MNXT   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_E] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_TRNS,  KC_F2,LALT(KC_F4),  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MUTE,  KC_VOLD,  KC_VOLU,  TO(_QWERTY),
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPLY,  KC_MPRV,  KC_MNXT,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /*  _F
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |   TO0   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_F] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     TO(_QWERTY),
        KC_ESC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT,KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_UP,    RSFT_T(KC_ENT),
        KC_LCTL,  KC_LALT,  KC_LALT,  KC_SPC,KC_SPC,KC_SPC,  KC_SPC,   TT(_LOWER),KC_SLSH,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    /*  _G
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |   TO0   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_G] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_QWERTY),
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /*  _H
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |   TO0   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_H] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_QWERTY),
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /*  _I
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |   TO0   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_I] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_QWERTY),
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /*  _J
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |   TO0   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_J] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_QWERTY),
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /*  _K
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |   TO0   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_K] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_QWERTY),
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /*  _L
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |   TO0   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_L] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_QWERTY),
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /*  _M
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |   TO0   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     */
    [_M] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_QWERTY),
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),

    /*  _N
     * -------------------------------------------------------------------------------------------------------------------------
     * |  RESET  |  DEBUG  |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |   TO0   |
     * -------------------------------------------------------------------------------------------------------------------------
     * | RGB-TOG | RGB-MOD | RGB-HUI | RGB-SAI | RGB-VAI | RGB-SPI | RGB-MP  | RGB-MR  | RGB-MSN | RGB-MX  |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |RGB-RMOD | RGB-HUD | RGB-SAD | RGB-VAD | RGB-SPD | RGB-MB  | RGB-MSW | RGB-MK  | RGB-MG  |  TRNS   |  TRNS   |
     * -------------------------------------------------------------------------------------------------------------------------
     * |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |  TRNS   |
     * ---------------------------------------4----------------------------------------------------------------------------------
     */
    [_N] = LAYOUT_preonic_grid(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PAST,  KC_PSLS,  KC_P7,    KC_P8,    KC_P9,    KC_TRNS,
        RESET,    DEBUG,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(_QWERTY),
        RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI,  RGB_M_P,  RGB_M_R,  RGB_M_SN, RGB_M_X,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD,  RGB_SPD,  RGB_M_B,  RGB_M_SW, RGB_M_K,  RGB_M_G,  KC_TRNS,  KC_TRNS,
        KC_SLEP,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    )

};


// Set a layer persistently.
void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _XTRA);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _XTRA);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _XTRA);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _XTRA);
      }
      return false;
      break;
    case XTRA:
      if (record->event.pressed) {
        layer_on(_XTRA);
      } else {
        layer_off(_XTRA);
      }
      return false;
      break;
  }
  return true;
}
