# Basic Keycodes

The basic set of keycodes are based on the [HID Keyboard/Keypad Usage Page (0x07)](http://www.usb.org/developers/hidpage/Hut1_12v2.pdf) with the exception of `KC_NO`, `KC_TRNS` and keycodes in the `0xA5-DF` range. See below for more details.

## Letters and Numbers

|Key   |Description|
|------|-----------|
|`KC_A`|`a` and `A`|
|`KC_B`|`b` and `B`|
|`KC_C`|`c` and `C`|
|`KC_D`|`d` and `D`|
|`KC_E`|`e` and `E`|
|`KC_F`|`f` and `F`|
|`KC_G`|`g` and `G`|
|`KC_H`|`h` and `H`|
|`KC_I`|`i` and `I`|
|`KC_J`|`j` and `J`|
|`KC_K`|`k` and `K`|
|`KC_L`|`l` and `L`|
|`KC_M`|`m` and `M`|
|`KC_N`|`n` and `N`|
|`KC_O`|`o` and `O`|
|`KC_P`|`p` and `P`|
|`KC_Q`|`q` and `Q`|
|`KC_R`|`r` and `R`|
|`KC_S`|`s` and `S`|
|`KC_T`|`t` and `T`|
|`KC_U`|`u` and `U`|
|`KC_V`|`v` and `V`|
|`KC_W`|`w` and `W`|
|`KC_X`|`x` and `X`|
|`KC_Y`|`y` and `Y`|
|`KC_Z`|`z` and `Z`|
|`KC_1`|`1` and `!`|
|`KC_2`|`2` and `@`|
|`KC_3`|`3` and `#`|
|`KC_4`|`4` and `$`|
|`KC_5`|`5` and `%`|
|`KC_6`|`6` and `^`|
|`KC_7`|`7` and `&`|
|`KC_8`|`8` and `*`|
|`KC_9`|`9` and `(`|
|`KC_0`|`0` and `)`|

## F Keys

|Key     |Description|
|--------|-----------|
|`KC_F1` |           |
|`KC_F2` |           |
|`KC_F3` |           |
|`KC_F4` |           |
|`KC_F5` |           |
|`KC_F6` |           |
|`KC_F7` |           |
|`KC_F8` |           |
|`KC_F9` |           |
|`KC_F10`|           |
|`KC_F11`|           |
|`KC_F12`|           |
|`KC_F13`|           |
|`KC_F14`|           |
|`KC_F15`|           |
|`KC_F16`|           |
|`KC_F17`|           |
|`KC_F18`|           |
|`KC_F19`|           |
|`KC_F20`|           |
|`KC_F21`|           |
|`KC_F22`|           |
|`KC_F23`|           |
|`KC_F24`|           |

## Punctuation

|Key              |Aliases  |Description                       |
|-----------------|---------|----------------------------------|
|`KC_ENTER`       |`KC_ENT` |Return (Enter)                    |
|`KC_ESCAPE`      |`KC_ESC` |Escape                            |
|`KC_BSPACE`      |`KC_BSPC`|Delete (Backspace)                |
|`KC_TAB`         |         |Tab                               |
|`KC_SPACE`       |`KC_SPC` |Spacebar                          |
|`KC_MINUS`       |`KC_MINS`|`-` and `_`                       |
|`KC_EQUAL`       |`KC_EQL` |`=` and `+`                       |
|`KC_LBRACKET`    |`KC_LBRC`|`[` and `{`                       |
|`KC_RBRACKET`    |`KC_RBRC`|`]` and `}`                       |
|`KC_BSLASH`      |`KC_BSLS`|`\` and <code>&#124;</code>       |
|`KC_NONUS_HASH`  |`KC_NUHS`|Non-US `#` and `~`                |
|`KC_NONUS_BSLASH`|`KC_NUBS`|Non-US `\` and <code>&#124;</code>|
|`KC_INT1`        |`KC_RO`  |JIS `\` and <code>&#124;</code>   |
|`KC_INT2`        |`KC_KANA`|JIS Katakana/Hiragana             |
|`KC_INT3`        |`KC_JYEN`|JIS `¥`                           |
|`KC_SCOLON`      |`KC_SCLN`|`;` and `:`                       |
|`KC_QUOTE`       |`KC_QUOT`|`'` and `"`                       |
|`KC_GRAVE`       |`KC_GRV` |<code>&#96;</code> and `~`        |
|`KC_COMMA`       |`KC_COMM`|`,` and `<`                       |
|`KC_DOT`         |         |`.` and `>`                       |
|`KC_SLASH`       |`KC_SLSH`|`/` and `?`                       |
|`KC_CAPSLOCK`    |`KC_CAPS`|Caps Lock                         |

## Modifiers

|Key                |Aliases             |Description                         |
|-------------------|--------------------|------------------------------------|
|`KC_LCTRL`         |`KC_LCTL`           |Left Control                        |
|`KC_LSHIFT`        |`KC_LSFT`           |Left Shift                          |
|`KC_LALT`          |                    |Left Alt                            |
|`KC_LGUI`          |`KC_LCMD`, `KC_LWIN`|Left GUI (Windows/Command/Meta key) |
|`KC_RCTRL`         |`KC_RCTL`           |Right Control                       |
|`KC_RSHIFT`        |`KC_RSFT`           |Right Shift                         |
|`KC_RALT`          |                    |Right Alt                           |
|`KC_RGUI`          |`KC_RCMD`, `KC_RWIN`|Right GUI (Windows/Command/Meta key)|
|`KC_LOCKING_CAPS`  |`KC_LCAP`           |Locking Caps Lock                   |
|`KC_LOCKING_NUM`   |`KC_LNUM`           |Locking Num Lock                    |
|`KC_LOCKING_SCROLL`|`KC_LSCR`           |Locking Scroll Lock                 |
|`KC_INT4`          |`KC_HENK`           |JIS Henkan                          |
|`KC_INT5`          |`KC_MHEN`           |JIS Muhenkan                        |

## Commands

|Key               |Aliases  |Description                   |
|------------------|---------|------------------------------|
|`KC_PSCREEN`      |`KC_PSCR`|Print Screen                  |
|`KC_SCROLLLOCK`   |`KC_SLCK`|Scroll Lock                   |
|`KC_PAUSE`        |`KC_PAUS`|Pause                         |
|`KC_INSERT`       |`KC_INS` |Insert                        |
|`KC_HOME`         |         |Home                          |
|`KC_PGUP`         |         |Page Up                       |
|`KC_DELETE`       |`KC_DEL` |Forward Delete                |
|`KC_END`          |         |End                           |
|`KC_PGDOWN`       |`KC_PGDN`|Page Down                     |
|`KC_RIGHT`        |`KC_RGHT`|Right Arrow                   |
|`KC_LEFT`         |         |Left Arrow                    |
|`KC_DOWN`         |         |Down Arrow                    |
|`KC_UP`           |         |Up Arrow                      |
|`KC_APPLICATION`  |`KC_APP` |Application (Windows Menu Key)|
|`KC_POWER`        |         |Power                         |
|`KC_EXECUTE`      |         |Execute                       |
|`KC_HELP`         |         |Help                          |
|`KC_MENU`         |         |Menu                          |
|`KC_SELECT`       |         |Select                        |
|`KC_AGAIN`        |         |Again                         |
|`KC_UNDO`         |         |Undo                          |
|`KC_CUT`          |         |Cut                           |
|`KC_COPY`         |         |Copy                          |
|`KC_PASTE`        |         |Paste                         |
|`KC_FIND`         |         |Find                          |
|`KC_ALT_ERASE`    |         |Alternate Erase               |
|`KC_SYSREQ`       |         |SysReq/Attention              |
|`KC_CANCEL`       |         |Cancel                        |
|`KC_CLEAR`        |         |Clear                         |
|`KC_PRIOR`        |         |Prior                         |
|`KC_RETURN`       |         |Return                        |
|`KC_SEPARATOR`    |         |Separator                     |
|`KC_OUT`          |         |Out                           |
|`KC_OPER`         |         |Oper                          |
|`KC_CLEAR_AGAIN`  |         |Clear/Again                   |
|`KC_CRSEL`        |         |CrSel/Props                   |
|`KC_EXSEL`        |         |ExSel                         |

## Media Keys

These keycodes are not part of the Keyboard/Keypad usage page. The `SYSTEM_` keycodes are found in the Generic Desktop page, and the rest are located in the Consumer page.

Windows and macOS use different keycodes for "next track" and "previous track". Make sure you choose the keycode that corresponds to your OS.

|Key                    |Aliases  |Description                      |
|-----------------------|---------|---------------------------------|
|`KC_SYSTEM_POWER`      |`KC_PWR` |System Power Down                |
|`KC_SYSTEM_SLEEP`      |`KC_SLEP`|System Sleep                     |
|`KC_SYSTEM_WAKE`       |`KC_WAKE`|System Wake                      |
|`KC_MAIL`              |`KC_MAIL`|                                 |
|`KC_CALCULATOR`        |`KC_CALC`|                                 |
|`KC_MY_COMPUTER`       |`KC_MYCM`|                                 |
|`KC_WWW_SEARCH`        |`KC_WSCH`|                                 |
|`KC_WWW_HOME`          |`KC_WHOM`|                                 |
|`KC_WWW_BACK`          |`KC_WBAK`|                                 |
|`KC_WWW_FORWARD`       |`KC_WFWD`|                                 |
|`KC_WWW_STOP`          |`KC_WSTP`|                                 |
|`KC_WWW_REFRESH`       |`KC_WREF`|                                 |
|`KC_STOP`              |         |Stop                             |
|`KC_WWW_FAVORITES`     |`KC_WFAV`|                                 |
|`KC__MUTE`             |         |Mute (macOS)                     |
|`KC__VOLUP`            |         |Volume Up (macOS)                |
|`KC__VOLDOWN`          |         |Volume Down (macOS)              |
|`KC_AUDIO_MUTE`        |`KC_MUTE`|Mute (Windows/macOS/Linux)       |
|`KC_AUDIO_VOL_UP`      |`KC_VOLU`|Volume Up (Windows/macOS/Linux)  |
|`KC_AUDIO_VOL_DOWN`    |`KC_VOLD`|Volume Down (Windows/macOS/Linux)|
|`KC_MEDIA_NEXT_TRACK`  |`KC_MNXT`|Next Track (Windows)             |
|`KC_MEDIA_PREV_TRACK`  |`KC_MPRV`|Previous Track (Windows)         |
|`KC_MEDIA_FAST_FORWARD`|`KC_MFFD`|Next Track (macOS)               |
|`KC_MEDIA_REWIND`      |`KC_MRWD`|Previous Track (macOS)           |
|`KC_MEDIA_STOP`        |`KC_MSTP`|Stop Track                       |
|`KC_MEDIA_PLAY_PAUSE`  |`KC_MPLY`|Play/Pause Track                 |
|`KC_MEDIA_SELECT`      |`KC_MSEL`|                                 |

## Number Pad

|Key                |Aliases  |Description                   |
|-------------------|---------|------------------------------|
|`KC_NUMLOCK`       |`KC_NLCK`|Keypad Num Lock and Clear     |
|`KC_KP_SLASH`      |`KC_PSLS`|Keypad `/`                    |
|`KC_KP_ASTERISK`   |`KC_PAST`|Keypad `*`                    |
|`KC_KP_MINUS`      |`KC_PMNS`|Keypad `-`                    |
|`KC_KP_PLUS`       |`KC_PPLS`|Keypad `+`                    |
|`KC_KP_ENTER`      |`KC_PENT`|Keypad Enter                  |
|`KC_KP_1`          |`KC_P1`  |Keypad `1` and End            |
|`KC_KP_2`          |`KC_P2`  |Keypad `2` and Down Arrow     |
|`KC_KP_3`          |`KC_P3`  |Keypad `3` and Page Down      |
|`KC_KP_4`          |`KC_P4`  |Keypad `4` and Left Arrow     |
|`KC_KP_5`          |`KC_P5`  |Keypad `5`                    |
|`KC_KP_6`          |`KC_P6`  |Keypad `6` and Right Arrow    |
|`KC_KP_7`          |`KC_P7`  |Keypad `7` and Home           |
|`KC_KP_8`          |`KC_P8`  |Keypad `8` and Up Arrow       |
|`KC_KP_9`          |`KC_P9`  |Keypad `9` and Page Up        |
|`KC_KP_0`          |`KC_P0`  |Keypad `0` and Insert         |
|`KC_KP_DOT`        |`KC_PDOT`|Keypad `.` and Delete         |
|`KC_KP_EQUAL`      |`KC_PEQL`|Keypad `=`                    |
|`KC_KP_COMMA`      |`KC_PCMM`|Keypad `,`                    |
|`KC_KP_EQUAL_AS400`|         |Keypad `=` on AS/400 keyboards|

## Special Keys

In addition to these, keycodes in the range of `0xA5-DF` are reserved for internal use by TMK.

|Key             |Aliases  |Description                            |
|----------------|---------|---------------------------------------|
|`KC_NO`         |         |Ignore this key (NOOP)                 |
|`KC_TRANSPARENT`|`KC_TRNS`|Use the next lowest non-transparent key|
