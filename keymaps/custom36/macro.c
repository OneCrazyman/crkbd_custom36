#pragma once

// Macro
// enum custom_keycodes {
// //     // TG_LNG = SAFE_RANGE,  //SET2로 전환 및 한영키 실행
// // 	COPY = SAFE RANGE,
// // 	PSTE,
// // 	CUT,
// // 	UNDO,
// // 	REDO,
// 	// INVITE = SAFE_RANGE,
// };

// static bool set2_layer = false;
// key event record
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
// // 	// /* LAYER KEY */
// //     //     case TG_LNG:
// //     //         if(record->event.pressed){
// //     //             layer_invert(_SET2);
// //     //             tap_code(KC_LNG1);
// //     //         } else {
// //     //            // nothing
// //     //         }
// // 	// 		return false;
// // 		/* 추후에 디파인으로 변경 - 메모리 차지 16 */	
// // 		case COPY:
// // 			if (record->event.pressed){
// // 				/* code */
// // 				tap_code16(LCTL(KC_C));
// 		case INVITE:
// 			if (record->event.pressed){
// 				tap_code(KC_ENT);
// 				_delay_ms(300);
// 				tap_code16(PSTE); //16비트로 복합키를 담을 수 있다.ㅣ
// 				_delay_ms(100);
// 				tap_code(KC_ENT);
// 				_delay_ms(200);
// 				tap_code(KC_ESC);
// 			}
// 			return false;	
//     }
// 	return true;
// }