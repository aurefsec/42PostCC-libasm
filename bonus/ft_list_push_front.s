section .text
global ft_list_push_front
extern malloc

ft_list_push_front:
  push rdi
  mov rdi, 16

  call malloc wrt ..plt
  test rax, rax
  je .error

  mov rdi, QWORD [rsi]
  mov QWORD [rax], rdi

  pop rdi
  mov rdx, QWORD [rdi]
  test rdx, rdx
  jne .retrive_next
  jump .end

.retrive_next:
  mov rdx, QWORD [rdx + 8]
  mov QWORD [rax + 8], rdx

.end:
  mov QWORD [rdi], rax
  ret

.error:
  ret
