qmk compile -kb crkbd/rev1 -km default -e CONVERT_TO=rp2040_ce
qmk flash -kb crkbd/rev1 -km Diselic0 -e CONVERT_TO=rp2040_ce

How to flush it manually.

0. Entrar en modo boot:
  Desconecta el cable USB del teclado.

  Usa un cable o clip para hacer puente entre el pin BOOT y cualquier pin GND.

  Mientras mantienes el puente hecho, conecta el cable USB al ordenador.

  Espera un par de segundos y suelta el puente.

1. Asegurar que la carpeta existe:
  ls /mnt/pico
  sudo mkdir -p /mnt/pico

2. Montar la unidad:
  sudo mount /dev/disk/by-label/RPI-RP2 /mnt/pico

3. Copiar el archivo:
  sudo cp .build/crkbd_rev1_diselico_rp2040_ce.uf2 /mnt/pico/

4. Desmontar:
  sudo unmount /mnt/pico
