#include <stdint.h>
#include "action.h"
#include "eeconfig.h"
#include "keycode_config.h"
#include "matrix.h"
#include "os_detection.h"
#include "quantum.h"
#include "select_word.h"
#include "achordion.h"

/* bool process_custom_layers(uint16_t keycode, keyrecord_t* record, uint16_t sel_keycode, uint16_t layer) { */
/*     if (keycode == sel_keycode) { */
/*         if (record->event.pressed) { */
/*             set_single_persistent_default_layer(layer); */
/*             layer_move(layer); */
/*         } */
/*             return false; */
/*     } */
/**/
/*     return true; */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    if (!process_select_word(keycode, record, K_SELWORD)) {
        return false;
    }
    /* if (!process_custom_layers(keycode, record, K_QWERTY, _QWERTY)) { return false; } */
    /* if (!process_custom_layers(keycode, record, K_DVORAK, _DVORAK)) { return false; } */
    /* if (!process_custom_layers(keycode, record, K_ENGRAM, _ENGRAM)) { return false; } */

    return true;
}

void matrix_scan_user(void) {
    achordion_task();
    select_word_task();
}

bool process_detected_host_os_user(os_variant_t os) {
    if (os == OS_MACOS) {
        keymap_config.raw            = eeconfig_read_user();
        keymap_config.swap_lalt_lgui = true;
        clear_keyboard();
    }

    return true;
}
