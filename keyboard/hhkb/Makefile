KEYMAP ?= default

# Target file name (without extension).
TARGET ?= hhkb
TARGET_DIR ?= .
TMK_DIR ?= ../../module/tmk/tmk_core
NJBAIR_COMMON_DIR ?= ../../common

SRC ?= \
	../../module/tmk/keyboard/hhkb/matrix.c \
	../../module/tmk/keyboard/hhkb/led.c \
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
BOOTMAGIC_ENABLE ?= yes      # Virtual DIP switch configuration
EXTRAKEY_ENABLE ?= yes       # Audio control and System control
CONSOLE_ENABLE ?= yes        # Console for debug
COMMAND_ENABLE ?= yes        # Commands for debug and configuration
KEYBOARD_LOCK_ENABLE ?= yes  # Child lock
NKRO_ENABLE ?= yes           # USB Nkey Rollover
#MOUSEKEY_ENABLE ?= yes       # Mouse keys(+4700)

#OPT_DEFS += -DNO_ACTION_TAPPING
#OPT_DEFS += -DNO_ACTION_LAYER
#OPT_DEFS += -DNO_ACTION_MACRO

# Optimize size but this may cause error "relocation truncated to fit"
EXTRALDFLAGS = -Wl,--relax

# Search Path
VPATH += $(NJBAIR_COMMON_DIR)
VPATH += $(TARGET_DIR)
VPATH += $(TMK_DIR)

include $(TMK_DIR)/protocol/lufa.mk
include $(TMK_DIR)/common.mk
include $(TMK_DIR)/rules.mk

debug-on: EXTRAFLAGS += -DDEBUG -DDEBUG_ACTION
debug-on: all

debug-off: EXTRAFLAGS += -DNO_DEBUG -DNO_PRINT
debug-off: OPT_DEFS := $(filter-out -DCONSOLE_ENABLE,$(OPT_DEFS))
debug-off: all
