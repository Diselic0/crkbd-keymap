#pragma once

// --- RP2040: double-tap reset to enter bootloader ---
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500

// --- TYPING ---
#define TAPPING_TERM 250

// --- RGB MATRIX ---
#define RGB_MATRIX_TIMEOUT 60000   // turn off LEDs after 60s of inactivity
#define RGB_MATRIX_SLEEP           // turn off LEDs when host suspends or powers off

