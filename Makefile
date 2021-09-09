MCU=atmega32u4
F_CPU=16000000
CC=avr-gcc
OBJCOPY=avr-objcopy
CFLAGS=-std=c99 -Wall -g -Og -mmcu=${MCU} -DF_CPU=${F_CPU} -I./includes -v -v
TARGET=builds/main
SRCS=src/main.c
PROGRAMMER=avr109
PORT=/dev/cu.usbmodem14501

all:
	${CC} ${CFLAGS} -o ${TARGET}.bin ${SRCS}
	${OBJCOPY} -j .text -j .data -O ihex ${TARGET}.bin ${TARGET}.hex

flash:
	avrdude -p ${MCU} -P ${PORT} -c ${PROGRAMMER} -v -v -U flash:w:${TARGET}.hex -F

clean:
	rm -f builds/*
