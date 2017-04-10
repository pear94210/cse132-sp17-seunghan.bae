#include <avr/io.h>

; AVR assembly comments start with a semicolon 
// (or a double slash, like C)
; Lines without labels should be indented once.

; You can "call printRegs" in your code to help you understand the register values and how they change.

.global giveMeMax
giveMeMax:
  ldi r24, 0xff // Load the value 0xff into register 24
  ret

.global giveMeZero
giveMeZero:
  ldi r24, 0
  ret

.global addFour
addFour:
  call printRegs
  ldi r18, 4
  add r24, r18
  call printRegs
  ret

.global turnOnLight
turnOnLight:
  sbi _SFR_IO_ADDR(DDRB), PIN5
  sbi _SFR_IO_ADDR(PORTB), PIN5
  cbi _SFR_IO_ADDR(PORTB), PIN5
  ret
