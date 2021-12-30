/* Copyright 2020 tominabox1
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

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_planck_mit(
    KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_TAB,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_A,  KC_S,    KC_D,    KC_F,    KC_G,    KC_LALT,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
    KC_ESC, TG(_NUMPAD), KC_LSFT, LOWER, KC_SPC,   KC_ENT,  RAISE,  KC_LCTL ,   KC_INS,  KC_PSCR,   KC_PAUS
),

[_LOWER] = LAYOUT_planck_mit(
    LCTL(KC_Q)   , KC_MS_UP, KC_MS_BTN4,    KC_MS_BTN5,LCTL(KC_T), _______,   KC_APP, KC_F7, KC_F8, KC_F9, KC_F10, KC_ESC,
    KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,    KC_MS_BTN1, KC_MS_BTN2,_______,   KC_PGUP, KC_F4, KC_F5, KC_F6, KC_F11, KC_F14,
    LCTL(KC_Z), LCTL(KC_X),  LCTL(KC_C),    LCTL(KC_V), LCTL(KC_B),_______,   KC_PGDN, KC_F1, KC_F2, KC_F3, KC_F12, KC_F13,
    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______
),

[_RAISE] = LAYOUT_planck_mit(
      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  _______,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC,
      KC_F20,   KC_F21,   KC_F22,  KC_F23,   KC_F24,_______,   KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_MINS,  KC_EQL,
      KC_F15,   KC_F16,   KC_F17,  KC_F18,   KC_F19,_______,   KC_BSPC,  KC_DEL, KC_HOME,  KC_END,  KC_GRV, KC_RSFT,
    _______, _______, _______, _______, KC_TAB, _______, _______, _______, _______, _______, _______
),


[_ADJUST] = LAYOUT_planck_mit(
      RESET,   DEBUG, RGB_TOG, RGB_MOD, RGB_HUI, _______, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),


[_NUMPAD] = LAYOUT_planck_mit(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_BSPC, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_PPLS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, KC_PDOT,
    _______, _______, _______, _______, _______, _______, _______, _______,  KC_COMM, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

