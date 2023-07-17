KEYMAP = husenap
KEYBOARD = moonlander

.PHONY: init build clean

build:
	cd qmk_firmware; qmk compile -kb $(KEYBOARD) -km $(KEYMAP)

gencc:
	cd qmk_firmware; qmk generate-compilation-database -kb $(KEYBOARD) -km $(KEYMAP)

init:
	git submodule update --init --recursive --remote --merge

	sed -i 's/LAYOUT_moonlander/LAYOUT/g' qmk_firmware/keyboards/$(KEYBOARD)/**.*

	rm -rf qmk_firmware/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP)
	ln -s $(shell pwd)/$(KEYMAP) qmk_firmware/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP)

clean:
	rm -rf qmk_firmware