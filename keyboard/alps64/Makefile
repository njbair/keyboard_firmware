ifndef KEYMAP
	KEYMAP = ansi
endif

# Target file name (without extension).
TARGET = alps64
TARGET_DIR = .
TMK_DIR = ../../module/tmk/tmk_core

SRC = keymap_common.c \
	matrix.c \
	led.c \
	init.c \
	keymaps/$(KEYMAP).c

CONFIG_H = config.h

# MCU-specific settings
ARCH = AVR8
MCU = atmega32u2
F_CPU = 16000000
F_USB = $(F_CPU)
OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Interrupt driven control endpoint task(+60)
# Basically all HID devices use this. --njb
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

# Build Options
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration(+1000)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = yes        # Console for debug(+400)
COMMAND_ENABLE = yes        # Commands for debug and configuration
KEYBOARD_LOCK_ENABLE = yes  # Child lock
NKRO_ENABLE = yes           # USB Nkey Rollover
#MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
#SLEEP_LED_ENABLE = yes      # Breathing sleep LED during USB suspend

# Optimize size but this may cause error "relocation truncated to fit"
EXTRALDFLAGS = -Wl,--relax

include $(TMK_DIR)/protocol/lufa.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/rules.mk

# Search Path
VPATH += $(TARGET_DIR)
VPATH += $(TMK_DIR)
