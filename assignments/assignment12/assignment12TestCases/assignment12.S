#include <avr/io.h>

.global hasAOne
hasAOne:
  ori r24, 0
  ret

.global byteToAscii
byteToAscii:
  adiw r24, 0x30
  ret

.global int8ToInt
int8ToInt:
  // TODO
  ret

.global addInt8ToInt
addInt8ToInt:
  // TODO
  ret

.global add4Int8
add4Int8:
  // TODO
  ret

.global average
average:
  add r24, r22
  ror r24
  ret
