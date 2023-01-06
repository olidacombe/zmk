.PHONY: build
.DEFAULT_GOAL := build

build-%:
	west build -p -d build/$* -- -DZMK_CONFIG="${HOME}/od/kbd/zmk-config/config" -DSHIELD=guppy_$*

build:
	make build-left
	make build-right

flash-%:
	mount -uw /Volumes/NICENANO
	cp build/$*/zephyr/zmk.uf2 /Volumes/NICENANO/

flash:
	make flash-left
