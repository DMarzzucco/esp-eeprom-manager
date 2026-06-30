# esp-eeprom-manager

chip: esp8266
placa: WeMos D1 mini
memory EEPROM:ST m95m04rd

- Hace un componente que lea y escriba por bytes y/o bloques
- Leer lo registros y determinar que memoria es y su tamaño
- Crea un sistema que divida la memoria en secciones para crea una especi de sistemas de bloques para almacenar datos

wemos placa:    | placa del eeprom
                |
D8 -> CS        | pin 1
D6 -> DO/MISO   | pin 2
3V3 -> VCC      | pin 3                            
G -> GND        | pin 4                            
D7 -> DI/MOSI   | pin 5
D5 -> CLK/SCK   | pin 6
3V3 -> VCC      | pin 7                            
3V3 -> VCC      | pin 8


## falta 
- pint 3 (WP#)
- pint 7 (HOLD#)


WP# conectado a VCC.
HOLD# conectado a VCC.

* unir tres cables con uno que vaya al pin 3V3 (por ejemplo, con una regleta, un conector tipo Wago, soldándolos temporalmente, etc.).

1 = 5 / MOSI
2 = 2 / MISO
3 = 6 / CLOCK
4 = nada
5 = 1 / Chip Select 
6 =  7 / #HOLD
7 = 3 / #WP
8 = nada
9 = 8 / VCC
10 = 4 / GND