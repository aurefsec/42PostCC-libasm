section .text
global ft_list_size

ft_list_size:
  test rdi, rdi
  je .no_list

  mov rax, 1
  .loop:
    mov rsi, QWORD [rdi + 8]
    test rsi, rsi
    je .end

    mov rdi, rsi
    inc rax
    jmp .loop

.end:
  ret

.no_list:
  mov rax, 0
  ret
