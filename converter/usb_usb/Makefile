ifndef KEYMAP
	KEYMAP = ansi
endif

# Target file name (without extension).
TARGET = usb_usb
TARGET_DIR = .
TMK_DIR = ../../module/tmk/tmk_core

SRC = keymap_common.c \
	matrix.c \
	main.cpp \
	keymaps/$(KEYMAP).c

CONFIG_H = config.h

# MCU-specific settings
ARCH = AVR8
MCU = atmega32u4
F_CPU = 16000000
F_USB = $(F_CPU)
OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Interrupt driven control endpoint task
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

# Build Options
#BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Media control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
#NKRO_ENABLE = yes	# USB Nkey Rollover

# Optimize size
LDFLAGS += -Wl,--relax

# Search Path
VPATH += $(TARGET_DIR)
VPATH += $(TMK_DIR)

# program Leonardo
PROGRAM_CMD = avrdude -p$(MCU) -cavr109 -b57600 -Uflash:w:$(TARGET).hex -P$(DEV)

include $(TMK_DIR)/protocol/usb_hid.mk
include $(TMK_DIR)/protocol/lufa.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/rules.mk
