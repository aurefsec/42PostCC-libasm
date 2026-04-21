# include "bonus/libasm_bonus.h"

int main(void)
{
  printf("TEST 1 : ft_atoi_base\n");
  int binary = ft_atoi_base("+11111111", "01");
  int hex = ft_atoi_base("FF", "0123456789ABCDEF");
  int decimal = ft_atoi_base("-44", "0123456789");
  int error = ft_atoi_base("123", "01123456789");
  printf("binary = %d\nhex = %d\ndecimal = %d\nerror = %d\n", binary, hex, decimal, error);

  printf("\nTEST 2 : ft_list_push_front\n");
  t_list* l = malloc(sizeof(t_list));
  if (!l)
    return 1;
  memset(l, 0, sizeof(t_list));
  l->data = "je fais un test";
  char* str = "je fais un test 2";
  ft_list_push_front(&l, str);
  int i = 0;
  while (l)
  {
    printf("i = %d | data = %s\n", i, (char *)l->data);
    i++;
    t_list *tmp = l;
    l = l->next;
    free(tmp);
  }

  printf{"\nTEST3 : ft_list_size\n"};
  t_list* l = malloc(sizeof(t_list));
  if (!l)
    return 1;
  int nb1 = ft_list_size(0);
  int nb2 = ft_list_size(l);
  ft_list_push_front(&l, str);
  ft_list_push_front(&l, str);
  int nb3 = ft_list_size(l);
  printf("nb1 = %d nb2 = %d nb3 = %d\n", nb1, nb2, nb3);
  while (l)
  {
    t_list *tmp = l;
    l = l->next;
    free(tmp);
  }
  return 0;
}
