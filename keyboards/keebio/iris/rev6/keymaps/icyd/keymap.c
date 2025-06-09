#include <stdint.h>
#include "achordion.h"
#include "action.h"
#include "action_tapping.h"
#include "keycode_config.h"
#include "keycodes.h"
#include "matrix.h"
#include "os_detection.h"
#include "progmem.h"
#include "select_word.h"
#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum custom_layers {
    _ENTHIUM,
    _QWERTY,
    _SYS,
    _NAV,
    _SYM,
};

enum custom_keycodes {
    K_SELWRD = SAFE_RANGE,
};

// Home row mods
#define HOME_Y RALT_T(KC_Y)
#define HOME_C LGUI_T(KC_C)
#define HOME_I LALT_T(KC_I)
#define HOME_E LCTL_T(KC_E)
#define HOME_A LSFT_T(KC_A)
#define HOME_G LT(_SYM, KC_G)
#define HOME_QUO LT(_SYM, KC_QUOT)
#define HOME_W RALT_T(KC_W)
#define HOME_H RSFT_T(KC_H)
#define HOME_T RCTL_T(KC_T)
#define HOME_N LALT_T(KC_N)
#define HOME_S LGUI_T(KC_S)
#define HOME_P LT(_SYM, KC_P)
#define HOME_F LT(_SYM, KC_F)

// Layer switch
#define LT_BSPC LT(_SYM, KC_BSPC)
#define LT_DEL LT(_SYM, KC_DEL)
#define LT_PGDN LT(_SYS, KC_PGDN)
#define LT_PGUP LT(_NAV, KC_PGUP)
#define LT_R LT(_NAV, KC_R)
#define LT_HOME LT(_SYS, KC_HOME)
#define LT_END LT(_NAV, KC_END)
#define LT_ESC LT(_SYS, KC_ESC)

// Keys with mod
#define ALT_TAB LALT(KC_TAB)
#define K_CUT LCTL(KC_X)
#define K_YANK LCTL(KC_C)
#define K_PASTE LCTL(KC_V)
#define K_FIND LCTL(KC_F)
#define K_FINDN LCTL(KC_G)
#define K_UNDO LCTL(KC_Z)
#define K_REDO LCTL(KC_Y)
#define K_SELALL LCTL(KC_A)
#define K_CLR LCTL(KC_L)

#define S_ENTHIUM PDF(_ENTHIUM)
#define S_QWERTY PDF(_QWERTY)

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(jk_combo, KC_ESC),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ENTHIUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    HOME_Y,  KC_O,    KC_U,    KC_SCLN,                            KC_X,    KC_L,    KC_D,    HOME_W,  KC_Z,    KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_B,    HOME_C,  HOME_I,  HOME_E,  HOME_A,  KC_COMM,                            KC_K,    HOME_H,  HOME_T,  HOME_N,  HOME_S,  KC_V,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, HOME_QUO,KC_SLSH, KC_EQUAL,KC_MINS, KC_DOT,  KC_BSPC,          KC_DEL,  KC_J,    KC_M,    KC_G,    KC_P,    HOME_F,  KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LT_HOME, LT_END,  KC_SPC,                    KC_ENT,  LT_R,    LT_ESC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS,          KC_TRNS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_SYS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   DB_TOGG,                           S_ENTHIUM,S_QWERTY,KC_NO,   KC_NO,   KC_NO,   EE_CLR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_M_P,                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   RGB_VAD, RGB_VAI, RGB_SPD, RGB_SPI, RGB_M_B,                            KC_NO,   KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, RGB_RMOD,RGB_MOD, RGB_M_R, RGB_M_SW,KC_NO,   KC_TRNS,          KC_TRNS, KC_NO,   KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_BTN4,                            K_CUT,   K_FIND,  K_FINDN, K_UNDO,  K_REDO,  K_CLR,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN5,                            K_YANK,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,K_SELWRD,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_NO,   KC_ACL0, KC_ACL1, KC_ACL2, KC_BTN3, KC_BTN1,          ALT_TAB, K_PASTE, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_BTN2,                   KC_LALT, KC_LCTL, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                           KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_CIRC, KC_LCBR, KC_RCBR, KC_BSLS, KC_COLN,                            KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_AMPR, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_LT,                              KC_PCMM, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PMNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,   KC_GRV,  KC_PIPE, KC_TILD, KC_ASTR, KC_GT,   KC_BSPC,          KC_DEL,  KC_PDOT, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_SPC,                    KC_ENT,  KC_NO,   KC_NO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    if (!process_select_word(keycode, record, K_SELWRD)) {
        return false;
    }

    return true;
}

bool process_detected_host_os_user(os_variant_t detected_os) {
    if (detected_os == OS_MACOS) {
        keymap_config.swap_lalt_lgui = true;
        clear_keyboard();
    }

    return true;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    switch (tap_hold_keycode) {
        // Shift + g
        case HOME_A:
            if (other_keycode == KC_G) {
                return true;
            }
            break;
        // Ctrl + c
        case HOME_E:
            if (other_keycode == KC_C) {
                return true;
            }
        // Ctrl + l
        case HOME_T:
            if (other_keycode == KC_L) {
                return true;
            }
        // AltGr + (a|e)
        case HOME_Y:
            if (other_keycode == KC_A || other_keycode == KC_E) {
                return true;
            }
            break;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LCTL:
        case MOD_RCTL:
        case MOD_RALT:
            return true;
    }

    return false;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_H:
        case HOME_N:
            return QUICK_TAP_TERM;
        default:
            return 0;
    }
}

void matrix_scan_user(void) {
    achordion_task();
    select_word_task();
}
