/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
    QKUNWRAP = SAFE_RANGE,
    QKEXPECT,
    QKCLONE,
    QKSTRUCT,
    QKENUM,
    QKTYPE,
    QKTRUE,
    QKFALSE,
    QKNONE,
    QKSOME,
    QKRESULT,
    QKRETURN,
    QKTRAIT,
    QKIMPL,
    // DERIVE,
    // CRATE,
    // WHERE,
    // CONST,
    // FORMAT,
    // USIZE,
    // MOVE,
    // ASYNC,
    // AWAIT,
    // LOOP,
    // ITER,
    // MATCH,
    // SUPER,
    // TEST,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case QKUNWRAP:
        if (record->event.pressed) {
            SEND_STRING(".unwrap()");
        }
        break;
      case QKEXPECT:
        if (record->event.pressed) {
            SEND_STRING(".expect(");
        }
        break;
      case QKCLONE:
        if (record->event.pressed) {
            SEND_STRING(".clone()");
        }
        break;
      case QKSTRUCT:
        if (record->event.pressed) {
            SEND_STRING("struct ");
        }
        break;
      case QKENUM:
        if (record->event.pressed) {
            SEND_STRING("enum ");
        }
        break;
      case QKTYPE:
        if (record->event.pressed) {
            SEND_STRING("type ");
        }
        break;
      case QKTRUE:
        if (record->event.pressed) {
            SEND_STRING("true");
        }
        break;
      case QKFALSE:
        if (record->event.pressed) {
            SEND_STRING("false");
        }
        break;
      case QKSOME:
        if (record->event.pressed) {
            SEND_STRING("Some(");
        }
        break;
      case QKNONE:
        if (record->event.pressed) {
            SEND_STRING("None");
        }
        break;
      case QKRESULT:
        if (record->event.pressed) {
            SEND_STRING("Result<");
        }
        break;
      case QKRETURN:
        if (record->event.pressed) {
            SEND_STRING("return ");
        }
        break;
      case QKTRAIT:
        if (record->event.pressed) {
            SEND_STRING("trait ");
        }
        break;
      case QKIMPL:
        if (record->event.pressed) {
            SEND_STRING("impl");
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_J,    KC_C,    KC_Y,    KC_F,    KC_K,                         KC_Z,    KC_L, KC_COMM,    KC_U,   KC_Q,  KC_PEQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_R,    KC_S,    KC_T,    KC_H,    KC_D,                         KC_M,    KC_N,    KC_A,    KC_I,    KC_O, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
KC_LGUI,LCTL_T(KC_PSLS),   KC_V,    KC_G,    KC_P,    KC_B,                         KC_X,    KC_W, KC_DOT,  KC_SCLN, KC_UNDS,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,LT(3,KC_E), KC_BSPC,   LT(1,KC_ENT),LT(2,KC_SPC), KC_NO
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_EXLM, KC_DQUO,  KC_DLR, KC_LCBR, KC_RCBR,                        KC_AT,    KC_7,    KC_8,    KC_9, KC_PMNS,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CIRC, KC_QUOT, KC_PIPE, KC_AMPR, KC_LPRN, KC_RPRN,                      KC_PAST,    KC_4,    KC_5,    KC_6, KC_PPLS,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_PERC, KC_QUES, KC_TILD, KC_LBRC, KC_RBRC,                         KC_0,    KC_1,    KC_2,    KC_3,   KC_NO,    KC_0,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO, KC_HASH,  KC_ESC,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,  KC_GRV, KC_BTN2, KC_MS_U, KC_BTN1, KC_BTN3,                        KC_NO,   KC_NO,   KC_UP,   KC_NO,  KC_F12,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO, KC_MS_L, KC_MS_D, KC_MS_R,   KC_NO,                        KC_NO, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_F11,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),


    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     QKSTRUCT,  QKENUM,  QKTYPE,  QKTRUE,  QKFALSE,QKRESULT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                    QKUNWRAP, QKEXPECT, QKCLONE,  QKSOME,  QKNONE,QKRETURN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      QKTRAIT,  QKIMPL,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO
                                      //`--------------------------'  `--------------------------'
  ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
