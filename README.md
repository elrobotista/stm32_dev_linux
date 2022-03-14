# stm32_dev_linux
Un hola mundo para embebidos utilizando una nucleof303re en Linux con la librería openlibcm3.

## Clonar y compilar openlibcm3
No olvides clonar la librería openlibcm3 una vez que clones este repositorio:
``` bash
git submodule update --init
```
Una vez clonada la librería, no olvides compilarla:
``` bash
cd libopencm3 && make
```

## Compilar appl
Para compilar el proyecto, entra a a la carpeta `appl` ejecuta `make`
``` bash
cd appl && make
```

## Flashing
Para flashear el binario `blinky.bin` en el microcontrolador:
``` bash
st-flash --reset write blinky.bin 0x8000000
```

## Nota
Esta mini-guía asume que ya tienes instaladas las herramientas necesarias para compilar y flashear el código en tu stm32.
Para un tutorial detallado cómo hacer esto, vista https://elrobotista.com/stm322_dev_linux.
