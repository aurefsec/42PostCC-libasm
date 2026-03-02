section .text
global ft_strlen

ft_strlen:
  xor rax, rax ; Init rax to 0, rax = index and return value

.loop:
  mov dl, BYTE [rdi + rax] ; dl = 8 bits registrer of rdx, rdi = first char param of strlen
  test dl, dl ; test = if dl == 0
  je .done ; if dl == 0 jump to loop_end

  inc rax ; increment rax (i++)
  jmp .loop ; jump to loop

.done:
  ret ; retun rax
