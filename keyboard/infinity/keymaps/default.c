#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Bsp |
     * |-----------------------------------------------------------|
     * | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Enter  |
     * |-----------------------------------------------------------|
     * | Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn2|
     * |-----------------------------------------------------------'
     * |Ctrl |GUI|Alt  |         Space         |Alt  |GUI|Fn0|Ctrl |
     * `-----------------------------------------------------------'
     */
    [0] = KEYMAP(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN9,
    LCTL,LGUI,LALT,               SPC,                RALT,RGUI,FN0, RCTL
    ),

    /* QWERTY */
    [1] = KEYMAP(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,
    FN1, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,FN2,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN9,
    LCTL,LGUI,LALT,               FN3,                RALT,RGUI,FN0, RCTL
    ),

    /* Colemak */
    [2] = KEYMAP(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,
    FN1, Q,   W,   F,   P,   G,   J,   L,   U,   Y,   SCLN,LBRC,RBRC,BSPC,
    CAPS,A,   R,   S,   T,   D,   H,   N,   E,   I,   O,   QUOT,FN2,
    LSFT,Z,   X,   C,   V,   B,   K,   M,   COMM,DOT, SLSH,RSFT,FN9,
    LCTL,LGUI,LALT,               FN3,                RALT,RGUI,FN0, RCTL
    ),

    /* Dvorak */
    [3] = KEYMAP(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   LBRC,RBRC,BSLS,GRV,
    FN1, QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, BSPC,
    CAPS,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,FN2,
    LSFT,SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z,   RSFT,FN9,
    LCTL,LGUI,LALT,               FN3,                RALT,RGUI,FN0, RCTL
    ),

    /* Workman */
    [4] = KEYMAP(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,
    FN1, Q,   D,   R,   W,   B,   J,   F,   U,   P,   SCLN,LBRC,RBRC,BSPC,
    CAPS,A,   S,   H,   T,   G,   Y,   N,   E,   O,   I,   QUOT,FN2,
    LSFT,Z,   X,   M,   C,   V,   K,   L,   COMM,DOT, SLSH,RSFT,FN9,
    LCTL,LGUI,LALT,               FN3,                RALT,RGUI,FN0, RCTL
    ),

    /**
     * Gamer Layout
     *
     * A winkeyless QWERTY layout with tap layers disabled
     */
    [5] = KEYMAP(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,
    FN1, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,FN9,
    LCTL,NO,  LALT,               SPC,                RALT,NO,  FN0, RCTL
    ),

    /* HHKB mode (HHKB Fn)
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |Ins|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   | Del |
     * |-----------------------------------------------------------|
     * |Ctrl  |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig| Enter  |
     * |-----------------------------------------------------------|
     * |Shift   |   |   |   |   |   |  +|  -|End|PgD|Dow|Shift |   |
     * `-----------------------------------------------------------'
     * |Ctrl |GUI|Alt  |         Space         |Alt  |GUI|Fn0|Ctrl |
     * `-----------------------------------------------------------'
     */ 
    [6] = KEYMAP(
    PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  INS,
    CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,UP,  NO,  DEL,
    TRNS,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,TRNS,
    TRNS,NO,  NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,TRNS,TRNS,
    TRNS,TRNS,TRNS,               TRNS,               TRNS,TRNS,TRNS,TRNS
    ),

    [7] = KEYMAP(
    NO,  FN4, FN5, FN6, FN7, FN8, FN10,NO,  NO,  NO,  FN10,NO,  NO,  NO,  NO,
    TRNS,FN4, FN7, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  FN6, NO,  FN8, NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  FN5, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,                 NO,                 NO,  NO,  TRNS,NO
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
    [8] = KEYMAP(
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    TRNS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,       NO,
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,            NO,  NO,
    NO,  NO,  NO,                 NO,                      NO,  NO,  TRNS,NO
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
    [9]  = ACTION_LAYER_MOMENTARY(6),                  // HHKB layer
};
