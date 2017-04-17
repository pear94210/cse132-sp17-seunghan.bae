#include <avr/io.h>

.global hasAOne
hasAOne:
  ori r24, 0x00
  ret

.global byteToAscii
byteToAscii:
  adiw r24, 0x30
  ret

.global int8ToInt
int8ToInt:
  ldi r25, 0xff
  sbrs r24, 7
  ldi r25, 0x00
  ret

.global addInt8ToInt
addInt8ToInt:
  call int8ToInt
  add r24, r22
  adc r25, r23
  ret

.global add4Int8
add4Int8:
  mov r26, r22
  call int8ToInt
  movw r22, r24
  mov r24, r26
  call addInt8ToInt
  movw r22, r24
  mov r24, r20
  call addInt8ToInt
  movw r22, r24
  mov r24, r18
  call addInt8ToInt
  ret

.global average
average:
  add r24, r22
  ror r24
  ret
