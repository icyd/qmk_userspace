KEYBOARD=keebio/iris/rev6
KEYMAP=icyd

all: flash

flash: build
	qmk flash -kb $(KEYBOARD) -km $(KEYMAP)

build: keymap.c config.h rules.mk
	test ! -f keymap.json
	qmk compile -kb $(KEYBOARD) -km $(KEYMAP)

keymap.c: keymap_config.json keymap_header.c keymap_footer.c config.h
	qmk json2c -o $@ $<
	spot=$$( awk '/THIS FILE WAS GENERATED/ { print NR-1 }' $@ ) && \
	sed -e "$$spot r keymap_header.c" -e "$$ r keymap_footer.c" -i $@

clean:
	qmk clean
	rm -fv keymap.c
	rm -fv $$(git rev-parse --show-toplevel)/$$(echo $(KEYBOARD) | tr / _)_$(KEYMAP).hex

.PHONY: flash build clean
