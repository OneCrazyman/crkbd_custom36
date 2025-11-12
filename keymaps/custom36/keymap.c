/* 
Custum keymap for crkbd
*/
#include QMK_KEYBOARD_H
#include <stdbool.h>

#ifdef OLED_ENABLE
	// #include "oled.c"
#else
	
#endif

#include "keymap.h"

// 상태 저장용 변수
bool d_toggle_enabled = false; // 토글 모드 활성화 여부
bool d_auto_enabled = false; // 토글 모드 활성화 여부
bool d_is_pressed = false;     // 현재 D키가 눌린 상태인지

// #include "tap_dance.c"
#include "macro.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// COLEMAK DH
	[BASE] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
		    RGB_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, RGB_ESC,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		    KC_CAPS,S_HOME_A,S_HOME_S,S_HOME_D,S_HOME_F, 	KC_G,		 				  KC_H,S_HOME_J,S_HOME_K,S_HOME_L,S_HOME_SCLN,KC_LNG1,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LSFT,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											  MEDIA_ESC, NAV_SPC,MOUSE_TAB,	  SYM_ENT,NUM_BSPC, FUN_DEL
											//`--------------------------'  `--------------------------'
	),
	// // Hangle_QWERTY
	// [_SET2] = LAYOUT_split_3x6_3(
	// 	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
	// 		_______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
	// 	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	// 		_______,S_HOME_A,S_HOME_S,S_HOME_D,S_HOME_F, 	KC_G,		 				  KC_H,S_HOME_J,S_HOME_K,S_HOME_L,S_HOME_SCLN,_______,
	// 	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	// 		KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
	// 	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	// 										    _______, _______, _______,    _______, _______, _______
	// 								s		//`--------------------------'  `--------------------------'
	// ),
	// [_RGB] = LAYOUT_split_3x6_3(
	// 	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
	// 		XXXXXXX, TG(_PUBG), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_SLEP,  KC_PWR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	// 	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	// 		rgblight_toggle, rgblight_increase_hue, rgblight_increase_sat, rgblight_increase_val, XXXXXXX, XXXXXXX,                    TG(_PUBG),TG(_MSW),TG(_COLEMAK), XXXXXXX, XXXXXXX, XXXXXXX,
	// 	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	// 		rgblight_mode_step, rgblight_decrease_hue, rgblight_decrease_sat, rgblight_decrease_val, XXXXXXX, QK_BOOT,                      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
	// 	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	// 											XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
	// 										//`--------------------------'  `--------------------------'
	// ),
	[_RGB] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, XXXXXXX, XXXXXXX,                    TG(_PUBG),TG(_MSW),TG(_COLEMAK), XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			UG_NEXT, UG_HUED, UG_SATD, UG_VALD, XXXXXXX, QK_BOOT,                      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
											//`--------------------------'  `--------------------------'
	),	
	// Gaming
	[_PUBG] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			 KC_DOT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,  KC_ESC,TG(_PUBG),
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,LCTL(KC_M),
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_LSFT,    KC_Z,    KC_X, KC_LALT,    KC_V, XXXXXXX,                     KC_N,    KC_M, KC_COMM,  ALTTAB, KC_LGUI,    KC_H,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											       KC_C,  KC_SPC,MO(_PSUB),	  SYM_ENT,NUM_BSPC, FUN_DEL
											//`--------------------------'  `--------------------------'
	),
	// PUBG sub layout
	[_PSUB] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			   KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			   KC_9,   KC_F1,   KC_F4,   KC_F2, KC_PGUP,    KC_N,                      XXXXXXX, KC_MPLY, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_LCTL,    KC_8,   KC_F5,   KC_F3, KC_PGDN,    KC_M,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											 LCTL(KC_M),    KC_I, _______,	  XXXXXXX, XXXXXXX, XXXXXXX
											//`--------------------------'  `--------------------------'
	),
	[_MSW] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			KC_LALT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,  KC_UP, KC_HOME, KC_PGUP,TG(_MSW),
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_CAPS,    KC_A,    KC_S,    D_TOGGLE,    KC_F,    KC_G,                  KC_H, KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, AUTO_MODE,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,  	KC_B,                         KC_N,    KC_M,  KC_DEL,  KC_END, KC_PGDN, TOGGLE_MODE,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											  MEDIA_ESC, KC_SPC,MOUSE_TAB,	  KC_ENT,NUM_BSPC, FUN_DEL 
											//`--------------------------'  `--------------------------'
	),
	// // COLEMAK DH
	// [_COLEMAK] = LAYOUT_split_3x6_3(
	// 	//,-----------------------------------------------------.                    ,-----------------------------------------------------.
	// 	     KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,						  KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, TG(_COLEMAK),
	// 	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	// 		KC_CAPS,  HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G, 						  KC_M,  HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_LNG1,
	// 	//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
	// 	    KC_LSFT,    KC_Z,    KC_X, 	  KC_C,    KC_D,    KC_V,						  KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
	// 	//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
	// 										  MEDIA_ESC, NAV_SPC,MOUSE_TAB,	  SYM_ENT,NUM_BSPC, FUN_DEL
	// 										//`--------------------------'  `--------------------------'
	// ),
	[_MEDIA] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			_______, KC_LGUI,    FULL, XXXXXXX, KC_SLEP,  KC_PWR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												XXXXXXX, XXXXXXX, XXXXXXX,    KC_MSTP, KC_MPLY, KC_MUTE
											//`--------------------------'  `--------------------------'
	),
	[_NAV] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      	  REDO,    PSTE,  KC_INS, KC_HOME, KC_PGUP, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     	  UNDO,    COPY,  KC_DEL,  KC_END, KC_PGDN, _______,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												XXXXXXX, XXXXXXX, XXXXXXX,     KC_ENT, KC_BSPC,  KC_DEL
											//`--------------------------'  `--------------------------'
	),
	[_MOUSE] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          			   _______, _______, _______, _______, _______, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      _______, MS_LEFT, MS_DOWN, MS_UP, MS_RGHT, XXXXXXX,   
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      _______, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, _______,    
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												XXXXXXX, XXXXXXX, XXXXXXX,    MS_BTN1, MS_BTN2, MS_BTN3
											//`--------------------------'  `--------------------------'
	),
	[_SYM] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			_______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, LSFT(KC_QUOT), KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, KC_TILD, KC_EXLM,   KC_AT, KC_HASH, KC_PIPE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												KC_LPRN, KC_RPRN, KC_UNDS,    XXXXXXX, XXXXXXX, XXXXXXX
											//`--------------------------'  `--------------------------'
	),
	[_NUM] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			_______, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, KC_QUOT,    KC_4,    KC_5,    KC_6,  KC_EQL,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, KC_GRV,     KC_1,    KC_2,    KC_3, KC_BSLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												 KC_DOT,    KC_0, KC_MINS, 	  XXXXXXX, XXXXXXX, XXXXXXX
											//`--------------------------'  `--------------------------'
	),
	[_FUN] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			_______,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												KC_MENU,  KC_SPC,  KC_TAB,    XXXXXXX, XXXXXXX, XXXXXXX
										//`--------------------------'  `--------------------------'
	),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
