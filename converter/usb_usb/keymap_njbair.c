#include "keymap_common.h"

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  Bsp  |
     * |-----------------------------------------------------------|
     * |Fn1  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
     * |-----------------------------------------------------------|
     * | Caps |  A|  S|  D|  F|  G|  H|  J|  K|  L| ; | ' |  Fn2   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .| / |  Shift   |
     * |-----------------------------------------------------------'
     * |Ctrl|GUI |Alt |         Fn3            |Alt |GUI |Fn0 |Ctrl|
     * `-----------------------------------------------------------'
     */

    /*
     * QWERTY Layout
     */
    [0] = \
    KEYMAP(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,BRK,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    FN1, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL, END, PGDN,    P7,  P8,  P9,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     FN2,                         P4,  P5,  P6,  PPLS,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,          UP,           P1,  P2,  P3,
    LCTL,LGUI,LALT,          FN3,                     RALT,RGUI,FN0, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT
    ),

    /*
     * Colemak Layout
     */
    [1] = \
    KEYMAP(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,BRK,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    FN1, Q,   W,   F,   P,   G,   J,   L,   U,   Y,   SCLN,LBRC,RBRC,BSLS,     DEL, END, PGDN,    P7,  P8,  P9,
    CAPS,A,   R,   S,   T,   D,   H,   N,   E,   I,   O,   QUOT,     FN2,                         P4,  P5,  P6,  PPLS,
    LSFT,Z,   X,   C,   V,   B,   K,   M,   COMM,DOT, SLSH,          RSFT,          UP,           P1,  P2,  P3,
    LCTL,LGUI,LALT,          FN3,                     RALT,RGUI,FN0, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT
    ),

    /*
     * Dvorak Layout
     */
    [2] = \
    KEYMAP(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,BRK,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   LBRC,RBRC,BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    FN1, QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, BSLS,     DEL, END, PGDN,    P7,  P8,  P9,
    CAPS,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,     FN2,                         P4,  P5,  P6,  PPLS,
    LSFT,SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z,             RSFT,          UP,           P1,  P2,  P3,
    LCTL,LGUI,LALT,          FN3,                     RALT,RGUI,FN0, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT
    ),

    /*
     * Workman Layout
     */
    [3] = \
    KEYMAP(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,BRK,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    FN1, Q,   D,   R,   W,   B,   J,   F,   U,   P,   SCLN,LBRC,RBRC,BSLS,     DEL, END, PGDN,    P7,  P8,  P9,
    CAPS,A,   S,   H,   T,   G,   Y,   N,   E,   O,   I,   QUOT,     FN2,                         P4,  P5,  P6,  PPLS,
    LSFT,Z,   X,   M,   C,   V,   K,   L,   COMM,DOT, SLSH,          RSFT,          UP,           P1,  P2,  P3,
    LCTL,LGUI,LALT,          FN3,                     RALT,RGUI,FN0, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT
    ),

    /*
     * Gamer Layout
     *
     * A winkeyless QWERTY layout with tap layers disabled
     */
    [4] = \
    KEYMAP(
    ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,           PSCR,SLCK,BRK,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,
    FN1, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,     DEL, END, PGDN,    P7,  P8,  P9,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,                         P4,  P5,  P6,  PPLS,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,          RSFT,          UP,           P1,  P2,  P3,
    LCTL,NO,  LALT,          SPC,                     RALT,NO,  FN0, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT
    ),

    /*
     * HHKB Function Layer
     */
    [5] = \
    KEYMAP(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,          TRNS,TRNS,TRNS,
    NO,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,TRNS,
    CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,UP,  NO,  INS,      TRNS,TRNS,TRNS,    TRNS,TRNS,TRNS,
    TRNS,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,     TRNS,                        TRNS,TRNS,TRNS,TRNS,
    TRNS,NO,  NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,          TRNS,          TRNS,         TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,NO,  TRNS,     TRNS,TRNS,TRNS,    TRNS,     TRNS,TRNS
    ),

    /*
     * Layout switching layer
     */
    [6] = \
    KEYMAP(
    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,            NO,  NO,  NO,
    NO,  FN4, FN5, FN6, FN7, FN8, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,       NO,  NO,  NO,      NO,  NO,  NO,  NO,
    TRNS,FN4, FN7, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,       NO,  NO,  NO,      NO,  NO,  NO,
    NO,  NO,  NO,  FN6, NO,  FN8, NO,  NO,  NO,  NO,  NO,  NO,       NO,                          NO,  NO,  NO,  NO,
    NO,  NO,  NO,  FN5, NO,  NO,  NO,  NO,  NO,  NO,  NO,            NO,            NO,           NO,  NO,  NO,
    NO,  NO,  NO,            NO,                      NO,  NO,  TRNS,NO,       NO,  NO,  NO,      NO,       NO,  NO
    ),
};



/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const uint16_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const uint16_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_LAYER_MOMENTARY(6),                // Layout selection layer
    [1] = ACTION_LAYER_TAP_KEY(6, KC_TAB),          // Layout selection layer
    [2] = ACTION_LAYER_TAP_KEY(5, KC_ENTER),        // HHKB layer
    [3] = ACTION_LAYER_TAP_KEY(5, KC_SPC),          // HHKB layer
    [4] = ACTION_DEFAULT_LAYER_SET(0),              // QWERTY layout
    [5] = ACTION_DEFAULT_LAYER_SET(1),              // Colemak layout
    [6] = ACTION_DEFAULT_LAYER_SET(2),              // Dvorak layout
    [7] = ACTION_DEFAULT_LAYER_SET(3),              // Workman layout
    [8] = ACTION_DEFAULT_LAYER_SET(4),              // Gamer layout
};
