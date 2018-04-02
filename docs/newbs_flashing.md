# Flashing Your Keyboard 

Now that you've built a custom firmware file you'll want to flash your keyboard. 

## Flashing Your Keyboard with QMK Toolbox

The simplest way to flash your keyboard will be with the [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases). 

However, the QMK Toolbox is only available for Windows and macOS currently.  If you're using Linux (or just wish to flash the firmware from the command line), you'll have to use the [method outlined below](newbs_flashing.md#flash-your-keyboard-from-the-command-line).

### Load The File Into QMK Toolbox

Begin by opening the QMK Toolbox application. You'll want to locate the firmware file in Finder or Explorer. Your keyboard firmware may be in one of two formats- `.hex` or `.bin`. QMK tries to copy the appropriate one for your keyboard into the root `qmk_firmware` directory.

{% hint style='info' %}
If you are on Windows or macOS there are commands you can use to easily open the current firmware folder in Explorer or Finder.

Windows:

    start .

macOS:

    open .
{% endhint %}

The firmware file always follows this naming format:

    <keyboard_name>_<keymap_name>.{bin,hex}

For example, the `plank/rev5` with a `default` keymap will have this filename:

    planck_rev5_default.hex

Once you have located your firmware file drag it into the "Local file" box in QMK Toolbox, or click "Open" and navigate to where your firmware file is stored. 

### Put Your Keyboard Into DFU (Bootloader) Mode

In order to flash your custom firmware you have to put your keyboard into a special flashing mode. While it is in this mode you will not be able to type or otherwise use your keyboard. It is very important that you do not unplug your keyboard or otherwise interrupt the flashing process while the firmware is being written.

Different keyboards have different ways to enter this special mode. If your PCB currently runs QMK or TMK and you have not been given specific instructions try the following, in order:

* Hold down both shift keys and press `Pause`
* Hold down both shift keys and press `B`
* Unplug your keyboard, hold down the Spacebar and `B` at the same time, plug in your keyboard and wait a second before releasing the keys
* Press the physical `RESET` button on the bottom of the PCB
* Locate header pins on the PCB labeled `BOOT0` or `RESET`, short those together while plugging your PCB in

When you are successful you will see a message similar to this in QMK Toolbox:

```
*** Clueboard - Clueboard 66% HotSwap disconnected -- 0xC1ED:0x2390
*** DFU device connected
```

### Flash Your Keyboard

Click the `Flash` button in QMK Toolbox. You will see output similar to the following:

```
*** Clueboard - Clueboard 66% HotSwap disconnected -- 0xC1ED:0x2390
*** DFU device connected
*** Attempting to flash, please don't remove device
>>> dfu-programmer atmega32u4 erase --force
    Erasing flash...  Success
    Checking memory from 0x0 to 0x6FFF...  Empty.
>>> dfu-programmer atmega32u4 flash /Users/skully/qmk_firmware/clueboard_66_hotswap_gen1_skully.hex
    Checking memory from 0x0 to 0x55FF...  Empty.
    0%                            100%  Programming 0x5600 bytes...
    [>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]  Success
    0%                            100%  Reading 0x7000 bytes...
    [>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]  Success
    Validating...  Success
    0x5600 bytes written into 0x7000 bytes memory (76.79%).
>>> dfu-programmer atmega32u4 reset
    
*** DFU device disconnected
*** Clueboard - Clueboard 66% HotSwap connected -- 0xC1ED:0x2390
```

## Flash your Keyboard from the Command Line

First thing you'll need to know is which bootloader that your keyboard uses.  There are four main bootloaders that are used, usually. Pro-Micro and clones use CATERINA, and Teensy's use Halfkay, OLKB boards use QMK-DFU, and other atmega32u4 chips use DFU. 

You can find more information about the bootloaders in the [Flashing Instructions and Bootloader Information](flashing.md) page. 

If you know what bootloader that you're using, then when compiling the firmware, you can actually add some extra text to the `make` command to automate the flashing process. 

### DFU

For the DFU bootloader, when you're ready to compile and flash your firmware, open up your terminal window and run the built command: 

    make <my_keyboard>:<my_keymap>:dfu

For example, if your keymap is named "xyverz" and you're building a keymap for a rev5 planck, you'll use this command:

    make planck/rev5:xyverz:dfu

Once it finishes compiling, it should output the following:

```
Linking: .build/planck_rev5_xyverz.elf                                                              [OK]
Creating load file for flashing: .build/planck_rev5_xyverz.hex                                      [OK]
Copying planck_rev5_xyverz.hex to qmk_firmware folder                                               [OK]
Checking file size of planck_rev5_xyverz.hex                                                        
 * File size is fine - 18574/28672
 ```

After it gets to this point, the build script will look for the DFU bootloader every 5 seconds.  It will repeat the following until the device is found or you cancel it. 

    dfu-programmer: no device present.
    Error: Bootloader not found. Trying again in 5s.

Once it does this, you'll want to reset the controller.  It should then show output similiar to this: 

```
*** Attempting to flash, please don't remove device
>>> dfu-programmer atmega32u4 erase --force
    Erasing flash...  Success
    Checking memory from 0x0 to 0x6FFF...  Empty.
>>> dfu-programmer atmega32u4 flash /Users/skully/qmk_firmware/clueboard_66_hotswap_gen1_skully.hex
    Checking memory from 0x0 to 0x55FF...  Empty.
    0%                            100%  Programming 0x5600 bytes...
    [>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]  Success
    0%                            100%  Reading 0x7000 bytes...
    [>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>]  Success
    Validating...  Success
    0x5600 bytes written into 0x7000 bytes memory (76.79%).
>>> dfu-programmer atmega32u4 reset
```

If you have any issues with this, you may need to this: 

    sudo make <my_keyboard>:<my_keymap>:dfu

### Caterina 

For Arduino boards and their close (such as the SparkFun ProMicro), when you're ready to compile and flash your firmware, open up your terminal window and run the built command: 

    make <my_keyboard>:<my_keymap>:avrdude

For example, if your keymap is named "xyverz" and you're building a keymap for a rev2 Lets Split, you'll use this command:

    make lets_split/rev2:xyverz:avrdude

Once the firmware finishes compiling, it will output something like this: 

```
Linking: .build/lets_split_rev2_xyverz.elf                                                            [OK]
Creating load file for flashing: .build/lets_split_rev2_xyverz.hex                                    [OK]
Checking file size of lets_split_rev2_xyverz.hex                                                      [OK]
 * File size is fine - 27938/28672
Detecting USB port, reset your controller now..............
```

At this point, reset the board and then the script will detect the bootloader and then flash the board.  The output should look something like this: 

```
Detected controller on USB port at /dev/ttyS15

Connecting to programmer: .
Found programmer: Id = "CATERIN"; type = S
    Software Version = 1.0; No Hardware Version given.
Programmer supports auto addr increment.
Programmer supports buffered memory access with buffersize=128 bytes.

Programmer supports the following devices:
    Device code: 0x44

avrdude.exe: AVR device initialized and ready to accept instructions

Reading | ################################################## | 100% 0.00s

avrdude.exe: Device signature = 0x1e9587 (probably m32u4)
avrdude.exe: NOTE: "flash" memory has been specified, an erase cycle will be performed
             To disable this feature, specify the -D option.
avrdude.exe: erasing chip
avrdude.exe: reading input file "./.build/lets_split_rev2_xyverz.hex"
avrdude.exe: input file ./.build/lets_split_rev2_xyverz.hex auto detected as Intel Hex
avrdude.exe: writing flash (27938 bytes):

Writing | ################################################## | 100% 2.40s

avrdude.exe: 27938 bytes of flash written
avrdude.exe: verifying flash memory against ./.build/lets_split_rev2_xyverz.hex:
avrdude.exe: load data flash data from input file ./.build/lets_split_rev2_xyverz.hex:
avrdude.exe: input file ./.build/lets_split_rev2_xyverz.hex auto detected as Intel Hex
avrdude.exe: input file ./.build/lets_split_rev2_xyverz.hex contains 27938 bytes
avrdude.exe: reading on-chip flash data:

Reading | ################################################## | 100% 0.43s

avrdude.exe: verifying ...
avrdude.exe: 27938 bytes of flash verified

avrdude.exe: safemode: Fuses OK (E:CB, H:D8, L:FF)

avrdude.exe done.  Thank you.
```
If you have any issues with this, you may need to this: 

    sudo make <my_keyboard>:<my_keymap>:avrdude

## HalfKay

For the PJRC devices (Teensy's), when you're ready to compile and flash your firmware, open up your terminal window and run the built command: 

    make <my_keyboard>:<my_keymap>:teensy

For example, if your keymap is named "xyverz" and you're building a keymap for an Ergodox or Ergodox EZ, you'll use this command:

    make erdogox_ez:xyverz:teensy

Once the firmware finishes compiling, it will output something like this: 

```
Linking: .build/ergodox_ez_xyverz.elf                                                               [OK]
Creating load file for flashing: .build/ergodox_ez_xyverz.hex                                       [OK]
Checking file size of ergodox_ez_xyverz.hex                                                         [OK]
 * File size is fine - 25584/32256
 Teensy Loader, Command Line, Version 2.1
Read "./.build/ergodox_ez_xyverz.hex": 25584 bytes, 79.3% usage
Waiting for Teensy device...
 (hint: press the reset button)
 ```

 At this point, reset your board.  Once you've done that, you'll see output like this: 

 ```
 Found HalfKay Bootloader
Read "./.build/ergodox_ez_drashna.hex": 28532 bytes, 88.5% usage
Programming............................................................................................................................................................................
...................................................
Booting
```


## Test It Out!

Congrats! Your custom firmware has been programmed to your keyboard!

Give it a try and make sure everything works the way you want it to. We've written [Testing and Debugging](newbs_testing_debugging.md) to round out this Newbie Guide, so head over there to learn about how to troubleshoot your custom functionality.
