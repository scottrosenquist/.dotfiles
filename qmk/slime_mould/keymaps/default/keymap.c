/* Copyright 2020 Scott Rosenquist
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
 _COLEMAK,
 _LSHIFT,
 _RSHIFT,
 _NUMBER,
 _SYMBOL,
 _BRACKT,
 _NAV
};

#define KC_ALTA LALT_T(KC_A)
#define KC_GUIR LGUI_T(KC_R)
#define KC_GUIN LGUI_T(KC_N)
#define KC_CTLS LCTL_T(KC_S)
#define KC_SFTT LT(_RSHIFT, KC_T)
#define KC_SFTN LT(_LSHIFT, KC_N)
#define KC_SHFT MO(_LSHIFT)
#define KC_CTLE RCTL_T(KC_E)
#define KC_GUII RGUI_T(KC_I)
#define KC_ALTO RALT_T(KC_O)

#define SBRCKT LT(_BRACKT, KC_SPC)
#define ESYMBL LT(_SYMBOL, KC_ENT)
#define CNUMBE LT(_NUMBER, KC_SCLN)
#define SNAVIG LT(_NAV, KC_SLSH)

#define S_ENT S(KC_ENT)
#define S_ESC S(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
  [_COLEMAK] = LAYOUT( \
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_Z,    KC_F,    KC_R,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_Q,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_ALTA, KC_GUIN, KC_CTLS, KC_SFTT,    KC_G,                         KC_M, KC_SHFT, KC_CTLE, KC_GUII, KC_ALTO,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_V,    KC_X,    KC_C,    KC_D,    KC_W,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_ESC,  SBRCKT,  CNUMBE,    SNAVIG,  ESYMBL, KC_BSPC \
  ),

  [_RSHIFT] = LAYOUT( \
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      S(KC_J), S(KC_L), S(KC_U), S(KC_Y), S(KC_Q),\
  //|--------+--------+--------+--------+--------/                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      S(KC_M), XXXXXXX, S(KC_E), S(KC_I), S(KC_O),\
  //|--------+--------+--------+--------+--------/                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      S(KC_K), S(KC_H),  KC_GRV, KC_EXLM, KC_DQUO,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    KC_QUES,   S_ENT,  KC_DEL \
  ),

  [_LSHIFT] = LAYOUT( \
  //,--------------------------------------------.                    ,--------------------------------------------.
      S(KC_Z), S(KC_F), S(KC_R), S(KC_P), S(KC_B),                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      S(KC_A), S(KC_N), S(KC_S), S(KC_T), S(KC_G),                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      S(KC_V), S(KC_X), S(KC_C), S(KC_D), S(KC_W),                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  S_ESC,  KC_TAB, KC_COLN,     XXXXXXX, XXXXXXX, XXXXXXX \
  ),

  [_NUMBER] = LAYOUT( \
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_0, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_BRACKT] = LAYOUT( \
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LPRN, KC_RPRN, KC_AMPR, XXXXXXX,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_LT,   KC_GT, KC_BSLS, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC, KC_RBRC, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOL] = LAYOUT( \
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, KC_HASH, KC_CIRC,  KC_DLR, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, KC_ASTR, KC_MINS, KC_PLUS, XXXXXXX,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RGUI, KC_RALT,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, KC_TILD,  KC_EQL, KC_UNDS, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX,   KC_AT, KC_PERC,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT( \
  //,--------------------------------------------.                    ,--------------------------------------------.
        RESET, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RGUI, KC_RALT,\
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  )
};

