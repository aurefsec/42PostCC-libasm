section .text
global ft_list_sort

ft_list_sort:
  push rbx
  mov rbx, rsi

  mov rdx, QWORD[rdi]
  test rdx, rdx
  je .end:

  .loop:
  mov rcx, rdx
  mov rdx, QWORD[rdx + 8]
  test rdx, rdx
  je .end

  push rdx
  push rcx

  mov rdi, QWORD [rcx]
  mov rsi, QWORD [rdx]

  call rbx

  pop rcx
  pop rdx

  cmp rax, 0
  jg .swap
  jmp .loop

.swap:
  mov r10, QWORD [rcx]
  mov r11, QWORD [rdx]
  mov QWORD [rcx], r11
  mov QWORD [rdx], r10
  jmp .loop

.nend:
  pop rbx
  ret
