#include "keymap_common.h"
#include "macro.c"
#include "function.c"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /**
     * IBM M-122 / Unicomp PC-122
     *
     *                 ,-----------------------------------------------.
     *                 |F13|F14|F15|F16|F17|F18|F19|F20|F21|F22|F23|F24|
     *                 |-----------------------------------------------|
     *                 |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|
     *                 `-----------------------------------------------'
     * ,----,----. ,-----------------------------------------------------------. ,-----------. ,---------------.
     * | M1 | M2 | |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Bsp    | |Ins|Hom|PgU| |NmL|  /|  *|  -|
     * |----|----| |-----------------------------------------------------------| |-----------| |---------------|
     * | M3 | M4 | |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|    \| |Del|End|PgD| |  7|  8|  9|   |
     * |----|----| |-----------------------------------------------------------| `-----------' |-----------|  +|
     * | M5 | M6 | |CapsLo|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |     |Up |     |  4|  5|  6|   |
     * |----|----| |-----------------------------------------------------------| ,-----------. |---------------|
     * | M7 | M8 | |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     | |Lef|   |Rig| |  1|  2|  3|   |
     * |----|----| |-----------------------------------------------------------| `-----------' |-----------|Ent|
     * | M9 | M0 | |Ctrl |   | Alt |         Space             | Alt |   |Ctrl |     |Dow|     |      0|  .|   |
     * `----`----' `-----'   `---------------------------------------'   `-----'     `---'     `---------------'
     */
    [0] = KEYMAP(
              WBAK,WFWD,WHOM,MPLY,MPRV,MNXT,MSTP,VOLD,VOLU,PSCR,SLCK,PAUS,
              F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,
    FN20,GRV, ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    FN21,LGUI,TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL, END, PGDN,    P7,  P8,  P9,
    FN22,RGUI,CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,                UP,           P4,  P5,  P6,  PPLS,
    FN23,APP, LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,               LEFT,NO,  RGHT,    P1,  P2,  P3,
    FN24,FN25,LCTL,     LALT,               SPC,                RALT,     RCTL,               DOWN,         P0,       PDOT,PENT
    ),

    /* Dvorak */
    [1] = KEYMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,TRNS,               TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,SCLN,Q,   J,   K,   X,   B,   TRNS,W,   V,   Z,   TRNS,               TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,     TRNS,               TRNS,               TRNS,     TRNS,               TRNS,         TRNS,     TRNS,TRNS
    ),

    /* Colemak */
    [2] = KEYMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,F,   P,   G,   J,   L,   U,   Y,   SCLN,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,R,   S,   T,   D,   TRNS,N,   E,   I,   O,   TRNS,TRNS,               TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,K,   TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,     TRNS,               TRNS,               TRNS,     TRNS,               TRNS,         TRNS,     TRNS,TRNS
    ),

    /**
     * HHKB function layer
     * ,-----------------------------------------------------------.
     * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   | Ins |
     * |-----------------------------------------------------------|
     * |Ctrl  |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig| Enter  |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |   |  +|  -|End|PgD|Dow| Shift    |
     * |-----------------------------------------------------------|
     * |Ctrl|GUI |Alt |       Space            |Alt |GUI |Fn  |Ctrl|
     * `-----------------------------------------------------------'
     */
    [8] = KEYMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,UP,  NO,  INS,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,TRNS,               TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,FN20,NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,TRNS,               TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,     TRNS,               TRNS,               TRNS,     TRNS,               TRNS,         TRNS,     TRNS,TRNS
    ),

    /**
     * Default keyswaps
     *
     * The converter doesn't have Boot Magic (boo!) so instead we need to change
     * some options manually.
     */
    [16] = KEYMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,LCTL,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,CAPS,     TRNS,               TRNS,               TRNS,     TRNS,               TRNS,         TRNS,     TRNS,TRNS
    ),

    /* SpaceFn & EnterFn */
    [24] = KEYMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN9,                TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,     TRNS,               FN8,                TRNS,     TRNS,               TRNS,         TRNS,     TRNS,TRNS
    ),

    /* Keymap settings layer */
    [30] = KEYMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,FN1, FN2, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN0, TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,FN0, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,FN1, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN17,               TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,FN2, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,     TRNS,               FN17,               TRNS,     TRNS,               TRNS,         TRNS,     TRNS,TRNS
    ),

    /* Primary Fn layer */
    [31] = KEYMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,               TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,     TRNS,               TRNS,               FN16,     TRNS,               TRNS,         TRNS,     TRNS,TRNS
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_DEFAULT_LAYER_SET(0),             // QWERTY layout
    [1]  = ACTION_DEFAULT_LAYER_SET(1),             // Dvorak layout
    [2]  = ACTION_DEFAULT_LAYER_SET(2),             // Colemak layout

    [8]  = ACTION_LAYER_TAP_KEY(8, KC_SPC),         // HHKB function layer
    [9]  = ACTION_LAYER_TAP_KEY(8, KC_ENTER),       // HHKB function layer

    [16] = ACTION_LAYER_MOMENTARY(30),              // Keymap settings layer
    [17] = ACTION_LAYER_TOGGLE(24),                 // Toggle SpaceFn & EnterFn

    [20] = ACTION_MACRO(SIGNATURE),                 // Forum auto-signature
    [21] = ACTION_FUNCTION(LED_DANCE),              // Make the LEDs do a dance
};
