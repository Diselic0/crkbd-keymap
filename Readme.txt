# crkbd diselico keymap

## Compilar y flashear (método rápido)

1. Compilar:
   qmk compile -kb crkbd/rev1 -km diselico -e CONVERT_TO=rp2040_ce

2. Entrar en modo bootloader:
   Doble tap rápido en el botón RESET del teclado.
   El teclado aparecerá como una unidad USB llamada RPI-RP2.

3. Montar y copiar el firmware:
   sudo mkdir -p /mnt/pico
   sudo mount /dev/disk/by-label/RPI-RP2 /mnt/pico
   sudo cp ~/qmk_firmware/crkbd_rev1_diselico_rp2040_ce.uf2 /mnt/pico/

   El teclado se reinicia solo al terminar la copia.

---

## Método alternativo para entrar en bootloader (si el doble tap no funciona)

   Desconecta el cable USB.
   Haz puente entre el pin BOOT y cualquier pin GND.
   Mientras mantienes el puente, conecta el cable USB.
   Espera un par de segundos y suelta el puente.

---

## Desmontar manualmente (si fuera necesario)

   sudo umount /mnt/pico
