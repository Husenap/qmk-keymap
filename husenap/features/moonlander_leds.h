#include QMK_KEYBOARD_H

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