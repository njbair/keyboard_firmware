njbair's Keyboard Firmware Collection
=====================================

This is my personal TMK/QMK firmware repo, based on the work of others and
including my own custom layouts.

Quick Links
-----------

Here are some quick links to my custom TMK layouts in this repo for various
boards:

* [HHKB Professional 2](keyboard/hhkb)
* [Alps64](keyboard/alps64)
* [Monarch](keyboard/monarch)
* [Infinity](keyboard/infinity) (ChibiOS)
* [Filco Zero](keyboard/filco_zero)
* [Unicomp PC-122](converter/pc122_usb) (Hard-wired Teensy with TMK PS2-USB converter)
* [Planck](keyboard/planck)
* [USB to USB Converter](converter/usb_usb)

------------------------------------------------------------------------

Why Maintain Your Own Repository?
=================================

My main reason for maintaining this repo is that my keyboard use presents unique demands which I believe can be solved through creative use of firmware.

1. I am a happy Dvorak user. I believe firmware can overcome some of the common shortcomings of the Dvorak layout.
2. I occasionally play PC games.
3. I have *a lot* of keyboards.
4. I support *a lot* of computers.

It Makes a Dvorak User's Life Easier
------------------------------------

What's the single biggest complaint about Dvorak among those who actually use it? In my experience, it's the fact that the most common keyboard shortcuts, Ctrl+Z/X/C/V, are remapped all over the place. Well, what if a simple firmware function could solve this issue?

Borrowing the idea from Mac OSX's Dvorak-QWERTY layout, I've created a firmware function to re-map the alpha keys back to QWERTY whenever the Left Ctrl modifier is pressed. Having this support at the hardware level means that I can plug my keyboard into any machine and get started right away, regardless of how the user has their software keymap configured.

It Makes PC Games More Fun
--------------------------

My standard layout uses SpaceFn, which is something you can enable through most graphical firmware layout editors. However, SpaceFn and PC games don't mix. Dvorak and PC games don't really mix, either. For these reasons, I've implemented a special QWERTY overlay for gaming which disables SpaceFn (and Enter Fn), and while we're at it disables the Win keys as well.

I still lose at Fortnite, but at least now it's not my keyboard's fault.

It Makes Maintaining Lots of Keyboards More Practical
-----------------------------------------------------

If I tried to use graphical keyboard firmware editors for every keyboard I own, I would have given up by now. I also wouldn't be able to consistently implement all my custom tweaks. By creating this repository and extending TMK/QMK in a scalable and maintainable way, it not only eliminates a lot of the hassle, but actually makes it kind of fun.

------------------------------------------------------------------------

Using this Repository
=====================

Unless you're me, you probably won't want to use this repo as-is right out of
the box. But it could be a good starting point for managing your own personal
keyboard firmware collection. Much care has been taken to structure this
repository in a simple, meaningful, and maintainable way.

Directory Structure
-------------------

```
[root]
|-- common
|-- converter
|-- keyboard
|   |-- keyboard_a
|   |   |-- keymaps
|   |   |   |-- default.c 
|   |   |   |-- otherlayout.c 
|   |   |   `-- anotherlayout.c 
|   |   |-- config.h
|   |   |-- Makefile
|   |   `-- [...]
|   `-- keyboard_b
|   `-- keyboard_c
`-- modules
    |-- tmk
    |-- qmk
    `-- [others]
```

### Keyboards & Converters

The *converter* and *keyboard* directories are used to store per-device configurations. For a new project, I start by copying over something similar from the TMK collection. Here's a good starting point:

```
keymaps/
Makefile
config.h
keymap_common.h
macro.h
```

If you do this, be sure to change the `TMK_DIR` in the Makefile to point to the TMK core in the *modules* folder:

    TMK_DIR = ../../module/tmk/tmk_core

You'll also need to point any additional sources back to the parent TMK folder. So then, this line:

    SRC ?= matrix.c

...would become this:

    SRC ?= ../../module/tmk/keyboard/alps64/matrix.c

Next, I move all layout-specific keymap files to a newly-created *keymaps* directory, to help cut down on clutter and simplify file naming:

```shell
mkdir -p keymaps
mv keymap_ansi.c keymaps/ansi.c
```

...then before you go any further, edit the Makefile and modify the keymap selection logic to work with this new file-naming scheme:

```makefile
ifdef KEYMAP
    SRC := keymaps/$(KEYMAP).c $(SRC)
else
    SRC := keymaps/ansi.c $(SRC)
endif
```

Additionally, I have some custom configurations which are common among all my builds. I place these in the */common* directory in the project root. Then I add them to the keyboard Makefile with a few extra lines:

```
NJBAIR_COMMON_DIR ?= ../../common
SRC += $(NJBAIR_COMMON_DIR)/init.c
VPATH += $(NJBAIR_COMMON_DIR)
```

Now you should be good to go.

### Modules

This repository stores the core third-party firmware projects in the *modules*
directory, along with some other necessary third-party repositories. The included modules can be found here:

- [TMK Firmware](https://github.com/tmk/tmk_keyboard.git)
- [QMK Firmware](https://github.com/jackhumbert/qmk_firmware.git)
- [Flabbergast's ChibiOS fork](https://github.com/flabbergast/ChibiOS.git)

The repositories are included as subtrees, so they can be updated using
standard **git subtree** syntax, as follows:

```shell
git subtree pull --prefix module/tmk https://github.com/tmk/tmk_keyboard.git master --squash
git subtree pull --prefix module/qmk https://github.com/jackhumbert/qmk_firmware.git master --squash
git subtree pull --prefix module/chibios https://github.com/flabbergast/ChibiOS.git master --squash
```

I like to add the third-party repositories as named remotes in my local git repo:

```shell
git remote add tmk https://github.com/tmk/tmk_keyboard.git
git remote add qmk https://github.com/jackhumbert/qmk_firmware.git
git remote add chibios https://github.com/flabbergast/ChibiOS.git
```

...which makes pulling in updates that much easier:

```shell
git subtree pull --prefix module/tmk tmk master --squash
git subtree pull --prefix module/qmk qmk master --squash
git subtree pull --prefix module/chibios chibios master --squash
```



-----------------------------------------------------------------------

Building & Flashing the Firmware
================================

I have only had success building the firmware on Linux. I tried Windows once
but gave up and installed a VM running Ubuntu LTS. I recommend you do the
same.

Required Libraries
------------------

To build on Ubuntu, install the following libraries:

- gcc-avr
- avr-libc
- dfu-programmer

Additional required libraries for ARM-based firmware (e.g., Infinity Keyboard):

- dfu-util (required for flashing)
- gcc-arm-none-eabi



### Building & Flashing in Linux

To compile the firmware for a custom keymap stored in the file
*keymaps/hhkb.c*, issue the following commands:

    $ make clean
    $ make KEYMAP=hhkb

The process for flashing the firmware is different for each device. Most simply,
to flash the firmware for an AVR controller in Linux, issue the following
command:

    $ sudo make dfu

For the Infinity, issue the following command:

    $ sudo dfu-util -D build/infinity.bin -d 1c11:b007

### Building & Flashing in Windows

As mentioned above, at this point I haven't managed to successfully build TMK
natively in Windows. Instead, I use a Ubuntu VM to build the firmware, then
use Atmel's FLIP application to flash the .hex file.

Initial setup:

1. Download and install Atmel's FLIP application.
2. Plugin the converter and place it into bootloader mode.
3. Open Device Manager and update the driver for the ATmega32U4. Browse to
   *C:\Program Files (x86)\Atmel\Flip 3.4.7\usb*

#### Flashing via Atmel FLIP

These instructions have been tested on hasu's USB to USB converter dongle, and
hasu's alps64 PCB.

1. Open the Atmel FLIP application.
2. Click **Device > Select** and choose the appropriate device type from the list.
  - For hasu's USB to USB converter dongle, choose **ATmega32U4**.
  - For hasu's alps64 PCB, choose **ATmega32U2**.
3. Click **Settings > Communication > USB** and click the **Open** button.
4. Under *Operations Flow*, make sure the boxes are checked for *Erase*, *Blank
   Check*, *Program*, and *Verify*, then click **Run**.
5. Once the firmware has been flashed, check the *Reset* box next to the **Start
   Application** button, then click the button.

#### Flashing the USB to USB Converter firmware onto an Arduino Leonardo with USB Host Shield

We don't have a driver for this that works with FLIP, but we can use avrdude to
do it instead.

1. Open Device Manager and find out which COM port the Leonardo bootloader uses.
   It's listed under *Ports (COM & LPT)*. You may need to use **View > Show hidden
   devices** first.
2. Open a command prompt or PowerShell window. Place the device in bootloader
   mode and issue the following command: `avrdude -p atmega32u4 -c avr109 -b 57600
   -U flash:w:usb_usb.hex -P COM7` where COM7 is the port name you found in Device
   Manager.

