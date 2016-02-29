#include "keymap_common.h"

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
     * |Ctrl|GUI |Alt |         Space          |Alt |GUI |Fn0 |Ctrl|
     * `-----------------------------------------------------------'
     */
    [0] = KEYMAP_ANSI(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,
    LCTL,LGUI,LALT,               SPC,                RALT,RGUI,FN0, RCTL
    ),

    /* QWERTY */
    [1] = KEYMAP_ANSI(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,
    FN1, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,FN2,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,
    LCTL,LGUI,LALT,               FN3,                RALT,RGUI,FN0, RCTL
    ),

    /* Colemak */
    [2] = KEYMAP_ANSI(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,
    FN1, Q,   W,   F,   P,   G,   J,   L,   U,   Y,   SCLN,LBRC,RBRC,BSLS,
    CAPS,A,   R,   S,   T,   D,   H,   N,   E,   I,   O,   QUOT,FN2,
    LSFT,Z,   X,   C,   V,   B,   K,   M,   COMM,DOT, SLSH,RSFT,
    LCTL,LGUI,LALT,               FN3,                RALT,RGUI,FN0, RCTL
    ),

    /* Dvorak */
    [3] = KEYMAP_ANSI(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   LBRC,RBRC,BSPC,
    FN1, QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, BSLS,
    CAPS,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,FN2,
    LSFT,SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z,   RSFT,
    LCTL,LGUI,LALT,               FN3,                RALT,RGUI,FN0, RCTL
    ),

    /* Workman */
    [4] = KEYMAP_ANSI(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,
    FN1, Q,   D,   R,   W,   B,   J,   F,   U,   P,   SCLN,LBRC,RBRC,BSLS,
    CAPS,A,   S,   H,   T,   G,   Y,   N,   E,   O,   I,   QUOT,FN2,
    LSFT,Z,   X,   M,   C,   V,   K,   L,   COMM,DOT, SLSH,RSFT,
    LCTL,LGUI,LALT,               FN3,                RALT,RGUI,FN0, RCTL
    ),

    /**
     * Gamer Layout
     *
     * A winkeyless QWERTY layout with tap layers disabled
     */
    [5] = KEYMAP_ANSI(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,
    LCTL,NO,  LALT,               SPC,                RALT,NO,  FN0, RCTL
    ),

    /* HHKB mode (HHKB Fn)
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
    [6] = KEYMAP_ANSI(
    GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,
    CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,UP,  NO,  INS,
    TRNS,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,TRNS,
    TRNS,NO,  NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,TRNS,
    TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS
    ),

    /* Layout selection layer */
    [7] = KEYMAP_ANSI(
    NO,  FN4, FN5, FN6, FN7, FN8, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    TRNS,FN4, FN7, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  FN6, NO,  FN8, NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  FN5, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,                 NO,                 NO,  NO,  TRNS,NO
    )
};



/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_TAP_KEY(7, KC_APP),            // Layout selection layer
    [1]  = ACTION_LAYER_TAP_KEY(7, KC_TAB),            // Layout selection layer
    [2]  = ACTION_LAYER_TAP_KEY(6, KC_ENTER),          // HHKB layer
    [3]  = ACTION_LAYER_TAP_KEY(6, KC_SPC),            // HHKB layer
    [4]  = ACTION_DEFAULT_LAYER_SET(1),                // QWERTY layout
    [5]  = ACTION_DEFAULT_LAYER_SET(2),                // Colemak layout
    [6]  = ACTION_DEFAULT_LAYER_SET(3),                // Dvorak layout
    [7]  = ACTION_DEFAULT_LAYER_SET(4),                // Workman layout
    [8]  = ACTION_DEFAULT_LAYER_SET(5),                // Gamer layout
};
