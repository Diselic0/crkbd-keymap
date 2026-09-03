#include QMK_KEYBOARD_H
#include "keymap_spanish.h"

// --- DEFINICIONES MANUALES PARA ESPAÑOL ISO ---
// Red de seguridad: si tu versión de keymap_spanish.h no trae estos nombres,
// los definimos aquí. En el QMK actual ya existen, así que estos #ifndef
// normalmente no llegan a activarse.
#ifndef ES_LABK
#define ES_LABK KC_NUBS          // < (Tecla a la izquierda de Z)
#endif

#ifndef ES_RABK
#define ES_RABK LSFT(KC_NUBS)    // > (Shift + <)
#endif

// Definimos las capas
enum corne_layers {
    _BASE,
    _SYMB,
    _NUMP,
    _TUNE,
    _LAYER_COUNT             // NO es una capa: lo usa el OLED para saber
                             // cuántas hay. Mantener siempre al final.
};

/* * TECLAS MUERTAS (dead keys) EN ESPAÑOL
 * En el layout ES, las teclas ` ^ ~ no escriben nada por sí solas: esperan a
 * la siguiente letra para acentuarla (à, ê, ñ...). Para escribir el símbolo
 * suelto hay que pulsar espacio después.
 * Estos keycodes personalizados hacen ese "+ espacio" por ti.
 * Si algún día prefieres el comportamiento de tecla muerta real (para escribir
 * â, ê...), pon ES_GRV / ES_CIRC / ES_TILD en la capa en vez de SY_*.
 */
enum custom_keycodes {
    SY_GRV = SAFE_RANGE,     // `
    SY_CIRC,                 // ^
    SY_TILD                  // ~
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
#define HRM_L   MT(MOD_LALT, ES_L)   // Tocar: L, Mantener: Alt  <- OJO: LALT a propósito.
                                     //   En ES, MOD_RALT es AltGr, no Alt.
#define HRM_N   MT(MOD_RGUI, ES_NTIL)// Tocar: Ñ, Mantener: Super (Win/Cmd)

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
 * | Tab/Num| A/Gui| S/Alt| D/Ctl| F/Sft|   G  |      |       |   H  | J/Sft| K/Ctl| L/Alt| Ñ/Gui|    ´   |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * |  Ctrl  |   Z  |   X  |   C  |   V  |   B  |      |       |   N  |   M  |   ,  |   .  |   -  | RShift |
 * └--------+------+------+------+------+------+------┘       └------+------+------+------+------+--------┘
 * | GUI  | Symb | Enter|                 | Space| Num  | AltGr|
 * └--------------------┘                 └--------------------┘
 * Nota: los Shift principales están en F y J (home row mods). El meñique
 * izquierdo hace Esc al tocar y Ctrl al mantener.
 */
[_BASE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    CTL_T(KC_ESC),      ES_Q,  ES_W,  ES_E,  ES_R,  ES_T,                         ES_Y,  ES_U,    ES_I,   ES_O,    ES_P,  KC_BSPC,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    LT(_NUMP,KC_TAB),  HRM_A, HRM_S, HRM_D, HRM_F,  ES_G,                         ES_H, HRM_J,   HRM_K,  HRM_L,   HRM_N,  ES_ACUT,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL,            ES_Z,  ES_X,  ES_C,  ES_V,  ES_B,                         ES_N,  ES_M, ES_COMM, ES_DOT, ES_MINS,  KC_RSFT,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_LGUI, MO(_SYMB), KC_ENT,   KC_SPC, MO(_NUMP), KC_RALT
                                //`--------------------------'  `--------------------------'
),

/*
 * Capa _SYMB (Símbolos para Programación) — pulgar izquierdo
 * ┌--------------------------------------------------┐       ┌--------------------------------------------------┐
 * | (Esc)  |   !  |   "  |   #  |   $  |   %  |      |       |   &  |   /  |   (  |   )  |   =  |(Backsp)|
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * | (Tab)  |   \  |   @  |   €  |   '  |   ~  |      |       |   ^  |   <  |   {  |   }  |   >  |   +    |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * | (Ctrl) |   ¡  |   |  |   ç  |   `  |      |      |       |   _  |   *  |   [  |   ]  |   ¿  |   ?    |
 * └--------+------+------+------+------+------+------┘       └------+------+------+------+------+--------┘
 * | GUI  |  --  | Enter|                 | Space| Num  | AltGr|
 * └--------------------┘                 └--------------------┘
 *
 * Fila 1 = la fila de números con Shift, en su orden natural: ! " # $ % & / ( ) =
 *          El '·' inútil de Shift+3 se sustituye por '#', que además cae en la
 *          misma posición que en un teclado US.
 * Fila 2 = símbolos de AltGr + la comilla simple ' en el índice (posición F),
 *          uno de los sitios más rápidos de la capa.
 * Fila 3 = lo que quedaba fuera: ¡ | ç ` _ * [ ] ¿ ?
 *          Mnemónicos: '|' justo debajo de '\', 'ç' en la posición de C,
 *          '¡' en el meñique izquierdo espejando '¿' en el derecho.
 *
 * Las teclas en (paréntesis) son transparentes: se heredan de _BASE, así que
 * Esc, Tab, Ctrl, Backspace y los 6 pulgares no se mueven nunca.
 */
[_SYMB] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______, ES_EXLM, ES_DQUO, ES_HASH,  ES_DLR, ES_PERC,                      ES_AMPR, ES_SLSH, ES_LPRN, ES_RPRN,  ES_EQL, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, ES_BSLS,   ES_AT, ES_EURO, ES_QUOT, SY_TILD,                      SY_CIRC, ES_LABK, ES_LCBR, ES_RCBR, ES_RABK, ES_PLUS,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, ES_IEXL, ES_PIPE, ES_CCED,  SY_GRV, XXXXXXX,                      ES_UNDS, ES_ASTR, ES_LBRC, ES_RBRC, ES_IQUE, ES_QUES,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, _______, _______,   _______, _______, _______
                                //`--------------------------'  `--------------------------'
),

/*
 * Capa _NUMP (Números y Navegación) — pulgar derecho, o mantener Tab
 * ┌--------------------------------------------------┐       ┌--------------------------------------------------┐
 * | (Esc)  |   1  |   2  |   3  |   4  |   5  |      |       |   6  |   7  |   8  |   9  |   0  |  Del   |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * | (Tab)  | GUI  | Alt  | Ctrl | Shift|      |      |       | Left | Down |  Up  | Right|      |  (´)   |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * | (Ctrl) |   +  |   -  |   *  |   /  |   =  |      |       | Home | PgDn | PgUp | End  | Ins  | (Sft)  |
 * └--------+------+------+------+------+------+------┘       └------+------+------+------+------+--------┘
 * | GUI  | Symb | Enter|                 | Space|  --  | AltGr|
 * └--------------------┘                 └--------------------┘
 *
 * - Mods puros en la home row izquierda: te permite hacer Ctrl+Shift+flecha,
 *   Alt+flecha o GUI+flecha (tiling) sin salir de la posición base.
 * - Home/PgDn/PgUp/End caen justo debajo de su flecha correspondiente.
 * - Operadores en la fila 3 izquierda: la capa funciona como calculadora.
 * - Los controles multimedia se han movido a _TUNE.
 */
[_NUMP] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    _______,    ES_1,    ES_2,    ES_3,    ES_4,    ES_5,                         ES_6,    ES_7,    ES_8,     ES_9,    ES_0,  KC_DEL,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT, XXXXXXX, _______,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, ES_PLUS, ES_MINS, ES_ASTR, ES_SLSH,  ES_EQL,                      KC_HOME, KC_PGDN, KC_PGUP,   KC_END,  KC_INS, _______,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, _______, _______,   _______, _______, _______
                                //`--------------------------'  `--------------------------'
),

/*
 * Capa _TUNE (F-keys, Multimedia y RGB) — se activa con SYMB + NUMP a la vez
 * ┌--------------------------------------------------┐       ┌--------------------------------------------------┐
 * |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |      |       |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * | (Tab)  | GUI  | Alt  | Ctrl | Shift|      |      |       | Prev | Vol- | Vol+ | Next | Mute |  Play  |
 * |--------+------+------+------+------+------|      |       |------+------+------+------+------+--------|
 * | (Ctrl) | BOOT |EE Clr|Debug |RGB on|RGB ->|      |       | Hue- | Hue+ | Sat- | Sat+ | Val- |  Val+  |
 * └--------+------+------+------+------+------+------┘       └------+------+------+------+------+--------┘
 * | GUI  | Symb | Enter|                 | Space| Num  | AltGr|
 * └--------------------┘                 └--------------------┘
 *
 * - F1..F12 ocupan la fila superior entera (12 teclas, encaje exacto).
 *   OJO: mientras mantienes esta capa, esa fila NO tiene Esc ni Backspace,
 *   porque F1 y F12 ocupan sus posiciones. Es el precio de tener las 12
 *   F-keys alineadas; en el resto de capas Esc y Backspace siguen ahí.
 * - Los mods de la fila 2 permiten Alt+F4, Ctrl+F5, Shift+F10, etc.
 * - Debug (DB_TOGG) apaga/enciende el uprintf de process_record_user sin
 *   tener que recompilar.
 * - QK_BOOT resetea la mitad que actúa de master. Para flashear la otra mitad
 *   usa el doble tap en RESET o el puente BOOT-GND (ver Readme.txt).
 */
[_TUNE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                           KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, KC_MPLY,
    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, QK_BOOT,  EE_CLR, DB_TOGG, RM_TOGG, RM_NEXT,                      RM_HUED, RM_HUEU, RM_SATD, RM_SATU, RM_VALD, RM_VALU,
    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, _______, _______,   _______, _______, _______
                                //`--------------------------'  `--------------------------'
)
};

/* * TRI-LAYER
 * _TUNE se activa manteniendo _SYMB y _NUMP a la vez, en cualquier orden.
 * Como los pulgares son transparentes en todas las capas, funciona igual con
 * el pulgar izquierdo + pulgar derecho que con Tab (mantenido) + pulgar izquierdo.
 */
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYMB, _NUMP, _TUNE);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        // Teclas muertas: emitimos el símbolo y un espacio para "soltarlo".
        switch (keycode) {
            case SY_GRV:  tap_code16(ES_GRV);  tap_code(KC_SPC); return false;
            case SY_CIRC: tap_code16(ES_CIRC); tap_code(KC_SPC); return false;
            case SY_TILD: tap_code16(ES_TILD); tap_code(KC_SPC); return false;
        }

#ifdef CONSOLE_ENABLE
        // Si pulsas una tecla, imprime en consola
        uprintf("Tecla: 0x%04X\n", keycode);
#endif
    }
    return true;
}

#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
    // Esperar a que el USB de Linux arranque
    wait_ms(500);

    // Activar debug
    debug_enable = true;
}
#endif

#ifdef ENCODER_MAP_ENABLE
/* NOTA: ahora mismo esto es código muerto. rules.mk tiene ENCODER_ENABLE = no
 * y crkbd/rev1 no declara encoders, así que este bloque no se compila.
 * Se mantiene por si algún día montas encoders: entonces habría que poner
 * ENCODER_ENABLE = yes y ENCODER_MAP_ENABLE = yes en rules.mk, y ajustar el
 * número de entradas a los encoders que tengas realmente.
 */
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_LEFT, KC_RGHT), },
  [_SYMB] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_LEFT, KC_RGHT), },
  [_NUMP] = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(C(ES_Z), C(ES_Y)), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_LEFT, KC_RGHT), },
  [_TUNE] = { ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_NEXT, RM_NEXT), },
};

#endif

#ifdef OLED_ENABLE

// --- Isometric plate geometry ---
static const uint8_t PROGMEM rh_xl[11] = {16,13,10, 8, 5, 2, 5, 8,10,13,16};
static const uint8_t PROGMEM rh_xr[11] = {16,19,22,24,27,30,27,24,22,19,16};

static const uint8_t PROGMEM dp_lx[6] = { 2, 5, 8,10,13,16};
static const uint8_t PROGMEM dp_rx[6] = {30,27,24,22,19,16};

// 4×5 pixel glyphs (column-major, bit0=top): B, S, N, T
// El orden DEBE coincidir con enum corne_layers.
static const uint8_t PROGMEM glyphs[_LAYER_COUNT][4] = {
    {0x1F, 0x15, 0x15, 0x0A},  // B
    {0x12, 0x15, 0x15, 0x09},  // S
    {0x1F, 0x02, 0x04, 0x1F},  // N
    {0x01, 0x1F, 0x1F, 0x01},  // T
};

// Layer 0=BASE (bottom, y=63) .. 3=TUNE (top, y=15)
static const uint8_t PROGMEM plate_y[_LAYER_COUNT] = {63, 47, 31, 15};

static void draw_glyph(uint8_t x0, uint8_t y0, uint8_t gi, bool invert) {
    for (uint8_t col = 0; col < 4; col++) {
        uint8_t bits = pgm_read_byte(&glyphs[gi][col]);
        for (uint8_t row = 0; row < 5; row++) {
            bool on = (bits >> row) & 1;
            oled_write_pixel(x0 + col, y0 + row, invert ? !on : on);
        }
    }
}

static void draw_plate(uint8_t top_y, uint8_t gi, bool active) {
    for (uint8_t dy = 0; dy < 11; dy++) {
        uint8_t xl = pgm_read_byte(&rh_xl[dy]);
        uint8_t xr = pgm_read_byte(&rh_xr[dy]);
        if (active) {
            for (uint8_t x = xl; x <= xr; x++)
                oled_write_pixel(x, top_y + dy, true);
        } else {
            oled_write_pixel(xl, top_y + dy, true);
            if (xl != xr) oled_write_pixel(xr, top_y + dy, true);
        }
    }

    if (active) {
        for (uint8_t ddy = 0; ddy < 6; ddy++) {
            uint8_t row = top_y + 10 + ddy;
            uint8_t lx  = pgm_read_byte(&dp_lx[ddy]);
            uint8_t rx  = pgm_read_byte(&dp_rx[ddy]);
            for (uint8_t x = lx; x <= rx; x++)
                oled_write_pixel(x, row, true);
        }
    }

    draw_glyph(14, top_y + 3, gi, active);
}

static void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;
    return OLED_ROTATION_270;  // portrait: 32×128 px
}

bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        oled_render_logo();
        return false;
    }

    oled_clear();

    uint8_t active = get_highest_layer(layer_state);
    if (active >= _LAYER_COUNT) active = _LAYER_COUNT - 1;  // por si acaso

    for (uint8_t i = 0; i < _LAYER_COUNT; i++) {
        if (i != active)
            draw_plate(pgm_read_byte(&plate_y[i]), i, false);
    }
    draw_plate(pgm_read_byte(&plate_y[active]), active, true);

    // Separator line
    for (uint8_t x = 2; x <= 30; x++)
        oled_write_pixel(x, 92, true);

    // WPM label and value
    oled_set_cursor(0, 12);
    oled_write_P(PSTR("WPM"), false);
    oled_set_cursor(0, 13);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);

    // WPM progress bar (max 28px wide at 120 WPM)
    uint8_t wpm = get_current_wpm();
    uint8_t bar = (wpm >= 120) ? 28 : (uint8_t)(wpm * 28 / 120);
    for (uint8_t x = 2; x < 2 + bar; x++) {
        oled_write_pixel(x, 118, true);
        oled_write_pixel(x, 119, true);
    }

    return false;
}

#endif // OLED_ENABLE
