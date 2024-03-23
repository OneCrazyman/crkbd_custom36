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


// Macro
enum custom_keycodes {
    TG_LNG = SAFE_RANGE,  //SET2로 전환 및 한영키 실행
};
// static bool set2_layer = false;
// key event record
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	/* LAYER KEY */
        case TG_LNG:
            if(record->event.pressed){
                layer_invert(_SET2);
                tap_code(KC_LNG1);
				// if(set2_layer){
				// 	// set_single_persistent_default_layer(BASE);
				// 	layer_invert(_SET2);
				// } else{
				// 	// set_single_persistent_default_layer(_SET2);
				// 	layer_invert(_SET2);
				// }
				// set2_layer = !set2_layer;
            } else {
               // nothing
            }
			break;
    }
	return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// COLEMAK DH
	[BASE] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,						  KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_LNG1,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX,  HOME_A,  HOME_R,  HOME_S,  HOME_T,    KC_G, 						  KC_M,  HOME_N,  HOME_E,  HOME_I,  HOME_O,  TG_LNG,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
		   MO(_RGB),    KC_Z,    KC_X, 	  KC_C,    KC_D,    KC_V,						  KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,MO(_RGB),
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											  MEDIA_ESC, NAV_SPC,MOUSE_TAB,	  SYM_ENT,NUM_BSPC, FUN_DEL
											//`--------------------------'  `--------------------------'
	),
	// Hangle_QWERTY
	[_SET2] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			 KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX,S_HOME_A,S_HOME_S,S_HOME_D,S_HOME_F, 	KC_G,		 				  KC_H,S_HOME_J,S_HOME_K,S_HOME_L,S_HOME_SCLN,TG_LNG,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,MO(_RGB),
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											    _______, _______, _______,    _______, _______, _______
											//`--------------------------'  `--------------------------'
	),
	[_MEDIA] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												XXXXXXX, XXXXXXX, XXXXXXX,    KC_MSTP, KC_MPLY, KC_MUTE
											//`--------------------------'  `--------------------------'
	),
	[_NAV] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_AGIN, KC_PSTE,  KC_INS, KC_HOME, KC_PGUP, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDO, KC_COPY,  KC_CUT,  KC_END, KC_PGDN, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												XXXXXXX, XXXXXXX, XXXXXXX,     KC_ENT, KC_BSPC,  KC_DEL
											//`--------------------------'  `--------------------------'
	),
	[_MOUSE] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          			   _______, _______, _______, _______, _______, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,   
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_MS_R, XXXXXXX,    
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												XXXXXXX, XXXXXXX, XXXXXXX,    KC_BTN1, KC_BTN2, KC_BTN3
											//`--------------------------'  `--------------------------'
	),
	[_SYM] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			XXXXXXX, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX, KC_TILD, KC_EXLM, KC_DQUO, KC_HASH, KC_PIPE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												KC_LPRN, KC_RPRN, KC_UNDS,    XXXXXXX, XXXXXXX, XXXXXXX
											//`--------------------------'  `--------------------------'
	),
	[_NUM] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			XXXXXXX, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX, KC_GRV,     KC_1,    KC_2,    KC_3, KC_BSLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												 KC_DOT,    KC_0, KC_MINS, 	  XXXXXXX, XXXXXXX, XXXXXXX
											//`--------------------------'  `--------------------------'
	),
	[_FUN] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			XXXXXXX,  KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												KC_MENU,  KC_SPC,  KC_TAB,    XXXXXXX, XXXXXXX, XXXXXXX
										//`--------------------------'  `--------------------------'
	),
	[_RGB] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_SLEP,  KC_PWR, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                    TG(_PUBG), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
											//`--------------------------'  `--------------------------'
	),
	// Gaming
	[_PUBG] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			 KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,TG(_PUBG),
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  TG_LNG,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_LSFT,    KC_Z,    KC_X, KC_LALT,    KC_V,  KC_ESC,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,MO(_RGB),
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
											       KC_C, KC_SPC,MO(_PSUB),	  SYM_ENT,NUM_BSPC, FUN_DEL
											//`--------------------------'  `--------------------------'
	),
	// PUBG sub layout
	[_PSUB] = LAYOUT_split_3x6_3(
		//,-----------------------------------------------------.                    ,-----------------------------------------------------.
			   KC_0,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			   KC_9,   KC_F1,   KC_F4,   KC_F2, KC_PGUP,    KC_N,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
			KC_LCTL,    KC_8,    KC_0,   KC_F3, KC_PGDN,    KC_M,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
		//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
												   KC_C,  KC_SPC, _______,	  XXXXXXX, XXXXXXX, XXXXXXX
											//`--------------------------'  `--------------------------'
	),
};