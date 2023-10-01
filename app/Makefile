.PHONY: build
.DEFAULT_GOAL := build

DOCKER := $(if $(shell [ "$$(uname)" = "Darwin" ] && echo true),lima nerdctl,docker)
ZMK := $(if $(shell [ "$$(uname)" = "Darwin" ] && echo true),/tmp/lima/zmk,$${HOME}/od/zmk)

BOARD ?= charybdis

build-%:
	make _build-${BOARD}_$*

# OSX only rn, ensure this in ~/.lima/default/lima.yaml:
# - location: "~/od/zmk"
#   mountPoint: "/tmp/lima/zmk"
#   writable: true
builder:
	$(DOCKER) run -it -v "$${HOME}/od/zmk-config:/zmk-config" -e ZMK_CONFIG=/zmk-config/config -v "$(ZMK):/zmk" docker.io/zmkfirmware/zmk-dev-arm:3.2

_build-%:
	west build -p -b nice_nano_v2 -d build/$* -- -DZMK_CONFIG="$${ZMK_CONFIG:-"$${HOME}/od/zmk-config/config"}" -DSHIELD=$*

build:
	make build-left
	make build-right

reset:
	make _build-settings_reset

flash-%:
	mount -uw /Volumes/NICENANO
	cp build/${BOARD}_$*/zephyr/zmk.uf2 /Volumes/NICENANO/

flash:
	make flash-left

_nag:
	west update 2>&1 | grep "git config" | xargs -0 bash -c
