section .text
global ft_atoi_base

ft_atoi_base:
  xor rax, rax
  xor rdx, rdx

.loop_base_parsing:
  mov cl, BYTE [rsi + rdx]
  test cl, cl
  je .continue_parsing

  mov r8, rdx
  add r8, 1
  .loop_doublon:
    mov r9b, BYTE[rsi + r8]
    test r9b, r9b
    je .continue_loop_base_parsing
    cmp r9b, cl
    je .error
    inc r8
    jmp .loop_doublon

.continue_loop_base_parsing:
  cmp cl, '+'
  je .error
  cmp cl, '-'
  je .error
  cmp cl, ' '
  je .error
  cmp cl, 9
  jl .end_loop_base_parsing
  cmp cl, 13
  jg .end_loop_base_parsing
  jmp .error

.end_loop_base_parsing:
  inc rdx
  jmp .loop_base_parsing

.continue_parsing:
  cmp rdx, 2
  jl .error

  xor r8, r8
  mov r9, 1

.loop_parsing_whitespace:
  mov cl, BYTE[rdi + r8]

  cmp cl, ' '
  je .end_loop_parsing_whitespace
  cmp cl, 9
  jl .loop_parsing_sign
  cmp cl, 13
  jg .loop_parsing_sign
  jmp .end_loop_parsing_whitespace

.end_loop_parsing_whitespace:
  inc r8
  jmp .loop_parsing_whitespace

.loop_parsing_sign:
  mov cl, BYTE[rdi + r8]

  cmp cl, '+'
  je .end_loop_parsing_sign
  cmp cl, '-'
  jne .loop_calcul_value
  neg r9
  jmp .end_loop_parsing_sign

.end_loop_parsing_sign:
  inc r8
  jmp .loop_parsing_sign

.loop_calcul_value:
  mov cl, BYTE[rdi + r8]
  test cl, cl
  je .done

  xor r10, r10

  .loop_base:
    mov r11b, BYTE[rsi + r10]
    test r11b, r11b
    je .end_loop_calcul_value
    cmp r11b, cl
    je .end_loop_calcul_value
    inc r10
    jmp .loop_base

.end_loop_calcul_value:
  cmp r10, rdx
  je .done
  imul rax, rdx
  add rax, r10
  inc r8
  jmp .loop_calcul_value

.done:
  test r9, r9
  js .negative
  ret

.negative:
  neg rax
  ret

.error:
  mov rax, 0
  ret

