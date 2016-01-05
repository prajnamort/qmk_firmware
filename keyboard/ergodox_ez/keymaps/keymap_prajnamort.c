#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define CODER 1 // coder layer
#define MEDIA 2 // media layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | LCTL+V |   1  |   2  |   3  |   4  |   5  |LCTL+C|           |  L2  |   6  |   7  |   8  |   9  |   0  |   DEL  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |    _   |   ,  |   .  |   P  |   Y  |   (  | Hyper|           | Hyper|   )  |   B  |   C  |   L  |   G  |   +    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LCTL  |   A  |   O  |   E  |   I  |   U  |------|           |------|   H  |   R  |   T  |   N  |   S  |   -    |
 * |--------+------+------+------+------+------|  CAG |           |  CAG |------+------+------+------+------+--------|
 * |  LSFT  |   Z  |   Q  |   X  |   K  |   J  |      |           |      |   F  |   D  |   M  |   W  |   V  |  RSFT  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCTL | LALT |;/LGUI|   /  |  ~L1 |                                       |  ~L1 |   =  |\/LGUI| RALT | RCTL |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Esc  | PScr |       |      |  L2  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|  Tab |------|       |------| Back   |Enter |
 *                                 |      |      | End  |       | PgDn | space  |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        LCTL(KC_V), KC_1,     KC_2,            KC_3,     KC_4,     KC_5,      LCTL(KC_C),
        KC_UNDS,    KC_COMM,  KC_DOT,          KC_P,     KC_Y,     KC_LPRN,   KC_HYPR,
        KC_LCTL,    KC_A,     KC_O,            KC_E,     KC_I,     KC_U,
        KC_LSFT,    KC_Z,     KC_Q,            KC_X,     KC_K,     KC_J,      KC_CAG,
        KC_LCTL,    KC_LALT,  GUI_T(KC_SCLN),  KC_SLSH,  MO(CODER),
                                                                  KC_ESC,    KC_PSCR,
                                                                             KC_HOME,
                                                        KC_SPC,   KC_TAB,    KC_END,
        // right hand
        TG(MEDIA),  KC_6,     KC_7,       KC_8,    KC_9,     KC_0,     KC_DELT,
        KC_HYPR,  KC_RPRN,  KC_B,       KC_C,    KC_L,     KC_G,     KC_PLUS,
                    KC_H,     KC_R,       KC_T,    KC_N,     KC_S,     KC_MINS,
        KC_CAG,     KC_F,     KC_D,       KC_M,    KC_W,     KC_V,     KC_RSFT,
                              MO(CODER),  KC_EQL,  GUI_T(KC_BSLS), KC_RALT,  KC_RCTL,
        KC_NO,      TG(MEDIA),
        KC_PGUP,
        KC_PGDN,    KC_BSPC,   KC_ENT
),
/* Keymap 1: Coder layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   {  |   |  |   }  |      |      |           |      |      |   <  |   !  |   >  |      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   $  |   [  |   #  |   ]  |   `  |------|           |------|   ~  |   '  |  UP  |   "  |   ?  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   :  |   *  |   %  |      |      |           |      |      | LEFT | DOWN | RGHT |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[CODER] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LCBR, KC_PIPE, KC_RCBR, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_DLR,  KC_LBRC, KC_HASH, KC_RBRC, KC_GRV,
       KC_TRNS, KC_TRNS, KC_COLN, KC_ASTR, KC_PERC, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_TRNS, KC_LTHN, KC_EXLM, KC_GTHN, KC_TRNS, KC_F12,
                KC_TILD, KC_QUOT, KC_UP,   KC_DQUT, KC_QSMK, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | VolD | Mute | VolU |      |      |           |      |      | WhUp |MsBtn3|WhDown|      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | MPrv |  Up  | MNxt |      |------|           |------|      |MsBtn1| MsUp |MsBtn2|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Rght |      |      |           |      |      |MsLeft|MsDown|MsRght|      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | MPly |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_TRNS, KC_VOLD, KC_MUTE, KC_VOLU, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MPRV, KC_UP,   KC_MNXT, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_MPLY, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_TRNS, KC_WH_U, KC_BTN3, KC_WH_D,   KC_TRNS, KC_F12,
                KC_TRNS, KC_BTN1, KC_MS_U, KC_BTN2,   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R,   KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    // [1] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_BSLS)    // TapKey: \/RGUI
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void * matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void * matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case CODER:
            ergodox_right_led_1_on();
            break;
        case MEDIA:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
