section .text
global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:
  push rdi

  call ft_strlen

  mov rdi, rax
  add rdi, 1

  call malloc wrt ..plt
  test rax, rax
  je .error

  pop rsi
  mov rdi, rax

  call ft_strcpy

  ret

.error:
  pop rsi
  ret
