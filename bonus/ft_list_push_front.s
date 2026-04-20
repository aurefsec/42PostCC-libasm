section .text
global ft_list_push_front
extern malloc

ft_list_push_front:
  push rdi
  mov rdi, 16
  push rsi

  call malloc wrt ..plt
  test rax, rax
  je .error

  pop rsi
  mov rdi, QWORD [rsi]
  mov QWORD [rax], rdi

  pop rdi
  mov rdx, QWORD [rdi]
  mov QWORD [rax + 8], rdx
  mov QWORD [rdi], rax
  ret

.error:
  ret
