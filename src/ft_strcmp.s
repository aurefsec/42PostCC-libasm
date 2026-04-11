section .text
global ft_strcmp

ft_strcmp:
  xor rdx, rdx

.loop:
  mov cl, BYTE [rdi + rdx]
  mov r8b, BYTE [rsi + rdx]
  cmp cl, r8b
  jne .done
  test cl, cl
  je .done

  inc rdx
  jmp .loop

.done:
  movzx eax, cl
  movzx r8d, r8b
  sub eax, r8d
  ret
