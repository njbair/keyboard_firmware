#include "keymap_common.h"
#include "macro.c"
#include "function.c"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /**
     * Default Layer
     * ,---------------------------------------------------------------------------.
     * |Nlk| = | / | * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  Bsp  |
     * |---|---|---|---|-----------------------------------------------------------|
     * | 7 | 8 | 9 | - | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
     * |---|---|---|---|-----------------------------------------------------------|
     * | 4 | 5 | 6 | + | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter  |
     * |---|---|---|---|-----------------------------------------------------------|
     * | 1 | 2 | 3 |   | Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|  Shift   |
     * |-------|---|Ent|-----------------------------------------------------------|
     * |   0   | . |   |Ctrl |Alt |GUI  |         Space           |GUI  |Alt |Ctrl |
     * `---------------------------------------------------------------------------'
     */
    [0] = KEYMAP(
    NLCK,PEQL,PSLS,PAST,     ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,
    P7,  P8,  P9,  PMNS,     TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,
    P4,  P5,  P6,  PPLS,     CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,
    P1,  P2,  P3,  PENT,     LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,
    P0,       PDOT,          LCTL,LALT,LGUI,               SPC,                     FN16, RALT,RCTL
    ),

    /* Dvorak */
    [1] = KEYMAP(
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,SCLN,Q,   J,   K,   X,   B,   TRNS,W,   V,   Z,   TRNS,
    TRNS,     TRNS,          TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS
    ),

    /* Colemak */
    [2] = KEYMAP(
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,F,   P,   G,   J,   L,   U,   Y,   SCLN,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,R,   S,   T,   D,   TRNS,N,   E,   I,   O,   TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,K,   TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,          TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS
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
     * |Ctrl |Alt |GUI  |       Space             |Fn   |Alt |Ctrl |
     * `-----------------------------------------------------------'
     */
    [8] = KEYMAP(
    TRNS,TRNS,TRNS,TRNS,     GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,
    TRNS,TRNS,TRNS,TRNS,     CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,UP,  NO,  INS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,FN20,NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,TRNS,
    TRNS,     TRNS,          TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS
    ),

    /* SpaceFn & EnterFn */
    [24] = KEYMAP(
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN9,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,          TRNS,TRNS,TRNS,               FN8,                     TRNS,TRNS,TRNS
    ),

    /* Keymap settings layer */
    [30] = KEYMAP(
    TRNS,TRNS,TRNS,TRNS,     NO,  FN1, FN2, NO,  NO,  NO,  NO,  NO,  NO,  NO,  FN0, NO,  NO,  NO,
    TRNS,TRNS,TRNS,TRNS,     NO,  FN0, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    TRNS,TRNS,TRNS,TRNS,     NO,  NO,  NO,  FN1, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  FN17,
    TRNS,TRNS,TRNS,TRNS,     NO,  NO,  NO,  FN2, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    TRNS,     TRNS,          NO,  NO,  NO,                 FN17,                    TRNS,NO,  NO
    ),

    /* Primary Fn layer */
    [31] = KEYMAP(
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    FN24,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,          TRNS,TRNS,TRNS,               TRNS,                    FN16,TRNS,TRNS
    ),

    /* Keypad gaming layer */
    [16] = KEYMAP(
    1,   2,   3,   4,        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    Q,   W,   E,   R,        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    A,   S,   D,   F,        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    Z,   X,   C,   SPC,      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    NO,       NO,            TRNS,TRNS,TRNS,               TRNS,                    TRNS,TRNS,TRNS
    ),
};



/**
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

    [24] = ACTION_LAYER_TOGGLE(16)                  // Keypad gaming layer
};
