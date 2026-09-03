#pragma once

// --- RP2040: double-tap reset to enter bootloader ---
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500

// --- TYPING ---
#define TAPPING_TERM 250

// Pausa entre los taps que genera tap_code/tap_code16. Necesario para las
// teclas muertas (` ^ ~) del keymap: sin esto, el símbolo y el espacio que lo
// "suelta" pueden llegar desordenados al SO y salir el carácter equivocado.
#define TAP_CODE_DELAY 10

// --- RGB MATRIX ---
#define RGB_MATRIX_TIMEOUT 60000   // turn off LEDs after 60s of inactivity
#define RGB_MATRIX_SLEEP           // turn off LEDs when host suspends or powers off

