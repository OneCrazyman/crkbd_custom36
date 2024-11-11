/* 
Custum keymap for crkbd
*/
#include QMK_KEYBOARD_H
#include <stdbool.h>

#ifdef OLED_ENABLE
	#include "oled.c"
#else
	#include "keymap.h"
#endif

#include "tap_dance.c"
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
	// 										//`--------------------------'  `--------------------------'
	// ),
	[_RGB] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_SLEP,  KC_PWR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                    TG(_PUBG),TG(_MSW),TG(_COLEMAK), XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, QK_BOOT,                      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
			KC_LSFT,    KC_Z,    KC_X, KC_LALT,    KC_V,TD(TD_ESC_B),                     KC_N,    KC_M, KC_COMM,  ALTTAB, KC_LGUI,    KC_H,
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
			KC_LALT,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,  KC_INS, KC_HOME, KC_PGUP,TG(_MSW),
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_LNG1,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,  	KC_B,                         KC_N,    KC_M,  KC_DEL,  KC_END, KC_PGDN, KC_LGUI,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											  MEDIA_ESC, KC_SPC,MOUSE_TAB,	  SYM_ENT,NUM_BSPC, FUN_DEL
											//`--------------------------'  `--------------------------'
	),
	// COLEMAK DH
	[_COLEMAK] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
		     KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,						  KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, TG(_COLEMAK),
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_CAPS,  HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G, 						  KC_M,  HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_LNG1,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		    KC_LSFT,    KC_Z,    KC_X, 	  KC_C,    KC_D,    KC_V,						  KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											  MEDIA_ESC, NAV_SPC,MOUSE_TAB,	  SYM_ENT,NUM_BSPC, FUN_DEL
											//`--------------------------'  `--------------------------'
	),
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
			_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,   
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,    
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												XXXXXXX, XXXXXXX, XXXXXXX,    KC_BTN1, KC_BTN2, KC_BTN3
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