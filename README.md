njbair's Keyboard Firmware Collection
=====================================

This is my personal TMK/QMK firmware repo, based on the work of others and
including my own custom layouts.

Quick Links
-----------

Here are some quick links to my custom TMK layouts in this repo for various
boards:

* Alps64 ([ANSI](keyboard/alps64/keymaps/ansi.c), [AEKII](keyboard/alps64/keymaps/aekii.c), [HHKB](keyboard/alps64/keymaps/hhkb.c))
* [Infinity (ChibiOS)](keyboard/infinity/keymaps/default.c)
* [Filco Zero](keyboard/filco_zero/keymap_ansi.c)
* [Planck](keyboard/planck/keymaps/njbair.c)
* [USB to USB Converter](converter/usb_usb/keymap_njbair.c)

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

The *converter* and *keyboard* directories are used to store per-device configurations. For a new project, I start by copying over something similar from the TMK collection. If you do this, be sure to change the `TMK_DIR` in the Makefile to point to the TMK core in the *modules* folder:

    TMK_DIR = ../../module/tmk/tmk_core

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

