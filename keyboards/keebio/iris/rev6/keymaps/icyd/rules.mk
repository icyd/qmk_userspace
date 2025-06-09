# Size optimization
# ref: https://docs.qmk.fm/squeezing_avr
AUDIO_ENABLE = no
AVR_USE_MINIMAL_PRINTF = yes
COMBO_ENABLE = yes
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
ENCODER_ENABLE = no
GRAVE_ESC_ENABLE = no
LTO_ENABLE = yes
MAGIC_ENABLE = no
MUSIC_ENABLE = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE = no
UNICODE_ENABLE   = no

# Other config
# ref: https://docs.qmk.fm/features/caps_word
CAPS_WORD_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
## ref: https://docs.qmk.fm/features/os_detection
OS_DETECTION_ENABLE = yes

# External library configuration
GETREUER_DIR = $(shell git -C $(PWD) rev-parse --show-toplevel)/getreuer/features
SRC += $(GETREUER_DIR)/select_word.c $(GETREUER_DIR)/achordion.c
EXTRAINCDIRS += $(GETREUER_DIR)
