.PHONY: build
.DEFAULT_GOAL := build

build-%:
	make _build-guppy_$*

_build-%:
	west build -p -d build/$* -- -DZMK_CONFIG="${HOME}/od/kbd/zmk-config/config" -DSHIELD=$*


build:
	make build-left
	make build-right

reset:
	make _build-settings_reset

flash-%:
	mount -uw /Volumes/NICENANO
	cp build/guppy_$*/zephyr/zmk.uf2 /Volumes/NICENANO/

flash:
	make flash-left
