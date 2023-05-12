/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna)
 * <drashna@live.com>
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

#include <math.h>

#include "keycodes.h"
#include "keymap_swedish.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

#include "moonlander.h"
#include "sendstring_swedish.h"
#include "stdint.h"
#include "version.h"

enum layers {
  DEF, // default layer
  SYM, // symbols
  MED, // media keys
  NAV, // navigation
};

enum custom_keycodes {
  VRSN = SAFE_RANGE, // Keyboard, Keymap, Version
  REPEAT,            // Repeat key
  DIRUP,             // Directory up, ../
};

#define TMB_RPT LT(NAV, REPEAT)
#define TMB_TAB KC_TAB

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    *  q d r w b   j f u p å ä
    *  a s h t g   y n e o i ö
    *  z x m c v   k l , . -
    */
    [DEF] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_Q,     KC_D,     KC_R,     KC_W,     KC_B,     _______,      _______,  KC_J,     KC_F,     KC_U,     KC_P,     SE_ARNG,  SE_ADIA,
        _______,  KC_A,     KC_S,     KC_H,     KC_T,     KC_G,     _______,      _______,  KC_Y,     KC_N,     KC_E,     KC_O,     KC_I,     SE_ODIA,
        _______,  KC_Z,     KC_X,     KC_M,     KC_C,     KC_V,                             KC_K,     KC_L,     KC_COMM,  KC_DOT,   KC_SLSH,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,      _______,            _______,  _______,  _______,  _______,  LT(MED, _______),
                                                TMB_RPT,  TMB_TAB,  _______,      _______,  KC_ENT,   KC_SPC
    ),
    
    /*
    *  ' < > "  .
    *  ! - + =  #
    *  ^ / * \ ../
    */
    [SYM] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_QUOT,  KC_LABK,  KC_RABK,  KC_DQUO,  KC_DOT,   _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_EXLM,  KC_MINS,  KC_PLUS,  KC_EQL,   KC_HASH,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_CIRC,  KC_SLSH,  KC_ASTR,  KC_BSLS,  DIRUP,                            _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,      _______,            _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,  _______,      _______,  _______,  _______
    ),
    // [SYM+10] = LAYOUT(
    //     VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,           _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    //     _______, KC_EXLM, KC_LABK, KC_RABK, KC_AT,    KC_PIPE, _______,           _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
    //     _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  _______,           _______, KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
    //     _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                             KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
    //     EE_CLR,  _______, _______, _______, _______,          RGB_VAI,           RGB_TOG,          _______, KC_DOT,  KC_0,    KC_EQL,  _______,
    //                                         RGB_HUD, RGB_VAD, RGB_HUI, TOGGLE_LAYER_COLOR,_______, _______
    // ),

    [MED] = LAYOUT(
        LED_LEVEL,_______,_______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, _______, KC_MS_U, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,           _______, _______, _______, _______, _______, _______, KC_MPLY,
        _______, _______, _______, _______, _______, _______,                             _______, _______, KC_MPRV, KC_MNXT, _______, _______,
        _______, _______, _______, KC_BTN1, KC_BTN2,         _______,            _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
                                            _______, _______, _______,           _______, _______, _______
    ),

    // [] = LAYOUT(
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,                          _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,            _______,      _______,            _______,  _______,  _______,  _______,  _______,
    //                                             _______,  _______,  _______,      _______,  _______,  _______
    // ),

    // [] = LAYOUT(
    //     _______, _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,
    //     _______, _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,
    //     _______, _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,
    //                                  _______,  _______,       _______,  _______
    // ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    case VRSN:
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      return false;
    case DIRUP:
      SEND_STRING("../");
      return false;
    }
  }
  return true;
}
