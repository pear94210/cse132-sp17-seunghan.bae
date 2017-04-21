#include <avr/io.h>
.text


.global slowDivisionUint8
slowDivisionUint8:
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
  movw r26, r24
  ldi r22, 0
whileTwo:
  ld r18, X+
  cp r18, r1
  breq exit_whileTwo
  inc r22
  jmp whileTwo
exit_whileTwo:
  mov r24, r22
  ret

.global sumArray
sumArray:
  movw r26, r24
  ldi r20, 0
  ldi r21, 0
whileThree:
  cp r22, r1
  breq exit_whileThree
  dec r22
  ld r18, X+
  ldi r19, 0
  add r20, r18
  adc r21, r19
  jmp whileThree
exit_whileThree:
  movw r24, r20
  ret


.global greaterThanOrEqualUInt16
greaterThanOrEqualUInt16:
  cp r25, r23
  brlo false_body
  brne true_body
  cp r24, r22
  brsh true_body
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
  ldi r20, 0
  ldi r21, 0
whileFour:
  movw r18, r24
  call greaterThanOrEqualUInt16
  cp r24, r1
  breq exit_whileFour
  ldi r26, 1
  add r20, r26
  adc r21, r1
  sub r18, r22
  sbc r19, r23
  movw r24, r18
  jmp whileFour
exit_whileFour:
  movw r24, r20
  ret


.global avgArray
avgArray:
  movw r30, r22
  call sumArray
  movw r22, r30
  call slowDivisionUint16
  ret


