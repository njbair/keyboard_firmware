ifndef KEYMAP
	KEYMAP = default
endif

# Target file name (without extension).
PROJECT = ch
TARGET_DIR = .
TMK_DIR = ../../module/tmk/tmk_core

SRC = keymap_common.c \
	matrix.c \
	led.c \
	keymaps/$(KEYMAP).c

CONFIG_H = config.h

# MCU-specific settings
# Refer to
# https://github.com/tmk/tmk_keyboard/tree/master/keyboard/infinity_chibios for
# more information
MCU_FAMILY = KINETIS
MCU_SERIES = K20x
MCU_LDSCRIPT = MK20DX128BLDR4
MCU_STARTUP = k20x5
BOARD = MCHCK_K20
MCU  = cortex-m4
ARMV = 7
OPT_DEFS = -DCORTEX_VTOR_INIT=0x00001000

# Build Options
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
KEYBOARD_LOCK_ENABLE = yes  # Child lock
NKRO_ENABLE = yes           # USB Nkey Rollover
#MOUSEKEY_ENABLE = yes       # Mouse keys
#SLEEP_LED_ENABLE = yes      # Breathing sleep LED during USB suspend

# Optimize size but this may cause error "relocation truncated to fit"
EXTRALDFLAGS = -Wl,--relax

include $(TMK_DIR)/tool/chibios/common.mk
include $(TMK_DIR)/tool/chibios/chibios.mk

program: $(BUILDDIR)/$(PROJECT).bin
	dfu-util -D $(BUILDDIR)/$(PROJECT).bin
