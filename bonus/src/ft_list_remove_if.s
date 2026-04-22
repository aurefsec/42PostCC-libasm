section .text
global ft_list_remove_if

ft_list_remove_if:
  push r12
  mov r12, rsi
  push r13
  mov r13, rdx
  push r14
  mov r14, rcx

  mov r8, QWORD [rdi]
  test r8, r8
  je .end

  xor r9, r9

  .loop:
    mov r10, r9
    mov r9, r8
    test r9, r9
    je .end
    mov r8, QWORD [r8 + 8]

    mov rdi, QWORD [r9]
    mov rsi, r12

    push r10
    push r9
    push r8

    call r13

    pop r8
    pop r9
    pop r10

    test rax, rax
    je .free
    jmp .loop

.free:
  push r10
  push r9
  push r8

  mov rdi, r9

  call r14

  pop r8
  pop r9
  pop r10

  mov r9, r10
  test r9, r9
  je .loop
  mov QWORD [r9 + 8], r8
  jmp .loop

.end:
  pop r14
  pop r13
  pop r12
  ret
