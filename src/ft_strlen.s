section .text
global ft_strlen

ft_strlen:
  xor rax, rax

.loop_start:
  mov dl, BYTE [rdi + rax]
  test dl, dl
  je .loop_end

  inc rax
  jmp .loop_start

.loop_end:
  ret
