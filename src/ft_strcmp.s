section .text
global ft_strcmp

ft_strcmp:
  xor rdx, rdx

.loop:
  mov cl, BYTE [rdi + rdx]
  mov bl, BYTE [rsi + rdx]
  test cl, cl
  je .done
  test bl, bl
  je .done
  cmp cl, bl
  jne .done

  inc rdx
  jmp .loop

.done:
  movzx eax, cl
  movzx edx, bl
  sub eax, edx
  ret
