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
  memset(l3, 0, sizeof(t_list));
  char* s1 = "1";
  char* s2 = "2";
  char* s3 = "2";
  char* s4 = "3";
  l3->data = s1;
  ft_list_push_front(&l3, s2);
  ft_list_push_front(&l3, s3);
  ft_list_push_front(&l3, s4);
  t_list* l4 = l3;
  printf("Before sort :\n");
  while (l3)
  {
    printf("data = %s\n", (char*)l3->data);
    l3 = l3->next;
  }
  printf("After sort :\n");
  ft_list_sort(&l4, strcmp);
  t_list* l5 = l4;
  while (l4)
  {
    printf("data = %s\n", (char*)l4->data);
    l4 = l4->next;
  }

  printf("\nTEST5 : ft_list_remove_if\n");
  t_list* l6 = l5;
  printf("Before remove '2' :\n");
  while (l5)
  {
    printf("data = %s\n", (char*)l5->data);
    l5 = l5->next;
  }
  char* s5 = "2";
  ft_list_remove_if(&l6, s5, strcmp, free);
  t_list* l7 = l6;
  printf("After remove '2' :\n");
  while (l6)
  {
    printf("data = %s\n", (char*)l6->data);
    l6 = l6->next;
  }
  char* s6 = "3";
  ft_list_remove_if(&l6, s6, strcmp, free);
  t_list* l8 = l7;
  printf("After remove '3' :\n");
  while (l7)
  {
    printf("data = %s\n", (char*)l7->data);
    l7 = l7->next;
  }
  free(l8);
  return 0;
}
