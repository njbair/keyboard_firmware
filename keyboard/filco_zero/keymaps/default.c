#include "keymap_common.h"
#include "macro.c"
#include "function.c"

const uint8_t PROGMEM keymaps[][MATRIX_COLS][MATRIX_ROWS] = {
    /**
     * Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  Bsp  |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
     * |-----------------------------------------------------------|
     * | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter  |
     * |-----------------------------------------------------------|
     * | Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift   |
     * |-----------------------------------------------------------|
     * |Ctrl|GUI |Alt |         Space          |Alt |GUI |Fn0 |Ctrl|
     * `-----------------------------------------------------------'
     */
    [0] = KEYMAP_ANSI(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,         PSCR,SLCK,PAUS,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,   INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,   DEL, END, PGDN,    P7,  P8,  P9,  PPLS,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,                            P4,  P5,  P6,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,             UP,           P1,  P2,  P3,  PENT,
    LCTL,LGUI,LALT,               SPC,                RALT,RGUI,FN0, RCTL,   LEFT,DOWN,RGHT,    P0,  PDOT
    ),

    /* Dvorak */
    [1] = KEYMAP_ANSI(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,TRNS,                           TRNS,TRNS,TRNS,
    TRNS,SCLN,Q,   J,   K,   X,   B,   TRNS,W,   V,   Z,   TRNS,                  TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS
    ),

    /* Colemak */
    [2] = KEYMAP_ANSI(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,F,   P,   G,   J,   L,   U,   Y,   SCLN,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,R,   S,   T,   D,   TRNS,N,   E,   I,   O,   TRNS,TRNS,                           TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,K,   TRNS,TRNS,TRNS,TRNS,TRNS,                  TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS
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
     * |Ctrl|GUI |Alt |       Space            |Alt |GUI |Fn0 |Ctrl|
     * `-----------------------------------------------------------'
     */ 
    [3] = KEYMAP_ANSI(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,         PSCR,SLCK,PAUS,
    GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,    INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,UP,  NO,  INS,    DEL, END, PGDN,    P7,  P8,  P9,  PPLS,
    TRNS,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,TRNS,                           P4,  P5,  P6,
    TRNS,FN20,NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,TRNS,                  UP,           P1,  P2,  P3,  PENT,
    TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS,   LEFT,DOWN,RGHT,    P0,  PDOT
    ),

    /* SpaceFn & EnterFn */
    [4] = KEYMAP_ANSI(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN4,                            TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                  TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,               FN3,                TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS
    ),

    /* Keymap settings layer */
    [5] = KEYMAP_ANSI(
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,          NO,  NO,  NO,
    NO,  FN1, FN2, NO,  NO,  NO,  NO,  NO,  NO,  NO,  FN0, NO,  NO,  NO,     NO,  NO,  NO,      NO,  NO,  NO,  NO,
    NO,  FN0, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,     NO,  NO,  NO,      NO,  NO,  NO,  NO,
    NO,  NO,  NO,  FN1, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  FN7,                            NO,  NO,  NO,
    NO,  NO,  NO,  FN2, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,                    NO,           NO,  NO,  NO,  NO,
    NO,  NO,  NO,                 FN7,                NO,  NO,  NO,  NO,     NO,  NO,  NO,      NO,  NO
    ),

    /* Primary Fn Layer */
    [6] = KEYMAP_ANSI(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,        TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                           TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,                  TRNS,         TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,FN6, TRNS,   TRNS,TRNS,TRNS,    TRNS,TRNS
    ),
};



/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_DEFAULT_LAYER_SET(0),             // QWERTY layout
    [1]  = ACTION_DEFAULT_LAYER_SET(1),             // Dvorak layout
    [2]  = ACTION_DEFAULT_LAYER_SET(2),             // Colemak layout

    [3]  = ACTION_LAYER_TAP_KEY(3, KC_SPC),         // HHKB function layer
    [4]  = ACTION_LAYER_TAP_KEY(3, KC_ENTER),       // HHKB function layer

    [6]  = ACTION_LAYER_TAP_KEY(5, KC_APP),         // Keymap settings layer
    [7]  = ACTION_LAYER_TOGGLE(4),                  // Toggle SpaceFn & EnterFn

    [8]  = ACTION_MACRO(SIGNATURE),                 // Forum auto-signature
};
