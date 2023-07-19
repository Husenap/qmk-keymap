#include QMK_KEYBOARD_H

#include "layers.h"

// clang-format off
#define C_PRMRY       {0, 255, 255}
#define C_SNDRY       {-50, 255, 255}
#define C_ACCNT       {127, 255, 255}
#define C_BLACK       {0,0,0}

const HSV PROGMEM ledmap[][RGB_MATRIX_LED_COUNT] = {
    [DEF] = LED_LAYOUT(
              C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,        C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,  
              C_SNDRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_BLACK,        C_BLACK,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_BLACK,  
              C_SNDRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_BLACK,        C_BLACK,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  
              C_BLACK,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,                            C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_PRMRY,  C_BLACK,  
              C_ACCNT,  C_BLACK,  C_BLACK,  C_BLACK,  C_BLACK,            C_SNDRY,        C_SNDRY,            C_BLACK,  C_BLACK,  C_ACCNT,  C_BLACK,  C_ACCNT,  
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

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = ledmap[layer][i];
    if (!hsv.h && !hsv.s && !hsv.v) {
      rgb_matrix_set_color(i, 0, 0, 0);
    } else {
      hsv.h += rgb_matrix_config.hsv.h - 16;
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