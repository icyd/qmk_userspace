// Size optimization
// ref: https://docs.qmk.fm/squeezing_avr
#define LAYER_STATE_8BIT
#define NO_ACTION_ONESHOT
#define NO_MUSIC_MODE
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Home row modifiers
// ref: https://getreuer.info/posts/keyboards/achordion/index.html
// ref: https://precondition.github.io/home-row-mods
#define ACHORDION_STREAK
#define PEMISSIVE_HOLD
#define QUICK_TAP_TERM 120
#define QUICK_TAP_TERM_PER_KEY
#define TAPPING_TERM 200

// Other config
// ref: https://docs.qmk.fm/features/caps_word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
// ref: https://getreuer.info/posts/keyboards/select-word/
#define SELECT_WORD_TIMEOUT 2000
#define EXTRA_SHORT_COMBOS
