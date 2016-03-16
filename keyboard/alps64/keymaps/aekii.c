#include "keymap_common.h"
#include "macro.c"
#include "function.c"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  Bsp  |
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
     * |-----------------------------------------------------------|
     * | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter  |
     * |-----------------------------------------------------------|
     * | Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift   |
     * |-----------------------------------------------------------|
     * |Ctrl |Alt |GUI  |         Space           |GUI  |Alt |Ctrl |
     * `-----------------------------------------------------------'
     */
    [0] = KEYMAP_AEK(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,
    LCTL,LALT,LGUI,               SPC,                     FN16, RALT,RCTL
    ),

    /* Dvorak */
    [1] = KEYMAP_AEK(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,TRNS,
    TRNS,QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, TRNS,
    TRNS,TRNS,O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,TRNS,
    TRNS,SCLN,Q,   J,   K,   X,   B,   TRNS,W,   V,   Z,   TRNS,
    TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS
    ),

    /* Colemak */
    [2] = KEYMAP_AEK(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,F,   P,   G,   J,   L,   U,   Y,   SCLN,TRNS,TRNS,TRNS,
    TRNS,TRNS,R,   S,   T,   D,   TRNS,N,   E,   I,   O,   TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,K,   TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS
    ),

    /* HHKB function layer
     * ,-----------------------------------------------------------.
     * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   | Ins |
     * |-----------------------------------------------------------|
     * |Ctrl  |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig| Enter  |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |   |  +|  -|End|PgD|Dow| Shift    |
     * |-----------------------------------------------------------|
     * |Ctrl |Alt |GUI  |       Space             |Fn   |Alt |Ctrl |
     * `-----------------------------------------------------------'
     */
    [8] = KEYMAP_AEK(
    GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,
    CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,UP,  NO,  INS,
    TRNS,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,TRNS,
    TRNS,FN20,NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,TRNS,
    TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS
    ),

    /* SpaceFn & EnterFn */
    [24] = KEYMAP_AEK(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN9,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,               FN8,                     TRNS,TRNS,TRNS
    ),

    /* Keymap settings layer */
    [30] = KEYMAP_AEK(
    NO,  FN1, FN2, NO,  NO,  NO,  NO,  NO,  NO,  NO,  FN0, NO,  NO,  NO,
    NO,  FN0, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  FN1, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  FN17,
    NO,  NO,  NO,  FN2, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,                 FN17,                    TRNS,NO,  NO
    ),

    /* Primary Fn Layer */
    [31] = KEYMAP_AEK(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,               TRNS,                    FN16,TRNS,TRNS
    ),
};



/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_DEFAULT_LAYER_SET(0),             // QWERTY layout
    [1]  = ACTION_DEFAULT_LAYER_SET(1),             // Dvorak layout
    [2]  = ACTION_DEFAULT_LAYER_SET(2),             // Colemak layout

    [8]  = ACTION_LAYER_TAP_KEY(8, KC_SPC),         // HHKB function layer
    [9]  = ACTION_LAYER_TAP_KEY(8, KC_ENTER),       // HHKB function layer

    [16] = ACTION_LAYER_TAP_KEY(30, KC_RGUI),       // Keymap settings layer
    [17] = ACTION_LAYER_TOGGLE(24),                 // Toggle SpaceFn & EnterFn

    [20] = ACTION_MACRO(SIGNATURE),                 // Forum auto-signature
};
