#pragma once

#include QMK_KEYBOARD_H
#include "layers.h"
#include "quantum/keycodes.h"
#include "quantum/keymap_extras/sendstring_swedish.h"

enum custom_keycodes {
  VRSN = SAFE_RANGE, // Keyboard, Keymap, Version
  DIRUP,             // Directory up, ../
  MY_GRV
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