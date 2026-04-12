section .text
global ft_write
extern __errno_location

ft_write:
  mov eax, 1
  syscall
  js .error
  ret

.error:
  push rax
  call __errno_location
  pop rcx
  neg rcx
  mov [rax], rcx
  mov rax, -1
  ret
