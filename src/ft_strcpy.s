section .text
global ft_strcpy

ft_strcpy:
  xor rdx, rdx

.loop:
  mov cl, BYTE [rsi + rdx]
  mov BYTE [rdi + rdx], cl
  test cl, cl
  je .done

  inc rdx
  jmp .loop

.done:
  mov rax, rdi
  ret
