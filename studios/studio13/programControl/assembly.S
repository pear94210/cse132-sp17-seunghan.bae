#include <avr/io.h>


// TODO: Complete functions!

.global lessThan
lessThan:
  cp r24, r22
  brge notLessThan
  ldi r24, 1
  jmp retLessThan
notLessThan:
  ldi r24, 0
retLessThan:
  ret

.global lessThanOrEqualUnsigned
lessThanOrEqualUnsigned:
  cp r22, r24
  brlo notLessThanOrEqualUnsigned
  ldi r24, 1
  jmp retLessThanOrEqualUnsigned
notLessThanOrEqualUnsigned:
  ldi r24, 0
retLessThanOrEqualUnsigned:
  ret

.global slowMultiply
slowMultiply:
  ldi r20, 0
  ldi r18, 0
loopSlowMultiply:
  cp r18, r24
  brsh retSlowMultiply
  add r20, r22
  inc r18
  jmp loopSlowMultiply
retSlowMultiply:
  mov r24, r20
  ret

.global slowExponent
slowExponent:
  ldi r21, 1
  ldi r20, 0
loopSlowExponent:
  cp r20, r22
  brsh retSlowExponent
  ldi r19, 0
  ldi r18, 0
innerLoopSlowExponent:
  cp r18, r24
  brsh exitInnerLoop
  add r19, r21
  inc r18
  jmp innerLoopSlowExponent
exitInnerLoop:
  mov r21, r19
  inc r20
  jmp loopSlowExponent
retSlowExponent:
  mov r24, r21
  ret
