
;<Program title>

jmp start

;data


;code
start: nop
lda 8500
mov b, a
lda 8501
add b
sta 8502
rst 1


hlt