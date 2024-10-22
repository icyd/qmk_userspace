CAPS_WORD_ENABLE = yes
ENCODER_ENABLE = no
EXTRAKEY_ENABLE = no
UNICODE_ENABLE   = no
SWAP_HANDS_ENABLE = no
AUDIO_ENABLE = no
MOUSEKEY_ENABLE = yes

GETREUER_DIR = $(shell git -C $(PWD) rev-parse --show-toplevel)/getreuer/features
SRC += $(GETREUER_DIR)/select_word.c $(GETREUER_DIR)/achordion.c
EXTRAINCDIRS += $(GETREUER_DIR)
