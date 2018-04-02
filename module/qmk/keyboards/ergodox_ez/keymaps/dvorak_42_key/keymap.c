#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"


// to build this keymap
// make ergodox_ez:dvorak_42_key:teensy
// flashing from rpi:
// sudo teensy_loader_cli -v -w .build/ergodox_ez_dvorak_42_key.hex --mcu atmega32u4

// keeping fork up to date:
// https://help.github.com/articles/configuring-a-remote-for-a-fork/
// https://help.github.com/articles/syncing-a-fork/
// pushing dev branch
// git push origin dev:dev

static bool mouse_lock = false;

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  // shell nav macros
  SHELL_LS,
  SHELL_LSLTR,
  SHELL_LSLA, 
  SHELL_CDPRE,
  SHELL_LESS,
  SHELL_PLESS,
  SHELL_PGREP,
  SHELL_TAILF,  
  
  SHELL_PWD,
  SHELL_H3,
  SHELL_AMMCOLO,
  SHELL_SCREENRD,
  SHELL_SCREEN_NEW,
  SHELL_SCREEN_LIST,
  SHELL_MKE,
  SHELL_HTCSTATUS,
  
  // Cloud9 macros
  CLOUD9_TAB_LEFT,
  CLOUD9_TAB_RIGHT,
  CLOUD9_TAB_CLOSE,
  CLOUD9_GOTO_SYMBOL,
  CLOUD9_GOTO_LINE,
  CLOUD9_NAVIGATE,
  
};


#define BASE         0 // base dvorak layer
#define KEYNAV       1 // arrow navigation (right hand)
#define KEYSEL       2 // arrow navigation + shift (allow text selection)
#define SHELL_NAV    3 // bash shortcuts
#define SHELL_SCREEN 4 // linux screen shortcuts
#define SCREEN_NAV   5 // navigate between linux screen tabs 
#define MOUSE        6 // mouse layer (can be locked with lock key), unmapped for now
#define BROWSER_CONTROL 7 // control browser and mouse
#define COMBINED      	8 // combined numbers and symbols layer


// macros
#define MOUSE_TOGGLE 1
#define MOUSE_LOCK 2
#define SCREEN_TAB_LEFT 4
#define SCREEN_TAB_RIGHT 5
#define SCREEN_NEW_TAB 6
#define SWITCH_NDS 7
#define SCREEN_COPY_MODE 8
#define SCREEN_PASTE 9
#define SCREEN_RENAME 10
#define SCREEN_NUMBER 11
#define SCREEN_0 12
#define SCREEN_1 13
#define SCREEN_2 14
#define SCREEN_3 15
#define SCREEN_4 16
#define SCREEN_5 17
#define SCREEN_6 18
#define SCREEN_7 19
#define SCREEN_8 20
#define SCREEN_9 21
#define SCREEN_DETACH 22
#define SCREEN_UP_JUMP 23
#define SCREEN_DOWN_JUMP 24
#define SCREEN_READREG_1 25
#define SCREEN_READREG_2 26
#define SCREEN_READREG_3 27
#define SCREEN_PASTEREG_1 28
#define SCREEN_PASTEREG_2 29
#define SCREEN_PASTEREG_3 30
#define SHELL_WRITE_LOGPATTERN 31
#define SHELL_WRITE_TRANPATTERN 32
#define SHELL_EXPAND_PATTERN 33



#define MACRO_SCREEN_NUM(MACRO_NAME,NUM) \
        case MACRO_NAME:\
             if (record->event.pressed) {\
                return MACRO( D(LCTL), T(A), U(LCTL), T(NUM), END);\
            }\
        break;\
		
#define MACRO_SCREEN_REG(MACRO_NAME,NUM) \
        case MACRO_NAME:\
             if (record->event.pressed) {\
                return MACRO( D(LCTL), T(A), U(LCTL), D(LSFT), T(SCOLON), U(LSFT),\
                              T(R),\
                              T(E),\
                              T(A),\
                              T(D),\
                              T(R),\
                              T(E),\
							  T(G),\
                              T(SPC),\
							  T(NUM),\
							  T(ENTER),\
                             END);\
            }\
        break;\

#define MACRO_SCREEN_PASTE(MACRO_NAME,NUM)\
        case MACRO_NAME:\
             if (record->event.pressed) {\
                return MACRO( D(LCTL), T(A), U(LCTL), D(LSFT), T(SCOLON), U(LSFT),\
                              T(P),\
                              T(A),\
                              T(S),\
                              T(T),\
                              T(E),\
                              T(SPC),\
							  T(NUM),\
							  T(ENTER),\
                             END);\
            }\
        break;\

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = KEYMAP(
      // left hand
      KC_ESC,            KC_F1,         KC_F2,      KC_F3,        KC_F4,   KC_F5,   KC_F6,
      OSL(SCREEN_NAV),   KC_QUOTE,      KC_COMMA,   KC_DOT,       KC_P,    KC_Y,    MEH(KC_2),
      OSL(SHELL_NAV),    KC_A,          KC_O,       KC_E,         KC_U,    KC_I,
      OSL(SHELL_SCREEN), KC_SCOLON,     KC_Q,       KC_J,         KC_K,    KC_X,    MEH(KC_3),
      MEH(KC_1),         OSM(MOD_LSFT), OSM(MOD_LCTL), MO(KEYSEL), MO(BROWSER_CONTROL),
      
      // left thumb cluster
                MEH(KC_4),      MEH(KC_5),
                                MEH(KC_6),
      MO(COMBINED),MO(KEYNAV),  OSM(MOD_LALT),
      
      // right hand
      KC_F7,     KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, MEH(KC_9),
      MEH(KC_7), KC_F,  KC_G,  KC_C,   KC_R,   KC_L,   KC_TAB,
                 KC_D,  KC_H,  KC_T,   KC_N,   KC_S,   RCTL(KC_BSPC),
      MEH(KC_8), KC_B,  KC_M,  KC_W,   KC_V,   KC_Z,   MEH(KC_F3),
      KC_BSPC,   RCTL(KC_BSPC), KC_CAPSLOCK, OSM(MOD_LSFT),MEH(KC_F4),
    
      // right thumb cluster
      MEH(KC_F5),MEH(KC_F6),MEH(KC_F7),MEH(KC_F8),KC_ENTER,KC_SPACE
  
  ),
  
  [KEYNAV] = KEYMAP(
    // left hand
    KC_TRNS,KC_TRNS,     KC_TRNS,            KC_TRNS,         KC_TRNS,          KC_TRNS,          KC_TRNS,
    KC_TRNS,KC_ESC,      CLOUD9_GOTO_LINE,   RCTL(KC_Z),      RCTL(KC_S),       MEH(KC_F10),      KC_TRNS,
    KC_TRNS,KC_LSFT,     CLOUD9_GOTO_SYMBOL, RSFT(KC_TAB),    KC_TAB,           MEH(KC_A),
    KC_TRNS,MEH(KC_B),   CLOUD9_NAVIGATE,    CLOUD9_TAB_LEFT, CLOUD9_TAB_RIGHT, CLOUD9_TAB_CLOSE, KC_TRNS,
    KC_TRNS,KC_TRNS,     KC_TRNS,            KC_TRNS,         KC_TRNS,
    // left thumb cluster
    KC_TRNS,KC_TRNS,KC_TRNS,TO(MOUSE),KC_TRNS,KC_TRNS,
    
    // right hand
    KC_TRNS,KC_TRNS,       KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS,         MEH(KC_G),
    KC_TRNS,KC_NO,         KC_HOME,    KC_UP,           KC_END,     KC_PGUP,         MEH(KC_H),
            LCTL(KC_LEFT), KC_LEFT,    KC_DOWN,         KC_RIGHT,   LCTL(KC_RIGHT),  MEH(KC_I),
    KC_TRNS,KC_NO,         RCTL(KC_C), RCTL(KC_X),      RCTL(KC_V), KC_PGDOWN,       MEH(KC_J),
                           KC_BSPC,   RCTL(KC_BSPC),    KC_DELETE,  LCTL(KC_DELETE), MEH(KC_K),
    
    // right thumb cluster
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
  ),  
  
    // key selection layer
    [KEYSEL] = KEYMAP(
           // left hand
           KC_TRNS,KC_TRNS,   KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,
           KC_TRNS,MEH(KC_G), MEH(KC_H),MEH(KC_I), MEH(KC_J), MEH(KC_K), KC_TRNS,
           KC_TRNS,MEH(KC_L), MEH(KC_M),MEH(KC_N), MEH(KC_O), MEH(KC_P),
           KC_TRNS,MEH(KC_Q), MEH(KC_R),MEH(KC_S), MEH(KC_T), MEH(KC_U), KC_TRNS,
                   // bottom row
                   RESET,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                           // thumb cluster
                                           KC_TRNS,KC_TRNS,
                                                   KC_TRNS,
                                   KC_TRNS,KC_TRNS,KC_TRNS,
           // right hand
           KC_TRNS,       KC_TRNS,             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,              MEH(KC_Q),
           RSFT(KC_PGUP), KC_TRNS,             RSFT(KC_HOME), RSFT(KC_UP),   RSFT(KC_END),   RSFT(KC_PGUP),        MEH(KC_R),
                          RSFT(RCTL(KC_LEFT)), RSFT(KC_LEFT), RSFT(KC_DOWN), RSFT(KC_RIGHT), RSFT(RCTL(KC_RIGHT)), MEH(KC_S),
           RSFT(KC_PGDN), KC_TRNS,             RCTL(KC_C),    RCTL(KC_X),    RCTL(KC_V),     RSFT(KC_PGDN),        MEH(KC_T),
                    // bottom row
                    KC_BSPC,   RCTL(KC_BSPC),    KC_DELETE,  LCTL(KC_DELETE),                                      MEH(KC_U),
           // thumb cluster
           KC_TRNS, KC_TRNS,
           KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS
    ),  
  
  // shell navigation layer
  [SHELL_NAV] = KEYMAP(
       // left hand
       KC_NO,  KC_TRNS,           KC_TRNS,        KC_TRNS,          KC_TRNS,     KC_TRNS,         KC_TRNS,
       KC_TRNS,KC_TRNS,           SHELL_PGREP,    SHELL_PLESS,      SHELL_LESS,  KC_TRNS,         SHELL_H3,
       KC_TRNS,SHELL_MKE,         SHELL_CDPRE,    SHELL_LSLTR,      SHELL_LS,    SHELL_LSLA,
       KC_TRNS,SHELL_SCREEN_LIST, SHELL_SCREENRD, SHELL_SCREEN_NEW, SHELL_TAILF, SHELL_HTCSTATUS, SHELL_AMMCOLO,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,    KC_TRNS,    KC_TRNS,             KC_TRNS,         KC_TRNS,    KC_TRNS,    M(SHELL_WRITE_TRANPATTERN),
       RCTL(KC_L), RCTL(KC_W), KC_HOME,             KC_UP,           KC_END,     KC_TRNS,    M(SHELL_WRITE_LOGPATTERN),
                   LALT(KC_B), KC_LEFT,             KC_DOWN,         KC_RIGHT,   LALT(KC_F), RCTL(KC_W),
       RCTL(KC_C), RCTL(KC_U), LALT(KC_DOT),        RCTL(KC_R),      MEH(KC_V),  RCTL(KC_K), M(SHELL_EXPAND_PATTERN),
                   // bottom row (match functionality of base layer)
                   KC_BSPC,    RCTL(KC_W),          KC_DELETE,       LALT(KC_D), RCTL(KC_U),
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
  ),
  

    // linux screen layer
  [SHELL_SCREEN] = KEYMAP(
       // left hand
       KC_NO,  KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,
       KC_TRNS,KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,
       KC_TRNS,KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
       KC_TRNS,KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,   KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,             KC_TRNS,
       KC_TRNS, M(SCREEN_NEW_TAB),  M(SCREEN_7), M(SCREEN_8), M(SCREEN_9), M(SCREEN_RENAME),    KC_TRNS,
                M(SCREEN_TAB_LEFT), M(SCREEN_4), M(SCREEN_5), M(SCREEN_6), M(SCREEN_TAB_RIGHT), KC_TRNS,
       KC_TRNS, KC_TRNS,            M(SCREEN_1), M(SCREEN_2), M(SCREEN_3), M(SCREEN_NUMBER),    KC_TRNS,
                                    // bottom row
                                    M(SCREEN_0), KC_TRNS,     KC_TRNS,     KC_TRNS,             M(SCREEN_DETACH),
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
  ),

  // navigation within screen (for copy/paste)
  [SCREEN_NAV] = KEYMAP(
       // left hand
       // left hand
       KC_NO,  KC_TRNS,    KC_TRNS,              KC_TRNS,     		  KC_TRNS,               KC_TRNS,   KC_TRNS,
       KC_TRNS,KC_TRNS,    M(SCREEN_READREG_3),  M(SCREEN_READREG_2),  M(SCREEN_READREG_1),   KC_TRNS,   KC_TRNS,
       KC_TRNS,KC_TRNS,    M(SCREEN_PASTEREG_3), M(SCREEN_PASTEREG_2), M(SCREEN_PASTEREG_1),  KC_TRNS,
       KC_TRNS,KC_TRNS,    KC_TRNS,     		 KC_TRNS,     	      KC_TRNS,               KC_TRNS,   KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,    		  KC_TRNS,
       KC_TRNS,    KC_TRNS,    KC_0,           KC_UP,           KC_DLR,          M(SCREEN_UP_JUMP),   KC_TRNS,
                   KC_B,       KC_LEFT,        KC_DOWN,         KC_RIGHT,   	 KC_W,       		  M(SCREEN_COPY_MODE),
       KC_TRNS,    KC_TRNS,    S(KC_W),        S(KC_Y),         M(SCREEN_PASTE), M(SCREEN_DOWN_JUMP), MEH(KC_V),
                   // bottom row (match functionality of base layer)
                   KC_TRNS,    KC_TRNS,        KC_TRNS,         KC_TRNS,    KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
  ),
  


  
  [COMBINED] = KEYMAP(
  
    // left hand
    KC_NO,  KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS,
    KC_TRNS,KC_EXLM, KC_AT,      KC_HASH,     KC_DLR,      KC_PERC, KC_TRNS,
    KC_TRNS,KC_LPRN, KC_RPRN,    KC_LBRACKET, KC_RBRACKET, KC_UNDS,
    KC_TRNS,KC_COLN, KC_DQUO,    KC_LCBR,     KC_RCBR,     KC_AMPR, KC_TRNS,
    // bottom row
    KC_TRNS,KC_TRNS, KC_TILD,    KC_GRAVE,    KC_CIRC,
    // thumb cluster
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    
    // right hand
    KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     MEH(KC_L),
    KC_TRNS, KC_PLUS,     KC_7,    KC_8,    KC_9,    KC_ASTR,     MEH(KC_M),
             KC_MINS,     KC_4,    KC_5,    KC_6,    KC_SLSH,     MEH(KC_N),
    KC_TRNS, KC_EQUAL,    KC_1,    KC_2,    KC_3,    KC_QUES,     MEH(KC_O),
    // bottom row 
                          KC_0,    KC_DOT,  KC_PIPE, KC_BSLS,     MEH(KC_P),
    // thumb cluster
    KC_TRNS,KC_TRNS,
	KC_TRNS,
	KC_TRNS,KC_TRNS,KC_TRNS),
  
  
    [MOUSE] = KEYMAP(
           KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS,      KC_PGUP,       KC_MS_WH_UP,   KC_UP,        KC_TRNS, KC_TRNS,
           KC_TRNS, KC_MS_ACCEL0, KC_PGDN,       KC_MS_WH_DOWN, KC_DOWN,      KC_TRNS,
           KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS,      M(MOUSE_LOCK), KC_TRNS,       KC_MS_ACCEL0,
           
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_BTN3, KC_TRNS,
        // right hand
           KC_TRNS,  KC_TRNS,   KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,       KC_TRNS,
           KC_TRNS,  KC_UP,     KC_HOME,      KC_MS_U,      KC_END,       KC_MS_WH_UP,   KC_TRNS,
                     KC_DOWN,   KC_MS_L,      KC_MS_D,      KC_MS_R,      KC_MS_WH_DOWN, KC_TRNS,
           KC_TRNS,  MEH(KC_X), MEH(KC_Y),    MEH(KC_Z),    KC_F5,        RCTL(KC_W),    KC_TRNS,
                                    // browser tab control
                                    RSFT(RCTL(KC_TAB)), RCTL(KC_TAB), RCTL(KC_T), LALT(KC_LEFT), KC_TRNS,
           KC_TRNS, KC_TRNS,
           KC_TRNS,
           KC_TRNS, KC_BTN1, KC_BTN2
    ),  
	
    [BROWSER_CONTROL] = KEYMAP(
		   // left hand
           KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS,      KC_BTN3,       KC_MS_U,       KC_BTN1,      KC_BTN2, KC_TRNS,
           KC_TRNS, KC_TRNS,      KC_MS_L,       KC_MS_D,       KC_MS_R,      KC_TRNS,
           KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS, KC_TRNS,
		   // bottom row
           KC_TRNS, KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
           
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
          // right hand
           KC_TRNS,  KC_TRNS,   KC_TRNS,            KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
           KC_TRNS,  KC_UP,     KC_PGUP,            KC_PGDN,      KC_MS_WH_UP,   KC_TRNS,       KC_TRNS,
                     KC_DOWN,   RSFT(RCTL(KC_TAB)), RCTL(KC_TAB), KC_MS_WH_DOWN, LALT(KC_LEFT), KC_TRNS,
           KC_TRNS,  KC_TRNS,   RCTL(KC_1),         RCTL(KC_9),   KC_F6,         KC_F5,         KC_TRNS,
                                // bottom row
                                KC_TRNS,            KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,
           KC_TRNS, KC_TRNS,
           KC_TRNS,
           KC_TRNS, RCTL(KC_W), RCTL(KC_T)
    ),  	
    

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case MOUSE_TOGGLE:
            if (record->event.pressed) {
                layer_on(MOUSE);
            } else {
                if(!mouse_lock)
                    layer_off(MOUSE);
            }
            break;
        case MOUSE_LOCK:
            if (record->event.pressed)
            {
                if(mouse_lock)
                {
                    mouse_lock = false;
                    layer_off(MOUSE);
                }
                else
                    mouse_lock = true;
            }
            break;
        case SCREEN_TAB_LEFT:
            if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(P), END);
            }        
            break;
        case SCREEN_TAB_RIGHT:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(N), END);
            }                    
            break;
        case SCREEN_NEW_TAB:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(C), END);
            }                                
        break;
        case SCREEN_DETACH:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(D), END);
            }
        break;        
        case SCREEN_RENAME:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), D(LSFT), T(A), U(LSFT), END);
            }                                
        break;        
        case SCREEN_NUMBER:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), D(LSFT), T(SCOLON), U(LSFT),
                              T(N),
                              T(U),
                              T(M),
                              T(B),
                              T(E),
                              T(R),
                              T(SPC),
                             END);
            }                                
        break;        

		MACRO_SCREEN_REG(SCREEN_READREG_1,1);
		MACRO_SCREEN_REG(SCREEN_READREG_2,2);
		MACRO_SCREEN_REG(SCREEN_READREG_3,3);
		
		MACRO_SCREEN_PASTE(SCREEN_PASTEREG_1,1);
		MACRO_SCREEN_PASTE(SCREEN_PASTEREG_2,2);
		MACRO_SCREEN_PASTE(SCREEN_PASTEREG_3,3);

        MACRO_SCREEN_NUM(SCREEN_0,0);
        MACRO_SCREEN_NUM(SCREEN_1,1);
        MACRO_SCREEN_NUM(SCREEN_2,2);
        MACRO_SCREEN_NUM(SCREEN_3,3);
        MACRO_SCREEN_NUM(SCREEN_4,4);
        MACRO_SCREEN_NUM(SCREEN_5,5);
        MACRO_SCREEN_NUM(SCREEN_6,6);
        MACRO_SCREEN_NUM(SCREEN_7,7);
        MACRO_SCREEN_NUM(SCREEN_8,8);
        MACRO_SCREEN_NUM(SCREEN_9,9);
        
		case SCREEN_UP_JUMP:
            if (record->event.pressed) {
                return MACRO( T(5), T(UP), END);
            }		
		break;
		
		case SCREEN_DOWN_JUMP:
            if (record->event.pressed) {
                return MACRO( T(5), T(DOWN), END);
            }		
		break;		
		
        case SCREEN_COPY_MODE:
            if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(ESC), END);
            }
        break;
        case SCREEN_PASTE:
            if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(RBRC), END); 
            }
        break;        
		
		case SHELL_WRITE_LOGPATTERN:
            if (record->event.pressed) {
                return MACRO( D(LSFT),
							  T(8), 
				              T(8), 
							  U(LSFT),
							  T(L),  
							  T(O), 
							  T(G), 
							  T(LEFT), 
							  T(LEFT), 
							  T(LEFT), 
							  T(LEFT), 
							  END); 
            }		
		break;
		
		case SHELL_WRITE_TRANPATTERN:
            if (record->event.pressed) {
                return MACRO( D(LSFT),
							  T(8), 
				              T(8), 
							  U(LSFT), T(T), T(R), T(A), T(N), T(LEFT), T(LEFT), T(LEFT), T(LEFT), T(LEFT), END); 
            }		
		break;		
		
		case SHELL_EXPAND_PATTERN:
            if (record->event.pressed) {
                return MACRO( D(LALT), T(F), U(LALT), D(LCTL), T(X), U(LCTL), D(LSFT), T(8), D(LSFT), END); 
            }		
		break;				
   
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
  }
  
  // shell macros
  if(record->event.pressed) {
    switch (keycode) {
        case SHELL_LS:
            SEND_STRING("ls\n");
            return true;
            break;
        case SHELL_LSLTR:
            SEND_STRING("ls -ltr\n");
            return true;
            break;
        case SHELL_LSLA:
            SEND_STRING("ls -la\n");
            return true;
            break;
        case SHELL_CDPRE:
            SEND_STRING("cd ..\n");
            return true;
            break;
        case SHELL_LESS:
            SEND_STRING("less ");
            return true;
            break;
        case SHELL_PLESS:
            SEND_STRING(" | less");
            return true;
            break;
        case SHELL_PGREP:
            SEND_STRING(" | grep ");
            return true;
            break;            
        case SHELL_TAILF:
            SEND_STRING("tail -f ");
            return true;
            break;
        case SHELL_PWD:
            SEND_STRING("echo `pwd`/");
            return true;
            break;            
        case SHELL_H3:
            SEND_STRING("h3\n");
            return true;
            break;            
        case SHELL_AMMCOLO:
            SEND_STRING("ammcolo\n");
            return true;
            break;            
        case SHELL_SCREENRD:
            SEND_STRING("screen -r -d ");
            return true;
            break;                    
        case SHELL_SCREEN_NEW:
            SEND_STRING("screen -S ");
            return true;
            break;
        case SHELL_SCREEN_LIST:
            SEND_STRING("screen -list\n");
            return true;
            break;            
        case SHELL_MKE:
            SEND_STRING("mke\n");
            return true;
            break;     
        case SHELL_HTCSTATUS:
            SEND_STRING("htcStatus -j ");
            return true;
            break;               
		// Cloud9 macros
		case CLOUD9_TAB_LEFT:
            SEND_STRING(SS_LCTRL("["));
            return true;		
			break;
		case CLOUD9_TAB_RIGHT:
            SEND_STRING(SS_LCTRL("]"));
            return true;				
			break;
		case CLOUD9_TAB_CLOSE:
            SEND_STRING(SS_LALT("w"));
            return true;				
			break;
		case CLOUD9_GOTO_SYMBOL:
            SEND_STRING(SS_LSFT(SS_LCTRL("e")));
            return true;		
			break;
		case CLOUD9_GOTO_LINE:
            SEND_STRING(SS_LCTRL("g"));
            return true;						
			break;
		case CLOUD9_NAVIGATE:
            SEND_STRING(SS_LCTRL("e"));
            return true;
			break;
  		
    }
  }
  
  return true;
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }
}

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case COMBINED:
            ergodox_right_led_2_on();        
            break;
        case SHELL_NAV:            
        case SHELL_SCREEN:
        case KEYNAV:
        case KEYSEL:
		case SCREEN_NAV:
            ergodox_right_led_3_on();
            break;
        case MOUSE:
		case BROWSER_CONTROL:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

};
