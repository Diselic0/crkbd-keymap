#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

// --- DEFINICIONES MANUALES PARA ESPAÑOL ISO ---
// Aseguramos que estos símbolos existan para evitar errores de "undeclared"
#ifndef ES_LESS
#define ES_LESS KC_NUBS          // < (Tecla a la izquierda de Z)
#endif

#ifndef ES_GRTR
#define ES_GRTR LSFT(KC_NUBS)    // > (Shift + <)
#endif

#ifndef ES_EQL
#define ES_EQL LSFT(KC_0)        // = (Shift + 0)
#endif

// Definimos las capas
enum corne_layers {
    _BASE,
    _SYMB,
    _NUMP,
    _TUNE
};

/* * DEFINICIÓN DE HOME ROW MODS (HRM)
 * Esto hace que las teclas actúen como letras al tocar, y modificadores al mantener.
 * MT = Mod Tap.
 * L = Left (Izquierda), R = Right (Derecha) pero funcionalmente son iguales para atajos.
 */
// Mano Izquierda
#define HRM_A   MT(MOD_LGUI, ES_A)   // Tocar: A, Mantener: Super (Win/Cmd) -> Para Tiles
#define HRM_S   MT(MOD_LALT, ES_S)   // Tocar: S, Mantener: Alt
#define HRM_D   MT(MOD_LCTL, ES_D)   // Tocar: D, Mantener: Control -> Para Vim
#define HRM_F   MT(MOD_LSFT, ES_F)   // Tocar: F, Mantener: Shift

// Mano Derecha (Espejo)
#define HRM_J   MT(MOD_RSFT, ES_J)   // Tocar: J, Mantener: Shift
#define HRM_K   MT(MOD_RCTL, ES_K)   // Tocar: K, Mantener: Control
#define HRM_L   MT(MOD_RALT, ES_L)   // Tocar: L, Mantener: Alt
#define HRM_N   MT(MOD_RGUI, ES_NTIL)// Tocar: Ñ, Mantener: Super (Win/Cmd)
#define CTL_SFT MT(MOD_LCTL, KC_LSFT)// Tocar: sift, Mantener: ctrl

/* NOTA:
 * Con esta configuración, para mover una ventana en tu Tile Manager a la izquierda:
 * Mantienes 'A' (Super) con el meñique izquierdo y pulsas 'H' (Izquierda) con el índice derecho.
 * ¡Sin mover las manos de la posición base!
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* * Capa _BASE (Con Home Row Mods)
 * ┌--------------------------------------------------┐       ┌--------------------------------------------------┐
 * | Esc/Ctl|   Q  |   W  |   E  |   R  |   T  |      |       |   Y  |   U  |   I  |   O  |   P  | Backsp |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * | Sft/Tab| A/Gui| S/Alt| D/Ctl| F/Sft|   G  |      |       |   H  | J/Sft| K/Ctl| L/Alt| Ñ/Gui|    ´   |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * |  Ctrl  |   Z  |   X  |   C  |   V  |   B  |      |       |   N  |   M  |   ,  |   .  |   -  | RShift |
 * └--------+------+------+------+------+------+------┘       └------+------+------+------+------+--------┘
 * | GUI  | Symb | Enter|                 | Space| Num  | Alt  |
 * └--------------------┘                 └--------------------┘
 * Nota: He cambiado la tecla TAB izquierda por un Shift secundario o Tab,
 * pero recuerda que tus Shifts principales ahora están en F y J.
 */
[_BASE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    CTL_T(KC_ESC),   ES_Q,    ES_W,    ES_E,    ES_R,    ES_T,                         ES_Y,    ES_U,    ES_I,    ES_O,   ES_P,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LT(_NUMP,KC_TAB), HRM_A,   HRM_S,   HRM_D,   HRM_F,   ES_G,                         ES_H,    HRM_J,   HRM_K,   HRM_L,   HRM_N, ES_ACUT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL,    ES_Z,    ES_X,    ES_C,    ES_V,    ES_B,                         ES_N,    ES_M, ES_COMM,  ES_DOT, ES_MINS, KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, MO(_SYMB), KC_ENT,     KC_SPC, MO(_NUMP), KC_LALT
                                        //`--------------------------'  `--------------------------'
),

/* * Capa _NUMP (Números y Navegación Vim)
 * ┌--------------------------------------------------┐       ┌--------------------------------------------------┐
 * |   Tab  |   1  |   2  |   3  |   4  |   5  |      |       |   6  |   7  |   8  |   9  |   0  | Del    |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * |  Ctrl  | Prev | Vol- | Vol+ | Next | Stop |      |       | Left | Down |  Up  | Right|      |        |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * | Shift  |      | Mute |      |      |      |      |       |      |      |      |      |      |        |
 * └--------+------+------+------+------+------+------┘       └------+------+------+------+------+--------┘
 * | GUI  |      | Enter|                 | Space|      | Alt  |
 * └--------------------┘                 └--------------------┘
 * He añadido controles multimedia en la mano izquierda para aprovechar el espacio libre.
 */
[_NUMP] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MSTP,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, _______, KC_ENT,     KC_SPC, _______, KC_RALT
                                        //`--------------------------'  `--------------------------'
),

/*
 * Capa _SYMB (Símbolos para Programación)
 * ┌--------------------------------------------------┐       ┌--------------------------------------------------┐
 * |   Tab  |   !  |   "  |   ·  |   $  |   %  |      |       |   &  |   /  |   (  |   )  |   =  | Backsp |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * |  Ctrl  |   \  |   @  |   €  |   ~  |      |      |       |   ^  |   <  |   {  |   }  |   >  |   +    |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * | Shift  |   |  |      |      |      |      |      |       |   _  |      |   [  |   ]  |   ¿  |   ?    |
 * └--------+------+------+------+------+------+------┘       └------+------+------+------+------+--------┘
 * | GUI  |      | Enter|                 | Space| Tune | Alt  |
 * └--------------------┘                 └--------------------┘
 */
[_SYMB] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_TAB, KC_EXLM,  KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       ES_AMPR, ES_SLSH, ES_LPRN, ES_RPRN, ES_EQL, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LCTL, ES_BSLS,   ES_AT, ES_EURO, ES_TILD, XXXXXXX,                      ES_CIRC, ES_LESS, ES_LCBR, ES_RCBR, ES_GRTR, ES_PLUS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, ES_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, XXXXXXX, ES_LBRC, ES_RBRC, ES_IQUE, ES_QUES,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, _______, KC_ENT,     KC_SPC, MO(_TUNE), KC_RALT
                                        //`--------------------------'  `--------------------------'
),


/*
 * Capa _TUNE (RGB y Configuración)
 */

[_TUNE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_LGUI, _______, KC_ENT,     KC_SPC, _______, KC_RALT
                                        //`--------------------------'  `--------------------------'
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Si pulsas una tecla, imprime en consola
    if (record->event.pressed) {
        uprintf("Tecla: 0x%04X\n", keycode);
    }
    return true;
}

void keyboard_post_init_user(void) {
    // Esperar a que el USB de Linux arranque
    wait_ms(500);

    // Activar debug
    debug_enable = true;

    // Forzar LEDs encendidos si RGBLIGHT está activo
    #ifdef RGBLIGHT_ENABLE
        rgblight_enable_noeeprom(); // Enciende sin depender de memoria guardada
        rgblight_sethsv_noeeprom(HSV_MAGENTA); // Color Magenta por defecto para test
        rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL);
    #endif
}

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [_NUMP] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [_SYMB] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [_TUNE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};

#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE: oled_write_ln_P(PSTR("Baseeeee"), false); break;
        case _SYMB: oled_write_ln_P(PSTR("Symb"), false); break;
        case _NUMP: oled_write_ln_P(PSTR("Nump"), false); break;
        case _TUNE: oled_write_ln_P(PSTR("Tune"), false); break;
        default: oled_write_ln_P(PSTR("Undef"), false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif
