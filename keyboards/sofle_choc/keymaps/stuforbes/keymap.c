/* Copyright 2023 Brian Low
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

enum sofle_layers {
    _QWERTY,
    _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Ins  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |      |	 |	|      |      |      |       |    |       | +Lsft| +Lctl| +Lgui| +Lalt|      |      |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LALT |MO(1) | /Enter  /       \Space \  | MO(2)| Bspc | Del  | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
    KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,     KC_7,     KC_8,    KC_9,    KC_0,    KC_GRV,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_INS,
KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       MT(MOD_LSFT, KC_H),MT(MOD_LCTL,KC_J),MT(MOD_LGUI,KC_K),MT(MOD_LALT,KC_L),KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,   KC_MPLY,KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      KC_LCTL, KC_LGUI, KC_LALT, MO(1), KC_ENT,    KC_SPC, MO(2),  KC_BSPC,  KC_DEL, KC_RCTL
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | PgUp | Home |  End |   R  |   T  |                    |   ;  |   `  |   -  |   [  |   ]  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | PgDn | MsL  | MsD  | MsU  | MsR  |-------.    ,-------| Left | Down |  Up  | Right|   o  |   '  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | Shift| Caps | MsB1 | MsB2 |      |      |-------|    |-------|   =  |   \  |   ,  |   .  |   /  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LALT | LCTL |ADJUST| /Enter  /       \Space \  |ADJUST| RCTL | RALT | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
    KC_GRV,  KC_F1,    KC_F2,      KC_F3,      KC_F4,    KC_F5,   			     KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,
    KC_TAB,  KC_PGUP, KC_HOME,    KC_END,     KC_R,     KC_T,                               KC_GRV,  KC_SCLN, KC_MINS, KC_LBRC,  KC_RBRC, KC_F12,
    KC_ESC,  KC_PGDN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_O,    KC_QUOT,
    KC_LSFT, KC_CAPS, KC_MS_BTN1, KC_MS_BTN2, _______,  _______,      _______,     _______, KC_EQL,  KC_BSLS, KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT,
                       KC_LGUI,    KC_LALT,    KC_LCTL,  KC_TRNS,      KC_ENT,      KC_SPC,  KC_TRNS, KC_RCTL, KC_RALT, KC_RCTL
),
};


#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            if (index == 0) {
                if (clockwise) {
		            tap_code(KC_VOLU);
		        } else {
		            tap_code(KC_VOLD);
		        }
            } else if (index == 1) {
            	if (get_mods() & MOD_BIT(KC_LSFT)) {
			        if (index == 1) {
		                if (clockwise) {
		                    tap_code(KC_RIGHT);
		                } else {
		                    tap_code(KC_LEFT);
		                }
		            }
            	} else {
	                if (clockwise) {
			            tap_code(KC_UP);
			        } else {
			            tap_code(KC_DOWN);
			        }
			    }
            }
            break;
        case 1:
            if (index == 1) {
                if (clockwise) {
                	tap_code16(S(G(KC_Z)));
                } else {
                    tap_code16(G(KC_Z));
                }
            }
            break;
        case 2:
            if (index == 0) {
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
            }
            break;
    }
    return false;
}

#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

void write_int_ln(const char* prefix, uint8_t value) {
    oled_write_P(prefix, false);
    oled_write(get_u8_str(value, ' '), false);
}

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("Sofle_____"), false);

    /*if (get_highest_layer(layer_state) == _ADJUST) {
        uint8_t mode  = rgb_matrix_get_mode();
        HSV     hsv   = rgb_matrix_get_hsv();
        uint8_t speed = rgb_matrix_get_speed();

        if (keymap_config.swap_lctl_lgui) {
            oled_write_ln_P(PSTR("MAC\n"), false);
        } else {
            oled_write_ln_P(PSTR("WIN\n"), false);
        }

        oled_write_ln("RGB", false);
        write_int_ln(PSTR("Mo"), mode);
        write_int_ln(PSTR("H "), hsv.h);
        write_int_ln(PSTR("S "), hsv.s);
        write_int_ln(PSTR("V "), hsv.v);
        write_int_ln(PSTR("Sp"), speed);
        oled_write_P(PSTR("\n\n\n"), false);
    } else {*/
        oled_write_P(PSTR("\n\n\n\n\n\n\n\n\n\n"), false);
        led_t led_usb_state = host_keyboard_led_state();
        if (led_usb_state.caps_lock) {
            oled_write_ln_P(PSTR(" CAP "), true);
        } else {
            oled_write_ln_P(PSTR("     "), false);
        }
    /*}*/

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwrty"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        default:
            oled_write_P(PSTR("???  "), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }

    return false;
}

#endif
