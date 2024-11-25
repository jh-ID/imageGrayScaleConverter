section .data
var1 dq 255.0
section .text
bits 64
default rel

global imgCvtGrayDoubletoInt

;rcx = n
;rdx = dValues
;r8 = iValues

section .text
imgCvtGrayDoubletoInt:

 L1:
 
 movsd xmm0, [rdx]
 vmulsd xmm0, xmm0, [var1]
 CVTTSD2SI rax, xmm0
 mov [r8], rax
 
 add rdx, 8
 add r8, 4

 loop L1
 
 ret