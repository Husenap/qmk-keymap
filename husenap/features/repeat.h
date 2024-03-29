#pragma once

#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "definitions/keycodes.h"

bool process_repeat(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case TMB_RPT:
    if (record->event.pressed && record->tap.count > 0) {
      keyrecord_t press;
      press.event.type    = KEY_EVENT;
      press.tap.count     = 1;
      press.event.pressed = true;
      process_repeat_key(QK_REP, &press);
      keyrecord_t release;
      release.event.type    = KEY_EVENT;
      release.tap.count     = 1;
      release.event.pressed = false;
      process_repeat_key(QK_REP, &release);
      return true;
    }
  }
  return false;
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t *record, uint8_t *remembered_mods) {
  switch (keycode) {
  case KC_BSPC:
  case KC_DEL:
  case TMB_RPT:
    return false;
  }
  return true;
}