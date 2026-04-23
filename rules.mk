# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# Build Options
#   change to "no" to disable the options
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration (Hold ESC to boot)
#MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug (Activa /dev/ttyACM0 en Linux)
COMMAND_ENABLE = yes        # Commands for debug and configuration
NKRO_ENABLE = yes           # USB Nkey Rollover
#BACKLIGHT_ENABLE = no
#RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
OLED_ENABLE = yes           # OLED display
WPM_ENABLE = yes            # WPM counter (required for OLED)
ENCODER_ENABLE = no        # Encoder
LTO_ENABLE = yes            # L:underglowink Time Optimization (smaller binary)
