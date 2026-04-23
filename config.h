/*
 * config.h optimizado con Double Tap Reset
 */
#pragma once

// --- CRUCIAL PARA RP2040 ---
// Esto activa la función de pulsar el botón de Reset dos veces rápido
// para entrar en modo Bootloader (unidad USB).
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500 // 500ms para hacer el segundo click

// --- AJUSTES DE ESCRITURA ---
#define TAPPING_TERM 250
//#define IGNORE_MOD_TAP_INTERRUPT

// --- RGB ---
#ifdef RGBLIGHT_ENABLE
    //#define RGBLIGHT_SPLIT              // Necesario para teclados divididos

    // CORRECCIÓN DE PIN:
    // GP3 es el pin D3 en Pro Micro RP2040 (donde van los LEDs en Corne)
    #undef RGB_DI_PIN
    #define RGB_DI_PIN GP3

    // Configuración Básica
    #define RGBLIGHT_LIMIT_VAL 150      // Brillo máximo (max 255)
    #define RGBLIGHT_HUE_STEP 10        // Pasos para cambiar color
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17

    // --- MODO SÓLIDO POR DEFECTO ---
    // Esto asegura que arranque con un color fijo, sin animaciones.
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
    #define RGBLIGHT_DEFAULT_ON true    // Siempre encendido al arrancar

    // Color inicial (Rojo/Magenta para que sea visible)
    #define RGBLIGHT_DEFAULT_HUE 0
    #define RGBLIGHT_DEFAULT_SAT 255
    #define RGBLIGHT_DEFAULT_VAL 120
#endif

