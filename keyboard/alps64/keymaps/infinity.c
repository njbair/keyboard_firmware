#include "keymap_common.h"
#include "layer.h"
#include "macro.h"
#include "function.h"
#include "init.h"

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
    [L_QWERTY] = KEYMAP_INFINITY(
    ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS,GRV,
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,
    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,
    LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,NO,
    LCTL,LGUI,LALT,               SPC,           RALT,RGUI,APP, RCTL
    ),

    /* Dvorak */
    [L_DVORAK] = KEYMAP_INFINITY(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,TRNS,TRNS,
    TRNS,QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, TRNS,
    TRNS,TRNS,O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,TRNS,
    TRNS,SCLN,Q,   J,   K,   X,   B,   TRNS,W,   V,   Z,   TRNS,TRNS,
    TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,TRNS
    ),

    /* Colemak */
    [L_COLEMAK] = KEYMAP_INFINITY(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,F,   P,   G,   J,   L,   U,   Y,   SCLN,TRNS,TRNS,TRNS,
    TRNS,TRNS,R,   S,   T,   D,   TRNS,N,   E,   I,   O,   TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,K,   TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,TRNS
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
    [L_OVERLAY_HHKB_FN] = KEYMAP_INFINITY(
    TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, NO,  INS,
    CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,UP,  NO,  DEL,
    TRNS,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,TRNS,
    TRNS,FN8, NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,TRNS,TRNS,
    TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS,TRNS
    ),

    /* SpaceFn & EnterFn */
    [L_FN_SPACEFN] = KEYMAP_INFINITY(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN5,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,               FN4,           TRNS,TRNS,TRNS,TRNS
    ),

    /* Keymap settings layer */
    [L_OVERLAY_KEYMAP_SETTINGS] = KEYMAP_INFINITY(
    NO,  FN1, FN2, FN3, NO,  NO,  NO,  NO,  NO,  NO,  FN0, NO,  NO,  NO,  NO,
    NO,  FN0, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  FN1, NO,  FN3, NO,  NO,  NO,  NO,  NO,  NO,  FN7,
    NO,  NO,  NO,  FN2, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,                 FN7,           NO,  NO,  NO,  NO
    ),

    /* Primary Fn Layer */
    [L_FN_PRIMARY] = KEYMAP_INFINITY(
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN9,
    TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,FN6, TRNS
    ),
};



/**
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_FUNCTION(F_SWITCH_LAYOUT_QWERTY),
    [1]  = ACTION_FUNCTION(F_SWITCH_LAYOUT_DVORAK),
    [2]  = ACTION_FUNCTION(F_SWITCH_LAYOUT_COLEMAK),
    [3]  = ACTION_FUNCTION(F_SWITCH_LAYOUT_GAMER),

    [4]  = ACTION_LAYER_TAP_KEY(L_OVERLAY_HHKB_FN, KC_SPC),
    [5]  = ACTION_LAYER_TAP_KEY(L_OVERLAY_HHKB_FN, KC_ENTER),
    [6]  = ACTION_LAYER_TAP_KEY(L_OVERLAY_KEYMAP_SETTINGS, KC_APP),
    [7]  = ACTION_LAYER_TOGGLE(L_FN_SPACEFN),

    [8]  = ACTION_MACRO(M_SIGNATURE),

    [9]  = ACTION_LAYER_MOMENTARY(L_OVERLAY_HHKB_FN),
};
