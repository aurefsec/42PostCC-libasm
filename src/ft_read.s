section .text
global ft_read
extern __errno_location

ft_read:
  mov eax, 0
  syscall
  js .error
  ret

.error:
  push rax
  call __errno_location wrt ..plt
  pop rcx
  neg rcx
  mov [rax], rcx
  mov rax, -1
  ret
