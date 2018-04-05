KEYMAP ?= ansi

# Target file name (without extension).
TARGET ?= usb_usb
TARGET_DIR ?= .
TMK_DIR ?= ../../module/tmk/tmk_core
NJBAIR_COMMON_DIR ?= ../../common

SRC ?= \
	../../module/tmk/converter/usb_usb/usb_usb.cpp \
	../../module/tmk/converter/usb_usb/main.cpp \
	$(NJBAIR_COMMON_DIR)/init.c \
	keymaps/$(KEYMAP).c

CONFIG_H ?= config.h

# MCU-specific settings
ARCH ?= AVR8
MCU ?= atmega32u4
F_CPU ?= 16000000
F_USB ?= $(F_CPU)
OPT_DEFS += -DBOOTLOADER_SIZE=4096

# Interrupt driven control endpoint task
# Basically all HID devices use this. --njb
OPT_DEFS += -DINTERRUPT_CONTROL_ENDPOINT

# Build Options
EXTRAKEY_ENABLE ?= yes	# Media control and System control
CONSOLE_ENABLE ?= yes	# Console for debug
COMMAND_ENABLE ?= yes    # Commands for debug and configuration
#MOUSEKEY_ENABLE ?= yes	# Mouse keys
#NKRO_ENABLE = yes	# USB Nkey Rollover

# Optimize size
EXTRALDFLAGS += -Wl,--relax

# Search Path
VPATH += $(NJBAIR_COMMON_DIR)
VPATH += $(TARGET_DIR)
VPATH += $(TMK_DIR)

include $(TMK_DIR)/protocol/usb_hid.mk
include $(TMK_DIR)/protocol/lufa.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/rules.mk
