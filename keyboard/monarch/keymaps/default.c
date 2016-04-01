#include "keymap_common.h"
#include "layer.h"
#include "macro.h"
#include "function.h"
#include "init.h"

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
    [L_QWERTY] = KEYMAP_US(
    NLCK,PEQL,PSLS,PAST,     ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,
    P7,  P8,  P9,  PMNS,     TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSLS,
    P4,  P5,  P6,  PPLS,     CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,ENT,
    P1,  P2,  P3,  PENT,     LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,
    P0,       PDOT,          LCTL,LALT,LGUI,               SPC,           RGUI,RALT,RCTL
    ),

    /* Dvorak */
    [L_DVORAK] = KEYMAP_US(
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,LBRC,RBRC,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   SLSH,EQL, TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,O,   E,   U,   I,   D,   H,   T,   N,   S,   MINS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,SCLN,Q,   J,   K,   X,   B,   TRNS,W,   V,   Z,   TRNS,
    TRNS,     TRNS,          TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS
    ),

    /* Colemak */
    [L_COLEMAK] = KEYMAP_US(
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,F,   P,   G,   J,   L,   U,   Y,   SCLN,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,R,   S,   T,   D,   TRNS,N,   E,   I,   O,   TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,K,   TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,          TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS
    ),

    /* Remap Ctrl keys */
    [L_OVERLAY_CTRL_REMAP] = KEYMAP_US(
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     LCTL,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,          FN9, TRNS,TRNS,               TRNS,          TRNS,TRNS,CAPS
    ),

    /**
     * HHKB function layer
     * ,-----------------------------------------------------------.
     * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|  Del  |
     * |-----------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   | Ins |
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|   |   |  *|  /|Hom|PgU|Lef|Rig|        |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  +|  -|End|PgD|Dow|          |
     * |-----------------------------------------------------------|
     * |     |    |     |                         |     |    |Ctrl |
     * `-----------------------------------------------------------'
     */
    [L_OVERLAY_HHKB_FN] = KEYMAP_US(
    TRNS,TRNS,TRNS,TRNS,     GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, DEL,
    TRNS,TRNS,TRNS,TRNS,     CAPS,NO,  NO,  NO,  NO,  NO,  NO,  NO,  PSCR,SLCK,PAUS,UP,  NO,  INS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,VOLD,VOLU,MUTE,NO,  NO,  PAST,PSLS,HOME,PGUP,LEFT,RGHT,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,FN10,NO,  NO,  NO,  NO,  PPLS,PMNS,END, PGDN,DOWN,TRNS,
    TRNS,     TRNS,          TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,RCTL
    ),

    /* SpaceFn & EnterFn */
    [L_FN_SPACEFN] = KEYMAP_US(
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN5,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,          TRNS,TRNS,TRNS,               FN4,           TRNS,TRNS,TRNS
    ),

    /* Gaming Overrides */
    [L_OVERLAY_GAMER] = KEYMAP_US(
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,          LCTL,TRNS,NO,                 TRNS,          NO,  TRNS,TRNS
    ),

    /* Keymap settings layer */
    [L_OVERLAY_KEYMAP_SETTINGS] = KEYMAP_US(
    NO,  NO,  NO,  NO,       NO,  FN1, FN2, FN3, NO,  NO,  NO,  NO,  NO,  NO,  FN0, FN11,FN12,NO,
    NO,  NO,  NO,  NO,       NO,  FN0, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,  NO,  NO,  NO,       NO,  NO,  NO,  FN1, NO,  FN3, NO,  NO,  NO,  NO,  NO,  NO,  FN7,
    FN13,NO,  NO,  NO,       NO,  NO,  NO,  FN2, NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,
    NO,       NO,            FN8, NO,  NO,                 FN7,           NO,  NO,  FN8
    ),

    /* Primary Fn layer */
    [L_FN_PRIMARY] = KEYMAP_US(
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,TRNS,TRNS,TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,          TRNS,TRNS,TRNS,               TRNS,          FN6, TRNS,TRNS
    ),

    /* Keypad gaming layer */
    [L_KP_GAMER] = KEYMAP_US(
    1,   2,   3,   4,        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    Q,   W,   E,   R,        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    A,   S,   D,   F,        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    Z,   X,   C,   SPC,      TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    NO,       FN14,          TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS
    ),

    /* Keypad gaming layer */
    [L_KP_GAMER_L2] = KEYMAP_US(
    NO,  NO,  NO,  NO,       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    7,   8,   9,   NO,       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    4,   5,   6,   NO,       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    1,   2,   3,   NO,       TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    NO,       TRNS,          TRNS,TRNS,TRNS,               TRNS,          TRNS,TRNS,TRNS
    ),
};



/**
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0]   = ACTION_FUNCTION(F_SWITCH_LAYOUT_QWERTY),
    [1]   = ACTION_FUNCTION(F_SWITCH_LAYOUT_DVORAK),
    [2]   = ACTION_FUNCTION(F_SWITCH_LAYOUT_COLEMAK),
    [3]   = ACTION_FUNCTION(F_SWITCH_LAYOUT_GAMER),

    [4]   = ACTION_LAYER_TAP_KEY(L_OVERLAY_HHKB_FN, KC_SPC),
    [5]   = ACTION_LAYER_TAP_KEY(L_OVERLAY_HHKB_FN, KC_ENTER),
    [6]   = ACTION_LAYER_TAP_KEY(L_OVERLAY_KEYMAP_SETTINGS, KC_APP),
    [7]   = ACTION_LAYER_TOGGLE(L_FN_SPACEFN),
    [8]   = ACTION_LAYER_TOGGLE(L_OVERLAY_CTRL_REMAP),

    [9]   = ACTION_FUNCTION(F_CTRL_QWERTY_FALLBACK),

    [10]  = ACTION_MACRO(M_SIGNATURE),

    [11]  = ACTION_BACKLIGHT_INCREASE(),
    [12]  = ACTION_BACKLIGHT_DECREASE(),

    [13]  = ACTION_LAYER_TOGGLE(L_KP_GAMER),
    [14]  = ACTION_LAYER_MOMENTARY(L_KP_GAMER_L2),
};
