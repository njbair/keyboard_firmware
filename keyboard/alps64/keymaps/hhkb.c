#include "keymap_common.h"
#include "macro.c"
#include "function.c"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /**
     * Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Bsp |
     * |-----------------------------------------------------------|
     * | Ctrl |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter  |
     * |-----------------------------------------------------------|
     * | Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn2|
     * `-----------------------------------------------------------'
     *       |GUI|Alt  |         Space         |Alt  |Fn0|
     *       `-------------------------------------------'
     */
    [0] = KEYMAP_HHKB(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,
    LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,NO,
         LGUI,LALT,               SPC,           RALT,NO
    ),

    /* Dvorak */
    [1] = KEYMAP_HHKB(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,TRNS,TRNS,
    TRNS,QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, TRNS,
    TRNS,TRNS,O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,TRNS,
    TRNS,SCLN,Q,   J,   K,   X,   B,   TRNS,W,   V,   Z,   TRNS,TRNS,
         TRNS,TRNS,               TRNS,          TRNS,TRNS
    ),

    /* Colemak */
    [2] = KEYMAP_HHKB(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,F,   P,   G,   J,   L,   U,   Y,   SCLN,TRNS,TRNS,TRNS,
    TRNS,TRNS,R,   S,   T,   D,   TRNS,N,   E,   I,   O,   TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,K,   TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
         TRNS,TRNS,               TRNS,          TRNS,TRNS
    ),

    /**
     * HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Esc| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |Ins|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   | Del |
     * |-----------------------------------------------------------|
     * |Ctrl  |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig| Enter  |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |   |  +|  -|End|PgD|Dow|Shift |   |
     * `-----------------------------------------------------------'
     *       |GUI|Alt  |        Space          |Alt  |Fn0|
     *       `-------------------------------------------'
     */
    [3] = KEYMAP_HHKB(
    TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  INS,
    CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,UP,  NO,  DEL,
    TRNS,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,TRNS,
    TRNS,FN8, NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,TRNS,TRNS,
         TRNS,TRNS,               TRNS,          TRNS,TRNS
    ),

    /* SpaceFn & EnterFn */
    [4] = KEYMAP_HHKB(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN4,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
         TRNS,TRNS,               FN3,           TRNS,TRNS
    ),

    /* Keymap settings layer */
    [5] = KEYMAP_HHKB(
    NO,  FN1, FN2, NO,  NO,  NO,  NO,  NO,  NO,  NO,  FN0, NO,  NO,  NO,  NO,
    NO,  FN0, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  FN1, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  FN7,
    NO,  NO,  NO,  FN2, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
         NO,  NO,                 FN7,           NO,  NO
    ),

    /* Primary Fn Layer */
    [6] = KEYMAP_HHKB(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN5,
         TRNS,TRNS,               TRNS,          TRNS,FN6
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
    [5]  = ACTION_LAYER_MOMENTARY(3),               // HHKB function layer

    [6]  = ACTION_LAYER_TAP_KEY(5, KC_APP),         // Keymap settings layer
    [7]  = ACTION_LAYER_TOGGLE(4),                  // Toggle SpaceFn & EnterFn

    [8]  = ACTION_MACRO(SIGNATURE),                 // Forum auto-signature
};
