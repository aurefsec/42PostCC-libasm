section .text
global ft_strlen

ft_strlen:
  push rbp
  mov rbp, rsp
  sub rsp, 16

  mov QWORD [rbp-8], 0

.loop_start:
  mov rbx, QWORD [rbp-8]
  mov al, BYTE [rdi + rbx]
  cmp al, 0
  je .loop_end

  add QWORD [rbp-8], 1
  jmp .loop_start

.loop_end:
  mov rax, QWORD [rbp-8]
  leave
  ret
