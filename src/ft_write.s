section .text
global ft_write

ft_write:
  mov eax, 1
  syscall
  js .error
  ret

.error:
  push rax
  call errno_location
  pop rcx
  neg rcx
  mov [rax], rcx
  mov rax, -1
  ret
