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
  while (l)
  {
    printf("data = %s\n", (char*)l->data);
    t_list* tmp = l;
    l = l->next;
    free(tmp);
  }

  printf("\nTEST3 : ft_list_size\n");
  t_list* l2 = malloc(sizeof(t_list));
  if (!l2)
    return 1;
  memset(l2, 0, sizeof(t_list));
  int nb1 = ft_list_size(0);
  int nb2 = ft_list_size(l2);
  ft_list_push_front(&l2, str);
  ft_list_push_front(&l2, str);
  int nb3 = ft_list_size(l2);
  printf("nb1 = %d\nnb2 = %d\nnb3 = %d\n", nb1, nb2, nb3);
  while (l2)
  {
    t_list* tmp = l2;
    l2 = l2->next;
    free(tmp);
  }

  printf("\nTEST4 : ft_list_sort\n");
  t_list* l3 = malloc(sizeof(t_list));
  if (!l3)
    return 1;
  int n1 = 1;
  int n2 = 2;
  int n3 = 3;
  l3->data = &n1;
  ft_list_push_front(&l3, &n2);
  ft_list_push_front(&l3, &n3);
  t_list* l4 = l3;
  printf("Before sort :\n");
  while (l3)
  {
    printf("data = %d\n", *(int*)l3->data);
    l3 = l3->next;
  }
  printf("\nAfter sort\n");
  ft_list_sort(&l4, strcmp);
  while (l4)
  {
    printf("data = %d\n", *(int*)l4->data);
    t_list* tmp = l4;
    l4 = l4->next;
    free(tmp);
  }

  return 0;
}
