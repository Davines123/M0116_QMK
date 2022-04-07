#include QMK_KEYBOARD_H

enum {
    SUPER_F4,
    GUI_FILE,
    ABOVE_SUS,
    MUTE_PAUSE,
    PRINT_DEL,
    ALT_TAP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT(
				TD(ABOVE_SUS),
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_EQL,KC_7, KC_8, KC_9, KC_0, KC_MINS,  KC_BSPC, 				KC_NLCK, KC_EQL, KC_PSLS, KC_PAST, 
		KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_LBRC, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_QUOT, KC_ENT, 			KC_P7, KC_P8, KC_P9, KC_PPLS, 
		KC_LCTRL, KC_A, KC_R, KC_S, KC_T, KC_D, KC_RBRC, KC_H, KC_N, KC_E, KC_I, KC_O, 						KC_P4,  KC_P5, KC_P6, KC_PMNS, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SLSH,KC_K, KC_M, KC_COMM, KC_DOT,  KC_RSFT, 					KC_P1, KC_P2, KC_P3, 
		KC_LCAP, TD(GUI_FILE), TD(ALT_TAP), MO(1), KC_SPC, KC_BSLS, G(C(KC_LEFT)), G(C(KC_F4)), G(C(KC_D)), G(C(KC_RGHT)), 		KC_P0, KC_PDOT, KC_ENT
		),

	[1] = LAYOUT(
				RESET,
		KC_GRV, KC_F1, KC_F2, KC_F3, TD(SUPER_F4), KC_F5, KC_F6, KC_F12, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_DEL, 			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NK_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, C(KC_X), C(KC_C), C(KC_V), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 			KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS, AU_TOG, CK_DOWN, CK_UP, CK_TOGG, 	 						 KC_TRNS, KC_TRNS, KC_TRNS
		)
};

//NumpadNumlock Mods
led_t led_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case KC_P5:
    led_state = host_keyboard_led_state();
    if (!record->event.pressed) {
      if (led_state.num_lock) {
        return true;
      } else {
        tap_code(KC_PSCR);
        return false;
      }
    }
    break;
     }
  return true;
}
    
// SUPER_F4 TAP DANCE
void dance_sf4_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_F4);
    } else {
        register_code(KC_LALT);
        register_code(KC_F4);
    }
}

void dance_sf4_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_F4);
    } else {
        unregister_code(KC_LALT);
        unregister_code(KC_F4);
    }
}

// GUI_FILE TAP DANCE
void dance_gfile_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_LGUI);
    } else {
        register_code(KC_LGUI);
        register_code(KC_E);
    }
}

void dance_gfile_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_LGUI);
    } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_E);
    }
}

// ABOVE_SUS TAP DANCE
void dance_asus_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LGUI);
        register_code(KC_D);
    } else {
        register_code(KC_LGUI);
        register_code(KC_L);
    }
}

void dance_asus_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_LGUI);
        unregister_code16(KC_D);
    } else {
        unregister_code16(KC_LGUI);
        unregister_code16(KC_L);
    }
}

// MUTE_PAUSE TAP DANCE
void dance_mutepause_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_MPLY);
    } else {
        register_code(KC_MUTE);
    }
}

void dance_mutepause_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_MPLY);
    } else {
        unregister_code(KC_MUTE);
    }
}

// PRINT_DEL TAP DANCE
void dance_printdel_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_PSCR);
    } else {
        register_code(KC_DEL);
    }
}
void dance_printdel_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_PSCR);
    } else {
        unregister_code(KC_DEL);
    }
}

// ALT_TAP TAP DANCE
void dance_altab_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_LALT);
    } else {
        register_code(KC_LALT);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
    }
}
void dance_altab_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_LALT);
    } else {
        unregister_code16(KC_LALT);
    }
    clear_mods();
}



// All tap dance functions go here.
qk_tap_dance_action_t tap_dance_actions[] = {
    [SUPER_F4] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_sf4_finished, dance_sf4_reset, 250),
    [GUI_FILE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_gfile_finished, dance_gfile_reset, 200),
    [ABOVE_SUS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_asus_finished, dance_asus_reset, 200),
    [MUTE_PAUSE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_mutepause_finished, dance_mutepause_reset, 200),
    [PRINT_DEL] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_printdel_finished, dance_printdel_reset, 200),
    [ALT_TAP] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_altab_finished, dance_altab_reset, 200),
    
};
