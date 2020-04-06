#include QMK_KEYBOARD_H

extern uint8_t is_master;

#ifdef OLED_DRIVER_ENABLE
#    define KEYLOGGER_LENGTH 5
static uint32_t oled_timer                       = 0;
static char     keylog_str[KEYLOGGER_LENGTH + 1] = {"\n"};
static uint16_t log_timer                        = 0;
// clang-format off
static const char PROGMEM code_to_name[0xFF] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  27,  26,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 128, ' ', ' ', ' ', ' ', ' ', ' ',  // 3x
    ' ', ' ', ' ', ' ', ' ', ' ', 'P', 'S', ' ', ' ', ' ', ' ',  16, ' ', ' ', ' ',  // 4x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 5x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ax
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ex
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '        // Fx
};

void add_keylog(uint16_t keycode);
#endif

enum layers {
 _COLEMAK,
 _LSHIFT,
 _RSHIFT,
 _NUMBER,
 _SYMBOL,
 _BRACKT,
 _NAV
};

enum layer_keycodes {
  COLEMAK = SAFE_RANGE
  //LOWER,
  //RAISE,
  //ADJUST
};

enum td_keycodes {
  RCTL_SHIFT_E,
  RSFT_N
};

typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD
} td_state_t;

static td_state_t td_state;

// function to determine the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void rctl_shift_e_finished (qk_tap_dance_state_t *state, void *user_data);
void rctl_shift_e_reset (qk_tap_dance_state_t *state, void *user_data);
void rsft_n_finished (qk_tap_dance_state_t *state, void *user_data);
void rsft_n_reset (qk_tap_dance_state_t *state, void *user_data);

#define KC_ALTA LALT_T(KC_A)
#define KC_GUIR LGUI_T(KC_R)
#define KC_CTLS LCTL_T(KC_S)
//#define KC_SFTT LSFT_T(KC_T)
#define KC_SFTT LT(_RSHIFT, KC_T)
//#define KC_SFTN RSFT_T(KC_N)
#define KC_SFTN LT(_LSHIFT, KC_N)
//#define KC_SFTN TD(RSFT_N)
#define KC_CTLE RCTL_T(KC_E)
#define KC_GUII RGUI_T(KC_I)
#define KC_ALTO RALT_T(KC_O)

//#define KC_SALA LALT_T(S(KC_A))
//#define KC_SGUR LGUI_T(S(KC_R))
//#define KC_SCTS LCTL_T(S(KC_S))
//#define KC_SCTE RCTL_T(S(KC_E))
//#define KC_SCTE TD(RCTL_SHIFT_E)
//#define KC_SGUI RGUI_T(S(KC_I))
//#define KC_SALO RALT_T(S(KC_O))

//#define LOWER MO(_LOWER)
//#define RAISE MO(_RAISE)
//#define NUMBER MO(_NUMBER)

//#define SLOWER LT(_LOWER, KC_SPC)
#define SBRCKT LT(_BRACKT, KC_SPC)
#define ESYMBL LT(_SYMBOL, KC_ENT)
#define CNUMBE LT(_NUMBER, KC_SCLN)
#define SNAVIG LT(_NAV, KC_SLSH)

#define S_ENT S(KC_ENT)
#define S_ESC S(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_ALTA, KC_GUIR, KC_CTLS, KC_SFTT,    KC_G,                         KC_M, KC_SFTN, KC_CTLE, KC_GUII, KC_ALTO, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_QUOT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_ESC,  SBRCKT,  CNUMBE,    SNAVIG,  ESYMBL, KC_BSPC \
  ),

  [_RSHIFT] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      S(KC_J), S(KC_L), S(KC_U), S(KC_Y), XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------/                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      S(KC_M), S(KC_N), S(KC_E), S(KC_I), S(KC_O), XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------/                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      S(KC_K), S(KC_H),  KC_GRV, KC_EXLM, KC_DQUO, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_QUES,   S_ENT,  KC_DEL \
  ),

  [_LSHIFT] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, S(KC_Q), S(KC_W), S(KC_F), S(KC_P), S(KC_B),                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_G),                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, S(KC_Z), S(KC_X), S(KC_C), S(KC_D), S(KC_V),                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           S_ESC,  KC_TAB, KC_COLN,     XXXXXXX, XXXXXXX, XXXXXXX \
  ),

  [_NUMBER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    KC_0, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_BRACKT] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_LPRN, KC_RPRN, KC_AMPR, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_LT,   KC_GT, KC_BSLS, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC, KC_RBRC, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYMBOL] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, KC_HASH, KC_CIRC,  KC_DLR, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_ASTR, KC_MINS, KC_PLUS, XXXXXXX,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RGUI, KC_RALT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_TILD,  KC_EQL, KC_UNDS, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,   KC_AT, KC_PERC,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RGUI, KC_RALT, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX \
                                      //`--------------------------'  `--------------------------'
  )
};

// determine the tapdance state to return
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) { return SINGLE_TAP; }
    else { return SINGLE_HOLD; }
  }
  //if (state->count == 2) { return DOUBLE_SINGLE_TAP; }
  else { return 2; } // any number higher than the maximum state value you return above
}

// handle the possible states for each tapdance keycode you define:
void rctl_shift_e_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(S(KC_E));
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_RCTL)); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
  }
}

void rctl_shift_e_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(S(KC_E));
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_RCTL)); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
  }
}

// handle the possible states for each tapdance keycode you define:
void rsft_n_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_N);
      break;
    case SINGLE_HOLD:
      //layer_on(_SHIFT); // for a layer-tap key, use `layer_on(_MY_LAYER)` here
      break;
  }
}

void rsft_n_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_N);
      break;
    case SINGLE_HOLD:
      //layer_off(_SHIFT); // for a layer-tap key, use `layer_off(_MY_LAYER)` here
      break;
  }
}

// define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
  [RCTL_SHIFT_E] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rctl_shift_e_finished, rctl_shift_e_reset),
  [RSFT_N] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rsft_n_finished, rsft_n_reset)
};

//uint32_t layer_state_set_user(uint32_t state) {
//  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
//}

//set_single_persistent_default_layer(_COLEMAK);

//void matrix_init_user(void) {
//    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
//    #ifdef SSD1306OLED
//        iota_gfx_init(!has_usb());   // turns on the display
//    #endif
//}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
//#ifdef SSD1306OLED
//
//// When add source files to SRC in rules.mk, you can use functions.
//const char *read_layer_state(void);
//const char *read_logo(void);
//void set_keylog(uint16_t keycode, keyrecord_t *record);
//const char *read_keylog(void);
//const char *read_keylogs(void);
//
//// const char *read_mode_icon(bool swap);
//// const char *read_host_led_state(void);
//// void set_timelog(void);
//// const char *read_timelog(void);
//
//void matrix_scan_user(void) {
//   iota_gfx_task();
//}
//
//void matrix_render_user(struct CharacterMatrix *matrix) {
//  if (is_master) {
//    // If you want to change the display of OLED, you need to change here
//    matrix_write_ln(matrix, read_layer_state());
//    matrix_write_ln(matrix, read_keylog());
//    //matrix_write_ln(matrix, read_keylogs());
//    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
//    //matrix_write_ln(matrix, read_host_led_state());
//    //matrix_write_ln(matrix, read_timelog());
//  } else {
//    matrix_write(matrix, read_logo());
//  }
//}
//
//void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
//  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
//    memcpy(dest->display, source->display, sizeof(dest->display));
//    dest->dirty = true;
//  }
//}
//
//void iota_gfx_task_user(void) {
//  struct CharacterMatrix matrix;
//  matrix_clear(&matrix);
//  matrix_render_user(&matrix);
//  matrix_update(&display, &matrix);
//}
//#endif//SSD1306OLED

void mod_type(uint16_t modcode, uint16_t keycode) {
  register_mods(MOD_BIT(modcode));
  register_code(keycode);
  unregister_code(keycode);
  unregister_mods(MOD_BIT(modcode));
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
  //#ifdef SSD1306OLED
  //  set_keylog(keycode, record);
  //#endif
    // set_timelog();
    
#ifdef OLED_DRIVER_ENABLE
        oled_timer = timer_read32();
        add_keylog(keycode);
#endif
#ifndef SPLIT_KEYBOARD
        if (keycode == RESET && !is_master) {
            return false;
        }
#endif
    }

  return true;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) || (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
        keycode = keycode & 0xFF;
    } else if (keycode > 0xFF) {
        keycode = 0;
    }

    for (uint8_t i = (KEYLOGGER_LENGTH - 1); i > 0; --i) {
        keylog_str[i] = keylog_str[i - 1];
    }

    if (keycode < (sizeof(code_to_name) / sizeof(char))) {
        keylog_str[0] = pgm_read_byte(&code_to_name[keycode]);
    }

    log_timer = timer_read();
}

void update_log(void) {
  if (timer_elapsed(log_timer) > 750) {
    // add_keylog(0);
  }
}

void render_keylogger_status(void) {
    //oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}

void render_layer_state(void) {
    oled_write_P(PSTR("LAYER"), false);
    //oled_write_P(PSTR("Lower"), layer_state_is(_LOWER));
    //oled_write_P(PSTR("Raise"), layer_state_is(_RAISE));
    //oled_write_P(PSTR("Adjus"), layer_state_is(_ADJUST));
}

void render_blank_line(void) {
  oled_write_ln(" ", false);
}

void render_layout_symbol(void) {
    oled_write_P(PSTR("#^$  "), false);
    oled_write_P(PSTR("*-+  "), false);
    oled_write_P(PSTR("~=_  "), false);
    oled_write_P(PSTR("   @%"), false);
}

void render_layout_brackets(void) {
    oled_write_P(PSTR("  ()&"), false);
    oled_write_P(PSTR("  {}|"), false);
    oled_write_P(PSTR("  <>\\"), false);
    oled_write_P(PSTR("[]   "), false);
}

void render_layout_navigation(void) {
    oled_write_P(PSTR(" U   "), false);
    oled_write_P(PSTR("LDR  "), false);
}

void render_layout_numbers(void) {
    oled_write_P(PSTR("  789"), false);
    oled_write_P(PSTR("  456"), false);
    oled_write_P(PSTR("  123"), false);
    oled_write_P(PSTR(" 0   "), false);
}

void render_layout_blank(void) {
  oled_write_P(PSTR("     "), false);
  oled_write_P(PSTR("     "), false);
  oled_write_P(PSTR("     "), false);
  oled_write_P(PSTR("     "), false);
}

void render_status_main(void) {
  if (layer_state_is(_SYMBOL)) {
    render_layout_symbol();
  } else if (layer_state_is(_NAV)) {
    render_layout_navigation();
  } else {
    render_layout_blank();
  }
    /* Show Keyboard Layout  */
    //render_default_layer_state();
    //render_keylock_status(host_keyboard_leds());
    //render_bootmagic_status();
    //render_user_status();
    // 16 lines max!
    //render_layer_state();
    //render_blank_line();
    //render_blank_line();
    //render_blank_line();
    //render_blank_line();
    //render_blank_line();
    //render_blank_line();
    //render_blank_line();
    //render_blank_line();
    //render_blank_line();
    //render_blank_line();
    //render_blank_line();
    //render_keylogger_status();
}

void render_status_secondary(void) {
  if (layer_state_is(_NUMBER)) {
    render_layout_numbers();
  } else if (layer_state_is(_BRACKT)) {
    render_layout_brackets();
  } else {
    render_layout_blank();
  }
    /* Show Keyboard Layout  */
    //render_default_layer_state();
    //render_layer_state();
    //render_mod_status(get_mods() | get_oneshot_mods());

    //render_blank_line();
    //render_keylogger_status();
}

void oled_task_user(void) {
    if (timer_elapsed32(oled_timer) > 30000) {
        oled_off();
        return;
    }
#    ifndef SPLIT_KEYBOARD
    else {
        oled_on();
    }
#    endif

    update_log();
    if (is_master) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
  }

#endif
