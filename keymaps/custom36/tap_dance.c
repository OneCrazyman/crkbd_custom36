#pragma once

typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
	SINGLE_TAP = 1,
  	SINGLE_HOLD = 2,
};

enum {
  TD_ESC_B = 0,
};

int cur_dance (tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (tap_dance_state_t *state, void *user_data);
void x_reset (tap_dance_state_t *state, void *user_data);

int cur_dance (tap_dance_state_t *state) {
	if (state->interrupted || !state->pressed)  return SINGLE_TAP;
	//key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
	else return SINGLE_HOLD;
}

static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state){
	case SINGLE_TAP: register_code(KC_ESC); break;
    case SINGLE_HOLD: register_code(KC_B); break;
  }
}

void x_reset (tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_ESC); break;
    case SINGLE_HOLD: unregister_code(KC_B); break;
	}
	xtap_state.state = 0;
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_B]	= ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset)
};