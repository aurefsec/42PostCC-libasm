section .text
global ft_list_sort

ft_list_sort:
  push rbx
  mov rbx, rsi

  push r8
  mov r8, rdi

  mov rdx, QWORD [rdi]
  test rdx, rdx
  je .end

  xor r9, r9

  .loop:
  mov rcx, rdx
  mov rdx, QWORD[rdx + 8]
  test rdx, rdx
  je .end

  push r9
  push rdx
  push rcx

  mov rdi, QWORD [rcx]
  mov rsi, QWORD [rdx]

  call rbx

  pop rcx
  pop rdx
  pop r9

  cmp rax, 0
  jg .swap
  jmp .loop

.swap:
  mov r9, 1
  mov r10, QWORD [rcx]
  mov r11, QWORD [rdx]
  mov QWORD [rcx], r11
  mov QWORD [rdx], r10
  jmp .loop

.unsorted:
  xor r9, r9
  mov rdx, QWORD [r8]
  push r8
  jmp .loop

.end:
  pop r8
  test r9, r9
  jne .unsorted
  pop rbx
  ret
