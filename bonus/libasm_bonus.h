#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <string.h>

typedef struct s_list
{
  void    *data;
  struct  s_list *next;
} t_list

int     ft_atoi_base(char* str, char* base);
void    ft_list_push_front(t_list** begin_list, void* data);

#endif
