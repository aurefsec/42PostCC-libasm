section .text
global ft_strcpy

ft_strcpy:
  xor rdx, rdx

.loop:
  mov al, BYTE [rsi + rdx]
  test al, al
  je .done

  inc rdx
  jmp .loop

.done:
  mov al, '\0'
  ret
