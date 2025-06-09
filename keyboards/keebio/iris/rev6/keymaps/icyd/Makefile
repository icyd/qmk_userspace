KEYBOARD=keebio/iris/rev6
KEYMAP=icyd

all: flash

flash: build
	qmk flash -kb $(KEYBOARD) -km $(KEYMAP)

build: keymap_config.json config.h rules.mk
	@test ! -f keymap.json
	qmk compile -kb $(KEYBOARD) -km $(KEYMAP)

keymap_config.json: keymap.c
	@qmk c2json --no-cpp -o $@ $<

clean:
	qmk clean
	rm -fv keymap_config.json
	rm -fv $$(git rev-parse --show-toplevel)/$$(echo $(KEYBOARD) | tr / _)_$(KEYMAP).hex

.PHONY: flash build clean
.SILENT: clean
