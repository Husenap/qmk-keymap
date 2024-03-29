#include QMK_KEYBOARD_H
#include "definitions/keycodes.h"

bool process_macros(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
    case DIRUP:
      SEND_STRING("../");
      return false;
    case MY_GRV:
      SEND_STRING("`");
      return false;
    case MY_TILD:
      SEND_STRING("~");
      return false;
    case MY_CIRC:
      SEND_STRING("^");
      return false;
    }
  }
  return true;
}