# SPDX-License-Identifier: Apache-2.0

zephyr_library()
zephyr_library_sources(trackball_pim447.c)
zephyr_library_sources_ifdef(CONFIG_ZMK_TRACKBALL_PIM447_INTERRUPT trackball_pim447_trigger.c)
