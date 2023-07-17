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

#include <locale.h>
#include <stdint.h>

#include "config.h"
#include "keycodes.h"
#include "util.h"
#include QMK_KEYBOARD_H

#include "features/achordion.h"
#include "moonlander.h"
#include "rgb_matrix.h"
#include "sendstring_swedish.h"
#include "version.h"

enum layers {
  DEF,  // default layer
  OPS,  // operators
  SYM,  // symbols
  MED,  // media keys
  NAV,  // navigation
  NUM,  // numpad
  FUN,  // function keys
  GAME, // gaming
};

enum custom_keycodes {
  VRSN = SAFE_RANGE, // Keyboard, Keymap, Version
  DIRUP,             // Directory up, ../
};

// Home row mods
#define HRM_A LGUI_T(KC_A)
#define HRM_R LALT_T(KC_R)
#define HRM_S LT(NUM, KC_S)
#define HRM_T LSFT_T(KC_T)

#define HRM_N RSFT_T(KC_N)
#define HRM_E LT(OPS, KC_E)
#define HRM_I RALT_T(KC_I)
#define HRM_O RGUI_T(KC_O)

// Thumb cluster
#define TMB_SPC LT(NAV, KC_SPC)
#define TMB_TAB LCTL_T(KC_TAB)
#define TMB_ENT RCTL_T(KC_ENT)
#define TMB_RPT LT(SYM, QK_REP)

// Layer Changes
#define TO_GAME TG(GAME)
#define TO_MED MO(MED)
#define TO_NUM MO(NUM)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    *  q w f p b   j l u y å 
    *  a r s t g   m n e i o ö
    *  z x c d v   k h , . ä
    */
    [DEF] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_DEL,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     _______,      _______,  KC_J,     KC_L,     KC_U,     KC_Y,     SE_ARNG,  _______,
        KC_BSPC,  HRM_A,    HRM_R,    HRM_S,    HRM_T,    KC_G,     _______,      _______,  KC_M,     HRM_N,    HRM_E,    HRM_I,    HRM_O,    SE_ODIA,
        _______,  KC_Z,     KC_X, LT(FUN,KC_C), KC_D,     KC_V,                             KC_K,     KC_H,     KC_COMM,  KC_DOT,   SE_ADIA,  _______,
        TO_GAME,  _______,  _______,  _______,  _______,            _______,      _______,            _______,  _______,  TO_MED,   _______,  TO_NUM,
                                                TMB_SPC,  TMB_TAB,  _______,      _______,  TMB_ENT,  TMB_RPT
    ),

    /*
    *  ` $ { } %
    *  # _ ( ) 
    *  ~ @ [ ] ../
    */
    [SYM] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  SE_GRV,   SE_DLR,   SE_LCBR,  SE_RCBR,  SE_PERC,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  SE_HASH,  SE_UNDS,  SE_LPRN,  SE_RPRN,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  SE_TILD,  SE_AT,    SE_LBRC,  SE_RBRC,  DIRUP,                            _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,      _______,            _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,  _______,      _______,  _______,  _______
    ),
    
    /*
    *  ' < > " ^
    *  ! - + = &
    *  ? / * \ |
    */
    [OPS] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  SE_QUOT,  SE_LABK,  SE_RABK,  SE_DQUO,  SE_CIRC,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_EXLM,  SE_MINS,  SE_PLUS,  SE_EQL,   SE_AMPR,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  SE_QUES,  SE_SLSH,  SE_ASTR,  SE_BSLS,  SE_PIPE,                          _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,      _______,            _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,  _______,      _______,  _______,  _______
    ),

    [MED] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  QK_BOOT,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  RGB_HUI,  RGB_SAI,  RGB_VAI,  KC_MUTE,  KC_VOLD,  KC_VOLU,
        _______,  _______,  _______,  _______,  _______,  _______,                          RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_MPRV,  KC_MPLY,  KC_MNXT,
        _______,  _______,  _______,  _______,  _______,            _______,      RGB_TOG,            _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,  _______,      RGB_SPD,  RGB_SPI,  RGB_MOD
     ),

    [NAV] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  KC_MS_U,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,      _______,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, _______,
        _______,  KC_BTN2,  _______,  _______,  _______,  _______,                          _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,      _______,            _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,  _______,      _______,  _______,  _______
    ),

    [NUM] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  KC_7,     KC_8,     KC_9,     _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  KC_1,     KC_2,     KC_3,     KC_DOT,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,                          _______,  KC_4,     KC_5,     KC_6,     _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,      _______,            _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,  _______,      _______,  _______,  KC_0
    ),

    [FUN] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,                          _______,  KC_F5,    KC_F6,    KC_F7,    KC_F8,    _______,
        _______,  _______,  _______,  _______,  _______,            _______,      _______,            _______,  _______,  _______,  _______,  _______,
                                                _______,  _______,  _______,      _______,  _______,  _______
    ),

    [GAME] = LAYOUT(
        KC_ESC,   KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_1,     KC_3,     KC_Q,     KC_W,     KC_E,     KC_R,     _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        KC_2,     KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_G,     _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
        SE_LABK,  KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_B,                             _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  KC_V,               KC_M,         _______,            _______,  _______,  _______,  _______,  _______,
                                                KC_SPC,   KC_TAB,   _______,      _______,  _______,  _______
    ),

    // [] = LAYOUT(
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,  _______,                          _______,  _______,  _______,  _______,  _______,  _______,
    //     _______,  _______,  _______,  _______,  _______,            _______,      _______,            _______,  _______,  _______,  _______,  _______,
    //                                             _______,  _______,  _______,      _______,  _______,  _______
    // ),
};
// clang-format on

#include "g/keymap_combo.h"

// clang-format off
#define C_PRMRY         {0, 255, 255}
#define C_SNDRY       {32, 255, 255}
#define C_ACCNT          {127, 255, 255}
#define C_BLACK           {0,0,0}

const HSV PROGMEM ledmap[][RGB_MATRIX_LED_COUNT] = {
    [DEF] = LED_LAYOUT(
              C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,        C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  
              C_SNDRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_BLACK,        C_BLACK,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_BLACK,  
              C_SNDRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_BLACK,        C_BLACK,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  
              C_BLACK,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,                            C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_BLACK,  
              C_ACCNT,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,            C_BLACK,        C_BLACK,            C_BLACK,  C_BLACK,  C_ACCNT,  C_BLACK,  C_ACCNT,  
                                                      C_SNDRY,  C_SNDRY,  C_BLACK,        C_BLACK,  C_SNDRY,  C_SNDRY
    ),

    [MED] = LED_LAYOUT(
              C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,        C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_ACCNT,  
              C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,        C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  
              C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,        C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_SNDRY,  C_PRMRY,  C_SNDRY,  
              C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,                            C_BLACK,  C_BLACK,  C_BLACK,  C_SNDRY,  C_PRMRY,  C_SNDRY,  
              C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,            C_BLACK,        C_BLACK,            C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  
                                                      C_BLACK,  C_BLACK,  C_BLACK,        C_BLACK,  C_BLACK,  C_BLACK
    ),

    // [] = LED_LAYOUT(
    //           C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,        C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  
    //           C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,        C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  
    //           C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,        C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  
    //           C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,                            C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  
    //           C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,            C_BLACK,        C_BLACK,            C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  
    //                                                   C_BLACK,  C_BLACK,  C_BLACK,        C_BLACK,  C_BLACK,  C_BLACK
    // ),
};
// clang-format on

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = ledmap[layer][i];
    if (!hsv.h && !hsv.s && !hsv.v) {
      rgb_matrix_set_color(i, 0, 0, 0);
    } else {
      hsv.h += rgb_matrix_config.hsv.h;
      hsv.s *= (float)rgb_matrix_config.hsv.s / UINT8_MAX;
      hsv.v *= (float)rgb_matrix_config.hsv.v / UINT8_MAX;
      RGB rgb = hsv_to_rgb(hsv);
      rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  switch (get_highest_layer(layer_state)) {
  case DEF:
  case MED:
    set_layer_color(get_highest_layer(layer_state));
    break;
  default:
    return false;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = get_highest_layer(state);

  ML_LED_1((layer & 0x01));
  ML_LED_2((layer & 0x02));
  ML_LED_3((layer & 0x04));
  ML_LED_4((layer & 0x08));
  ML_LED_5((layer & 0x10));
  ML_LED_6((layer & 0x20));

  return state;
}

// Macros
bool process_macros(uint16_t keycode, keyrecord_t *record) {
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) return false;

  if (keycode == TMB_RPT && !record->tap.count) return true;

  if (!process_macros(keycode, record)) return false;

  return true;
}

// Achordion
void matrix_scan_user(void) {
  achordion_task();
}
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                     uint16_t other_keycode, keyrecord_t *other_record) {
  switch (tap_hold_keycode) {
  // Allow same hand shortcuts with thumbs
  case TMB_TAB:
  case TMB_ENT:
  case TO_MED:
  case TO_NUM:
    return true;

  // Allow alt + tab
  case HRM_R:
    if (other_keycode == TMB_TAB) return true;
  }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 500;
}