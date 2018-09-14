#include "chocopad.h"

#define _BASE 0
#define _FN1 1
#define _FN2 2

// Fillers to make layering more clear
#define KC_ KC_TRNS
#define KC_XX KC_NO

#define KC_L1 LT(1, KC_P0)
#define KC_L2 LT(2, KC_SPC)
#define KC_RST RESET
#define KC_BSTP BL_STEP
#define KC_RTOG RGB_TOG
#define KC_RMOD RGB_MOD
#define KC_RHUI RGB_HUI
#define KC_RHUD RGB_HUD
#define KC_RSAI RGB_SAI
#define KC_RSAD RGB_SAD
#define KC_RVAI RGB_VAI
#define KC_RVAD RGB_VAD

#define KC_MAC1 ADMIN
#define KC_MAC2 SMSPC
#define KC_M192 M192
#define KC_M255 M255

#define KC_SP SPOTIFY
#define KC_LK LOCK
#define KC_AR ARABIC
#define KC_TR TERMINAL
#define KC_IJ INTELLIJ
#define KC_PROSW PROGSWITCH
#define KC_TUP THUMBSUP

#define KC_CS SS_LGUI(SS_TAP(X_SPACE))
#define KC_ER SS_TAP(X_ENTER)

enum custom_keycodes {
  NUMPAD = SAFE_RANGE,
  SPOTIFY, 
  LOCK,    
  ARABIC,  
  TERMINAL,
  PROGSWITCH,
  INTELLIJ,
  THUMBSUP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_ortho_4x4(
  //,-------+-------+-------+-------.
      KC_LK , KC_SP , KC_AR , KC_TR ,
  //|-------+-------+-------+-------|
      KC_IJ, KC_NO  ,KC_PROSW,KC_TUP,
  //|-------+-------+-------+-------|
     KC_WH_D,KC_BTN1,KC_MS_U,KC_BTN2,
  //|-------+-------+-------+-------|
     KC_WH_U,KC_MS_L,KC_MS_D,KC_MS_R
  //|-------+-------+-------+-------|
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SPOTIFY:
      if (record->event.pressed) {
	SEND_STRING(KC_CS);
    _delay_ms(50);
	SEND_STRING("Spotify");
    _delay_ms(100);
	SEND_STRING(KC_ER);
      }
      return false;
      break;
    case LOCK:
      if (record->event.pressed) {
	SEND_STRING(SS_LGUI(SS_LCTRL(SS_TAP(X_Q))));
      }
      return false;
      break;
    case THUMBSUP:
      if (record->event.pressed) {
	SEND_STRING(":");
    _delay_ms(50);
	SEND_STRING(KC_ER);
    _delay_ms(50);
	SEND_STRING(SS_LGUI(KC_ER));
      }
      return false;
      break;
    case ARABIC:
      if (record->event.pressed) {
	SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_SPACE))));
      }
      return false;
      break;
    case INTELLIJ:
      if (record->event.pressed) {
	SEND_STRING(KC_CS);
    _delay_ms(50);
	SEND_STRING("intellij");
    _delay_ms(100);
	SEND_STRING(KC_ER);
      }
      return false;
      break;
    case TERMINAL:
      if (record->event.pressed) {
	SEND_STRING(KC_CS);
    _delay_ms(50);
	SEND_STRING("iTerm");
    _delay_ms(100);
	SEND_STRING(KC_ER);
      }
      return false;
      break;
    case PROGSWITCH:
      if (record->event.pressed) {
	SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_TAB))));
      }
      return false;
      break;
  }
  return true;
};
