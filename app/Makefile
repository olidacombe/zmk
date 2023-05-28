.PHONY: build
.DEFAULT_GOAL := build

build-%:
	make _build-guppy_$*

# OSX only rn, ensure this in ~/.lima/default/lima.yaml:
# - location: "~/od/zmk"
#   mountPoint: "/tmp/lima/zmk"
#   writable: true
builder:
	docker run -it -v "${HOME}/od/zmk-config:/zmk-config" -e ZMK_CONFIG=/zmk-config/config -v "/tmp/lima/zmk:/zmk" docker.io/zmkfirmware/zmk-dev-arm:3.0

_build-%:
	west build -p -d build/$* -- -DZMK_CONFIG="${ZMK_CONFIG:-"${HOME}/od/zmk-config/config}" -DSHIELD=$*

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
