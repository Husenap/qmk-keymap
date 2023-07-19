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

#include "config.h"
#include "keymap_swedish.h"
#include "process_caps_word.h"
#include "util.h"
#include QMK_KEYBOARD_H

#include "definitions/layout.h"
#include "definitions/ledmap.h"
#include "features/achordion.h"
#include "features/macros.h"
#include "features/moonlander_leds.h"
#include "features/repeat.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) return false;
  if (process_repeat(keycode, record)) return true;
  if (!process_macros(keycode, record)) return false;

  return true;
}

// CAPS WORD
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
  // Keycodes that continue Caps Word, with shift applied.
  case KC_A ... KC_Z:
  case SE_ARNG:
  case SE_ODIA:
  case SE_ADIA:
  case SE_MINS:
  case KC_MINS:
    add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
    return true;

  // Keycodes that continue Caps Word, without shifting.
  case KC_1 ... KC_0:
  case KC_BSPC:
  case KC_DEL:
  case KC_UNDS:
  case SE_UNDS:
    return true;

  default:
    return false; // Deactivate Caps Word.
  }
}

// Achordion
void matrix_scan_user(void) { achordion_task(); }
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

uint16_t achordion_timeout(uint16_t tap_hold_keycode) { return 500; }