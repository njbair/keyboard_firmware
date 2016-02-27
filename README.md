njbair's Keyboard Firmware Collection
=====================================

This is my personal TMK/QMK firmware repo, based on the work of others and
including my own custom layouts.

My Custom Layouts
-----------------

Here are some quick links to my custom TMK layouts in this repo for various
boards:

* [Alps64 (ANSI Layout)](keyboard/alps64/keymaps/ansi.c)
* [Alps64 (AEKII Layout)](keyboard/alps64/keymaps/aekii.c)
* [Alps64 (HHKB Layout)](keyboard/alps64/keymaps/hhkb.c)
* [Infinity (ChibiOS)](keyboard/infinity/keymaps/default.c)
* [Filco Zero](keyboard/filco_zero/keymap_ansi.c)
* [Planck](keyboard/planck/keymaps/njbair.c)
* [USB to USB Converter](converter/usb_usb/keymap_njbair.c)

Required Libraries
------------------

To build on Ubuntu, install the following libraries:

- gcc-avr
- avr-libc
- dfu-programmer

### Additional required libraries for the Infinity Keyboard:

- dfu-util
- gcc-arm-none-eabi



Building & Flashing the Firmware
--------------------------------

### Linux

To compile the firmware for a custom keymap stored in the file
*keymap_njbair.c*, issue the following commands:

    $ make clean
    $ make KEYMAP=njbair

The process for flashing the firmware is different for each device. Most simply,
to flash the firmware for an AVR controller in Linux, issue the following
command:

    $ sudo make dfu

For the Infinity, issue the following command:

    $ sudo dfu-util -D build/infinity.bin -d 1c11:b007

### Windows

At this point I haven't managed to successfully build TMK natively in Windows.
Instead, I use a Ubuntu VM to build the firmware, then use Atmel's FLIP
application to flash the .hex file.

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

