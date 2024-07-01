/* LAYER NAME */
// #define BASE 0
// #define _MEDIA 8
// #define _NAV 2
// #define _MOUSE 3
// #define _SYM 4
// #define _NUM 5
// #define _FUN 6
// #define _RGB 7
// #define _SET2 1 //hangle_2 qwerty
// #define _PUBG 9 //gaming
/* change to enum list */

enum layer_names{
    BASE, // 0
    // _SET2, // 1
    _RGB,
    _PUBG,
    _PSUB,
    _MSW,
    _MEDIA, // ...
    _NAV,
    _MOUSE,
    _SYM,
    _NUM, 
    _FUN,
};

/* COLEMAK-DH_BASE */
// Left-hand home row mods
// #define HOME_A LGUI_T(KC_A)
// #define HOME_R LCTL_T(KC_R)
// #define HOME_S LALT_T(KC_S)
// #define HOME_T LSFT_T(KC_T)

// // Right-hand home row mods
// #define HOME_N RSFT_T(KC_N)
// #define HOME_E RALT_T(KC_E)
// #define HOME_I RCTL_T(KC_I)
// #define HOME_O RGUI_T(KC_O)

/* QWERTY_SET2 */
// Left-hand home row mods
#define S_HOME_A LGUI_T(KC_A)
#define S_HOME_S LCTL_T(KC_S)
#define S_HOME_D LALT_T(KC_D)
#define S_HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define S_HOME_J RSFT_T(KC_J)
#define S_HOME_K LALT_T(KC_K)
#define S_HOME_L RCTL_T(KC_L)
#define S_HOME_SCLN RGUI_T(KC_SCLN)

/* LT KEYS */
// Layer-tab key mods
#define MEDIA_ESC LT(_MEDIA,KC_ESC)
#define NAV_SPC LT(_NAV,KC_SPC)
#define MOUSE_TAB LT(_MOUSE,KC_TAB)
#define SYM_ENT LT(_SYM,KC_ENT)
#define NUM_BSPC LT(_NUM,KC_BSPC)
#define FUN_DEL LT(_FUN,KC_DEL)

#define COPY LCTL(KC_C)
#define PSTE LCTL(KC_V)
#define CUT LCTL(KC_X)
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)

// Special Key
#define FULL LALT_T(KC_ENT)