#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* Default Layer (QWERTY)
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Fn1  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Bsp |
     * |-----------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Fn3   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn2|
     * `-----------------------------------------------------------'
     *       |GUI|Alt  |          Fn4          |Alt  |Fn0|
     *       `-------------------------------------------'
     */
    [0] = KEYMAP_HHKB(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, GRV,
    FN1, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,
    LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,FN3,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT, FN2,
         LGUI,LALT,               FN4,                     RALT,FN0
    ),

    /* Colemak */
    [1] = KEYMAP_HHKB(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, GRV,
    FN1, Q,   W,   F,   P,   G,   J,   L,   U,   Y,   SCLN,LBRC,RBRC,BSPC,
    LCTL,A,   R,   S,   T,   D,   H,   N,   E,   I,   O,   QUOT,FN3,
    LSFT,Z,   X,   C,   V,   B,   K,   M,   COMM,DOT, SLSH,RSFT, FN2,
         LGUI,LALT,               FN4,                     RALT,FN0
    ),

    /* Dvorak */
    [2] = KEYMAP_HHKB(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   LBRC,RBRC,BSLS, GRV,
    FN1, QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, BSPC,
    LCTL,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,FN3,
    LSFT,SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z,   RSFT, FN2,
         LGUI,LALT,               FN4,                     RALT,FN0
    ),

    /* Workman */
    [3] = KEYMAP_HHKB(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, GRV,
    FN1, Q,   D,   R,   W,   B,   J,   F,   U,   P,   SCLN,LBRC,RBRC,BSPC,
    LCTL,A,   S,   H,   T,   G,   Y,   N,   E,   O,   I,   QUOT,FN3,
    LSFT,Z,   X,   M,   C,   V,   K,   L,   COMM,DOT, SLSH,RSFT, FN2,
         LGUI,LALT,               FN4,                     RALT,FN0
    ),

    /**
     * Gamer Layout
     *
     * A winkeyless QWERTY layout with tap layers disabled
     */
    [4] = KEYMAP_HHKB(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, GRV,
    FN1, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,
    LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT, FN2,
         NO,  LALT,               SPC,                     RALT,FN0
    ),

    /*
     * The empty layer
     *
     * I have kids. Kids like to press buttons. So I set my keyboard to default
     * to an empty layout. That way kids can press buttons all day and not mess
     * up my computer.
     *
     * I use virtual DIP switch settings to set the keyboard to start on this
     * layout. So even if the computer reboots or the keyboard gets unplugged,
     * it's still a blank slate until I switch to one of the other layouts.
     */
    [5] = KEYMAP_HHKB(
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    TRNS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
         NO,  NO,                 NO,                      NO,  TRNS
    ),

    /* HHKB mode (HHKB Fn)
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
    [6] = KEYMAP_HHKB(
    TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  INS,
    CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,UP,  NO,  DEL,
    TRNS,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,TRNS,
    TRNS,NO,  NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,TRNS,TRNS,
         TRNS,TRNS,               TRNS,                    TRNS,TRNS
    ),

    [7] = KEYMAP_HHKB(
    NO,  FN5, FN6, FN7, FN8, FN9, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    TRNS,FN5, FN8, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  FN7, NO,  FN9, NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  FN6, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
         NO,  NO,                 NO,                      NO,  TRNS
    )
};



/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_LAYER_MOMENTARY(7),                 // Layout selection layer
    [1]  = ACTION_LAYER_TAP_KEY(7, KC_TAB),           // Layout selection layer
    [2]  = ACTION_LAYER_MOMENTARY(6),                 // HHKB layer
    [3]  = ACTION_LAYER_TAP_KEY(6, KC_ENT),           // HHKB layer
    [4]  = ACTION_LAYER_TAP_KEY(6, KC_SPC),           // HHKB layer
    [5]  = ACTION_DEFAULT_LAYER_SET(0),               // QWERTY layout
    [6]  = ACTION_DEFAULT_LAYER_SET(1),               // Colemak layout
    [7]  = ACTION_DEFAULT_LAYER_SET(2),               // Dvorak layout
    [8]  = ACTION_DEFAULT_LAYER_SET(3),               // Workman layout
    [9]  = ACTION_DEFAULT_LAYER_SET(4),               // Gamer layout
    [10] = ACTION_DEFAULT_LAYER_SET(5),               // Empty layout
};
