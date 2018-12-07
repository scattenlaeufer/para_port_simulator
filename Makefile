ARDUINO_PLATFORM_LIB_PATH = /usr/share/arduino/hardware/archlinux-arduino/avr/libraries
ARDUINO_VAR_PATH = /usr/share/arduino/hardware/archlinux-arduino/avr/variants
BOARDS_TXT = /usr/share/arduino/hardware/archlinux-arduino/avr/boards.txt
ARDUINO_CORE_PATH = /usr/share/arduino/hardware/archlinux-arduino/avr/cores/arduino

BOARD_TAG = nano
BOARD_SUB = atmega328old
MONITOR_PORT  = /dev/ttyUSB0

include /usr/share/arduino/Arduino.mk
