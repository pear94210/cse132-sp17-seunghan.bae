#include <avr/io.h>
.text


.global slowDivisionUint8
slowDivisionUint8:
  ldi r26, 0x41
  ldi r27, 0
  ldi r20, 0
whileOne:
  cp r24, r22
  brlo exit_whileOne
  inc r20
  sub r24, r22
  jmp whileOne
exit_whileOne:
  mov r24, r20
  ret


.global cStringLength
cStringLength:
  ldi r26, lo8(cStringLength)
  ldi r27, hi8(cStringLength)
  ldi r22, 0
whileTwo:
  ld r18, X+
  cp r18, 0
  breq exit_whileTwo
  inc r22
  jmp whileTwo
exit_whileTwo:
  mov r24, r22
  ret

.global sumArray
sumArray:
  ldi r26, lo8(sumArray)
  ldi r27, hi8(sumArray)
  ldi r20, 0
whileThree:
  cp r22, 0
  breq exit_whileThree
  dec r22
  ld r18, X+
  add r20, r18
  adc r21, 0
  jmp whileThree
exit_whileThree:
  mov r24, r20
  mov r25, r21
  ret


.global greaterThanOrEqualUInt16
greaterThanOrEqualUInt16:
  cp r25, r23
  brlo false_body
  brne true_body
  cp r24, r22
  brge true_body
  ldi r24, 0
  jmp main_body
true_body:
  ldi r24, 1
  jmp main_body
false_body:
  ldi r24, 0
main_body:
  ldi r25, 0
  ret


.global slowDivisionUint16
slowDivisionUint16:
  // TODO: uint16_t slowDivisionUint16(uint16_t a, uint16_t b)
  ret


.global avgArray
avgArray:
  // TODO: uint16_t avgArray(uint8_t a[], uint8_t length)
  ret


