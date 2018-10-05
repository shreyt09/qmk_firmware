/* Copyright 2018 MechMerlin
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  KC_GDB_NEXT = SAFE_RANGE,    /* "n" + enter */
  KC_GDB_STEP_IN,              /* "s" + enter */
  KC_GDB_STEP_OUT,             /* "fin" + enter */
  KC_GDB_BT,                   /* "bt" + enter */
  KC_GDB_PRINT_ARR,            /* "set print array on" + enter */
  KC_GDB_PRINT_PRETTY,         /* "set print pretty on" + enter */
  KC_GDB_LOCALS,               /* "info locals" + enter */
  KC_GDB_ARGS                 /* "info args" + enter */
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* GDB Debugging */
    KC_GDB_NEXT,       KC_GDB_STEP_IN,      KC_GDB_STEP_OUT, \
    KC_GDB_LOCALS,     KC_GDB_ARGS,         KC_GDB_BT, \
    KC_GDB_PRINT_ARR,  KC_GDB_PRINT_PRETTY, KC_ENTER   \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case KC_GDB_NEXT:
      if (record->event.pressed)
      {
        SEND_STRING("n" SS_TAP(X_ENTER));
      }
      break;
    
    case KC_GDB_STEP_IN:
      if (record->event.pressed)
      {
        SEND_STRING("s" SS_TAP(X_ENTER));
      }
      break;

    case KC_GDB_STEP_OUT:
      if (record->event.pressed)
      {
        SEND_STRING("fin" SS_TAP(X_ENTER));
      }
      break;             

    case KC_GDB_BT:
      if (record->event.pressed)
      {
        SEND_STRING("bt" SS_TAP(X_ENTER));
      }
      break;

    case KC_GDB_PRINT_ARR:
      if (record->event.pressed)
      {
        SEND_STRING("set print array on" SS_TAP(X_ENTER));
      }  
      break;
    
    case KC_GDB_PRINT_PRETTY:
      if (record->event.pressed)
      {
        SEND_STRING("set print pretty on" SS_TAP(X_ENTER));
      }
      break;

    case KC_GDB_LOCALS:
      if (record->event.pressed)
      {
        SEND_STRING("info locals" SS_TAP(X_ENTER));
      }
      break;

    case KC_GDB_ARGS:
      if (record->event.pressed)
      {
        SEND_STRING("info args" SS_TAP(X_ENTER));
      }
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
