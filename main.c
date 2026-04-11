# include "libasm.h"

int main(void)
{
  printf("ft_strlen :\n");
  char* s = "je fais un test";
  size_t l1 = strlen(s);
  size_t l2 = ft_strlen(s);
  printf("strlen = %ld\nft_strlen = %ld\n", l1, l2);

  printf("\nft_strcpy :\n");
  char* src = "je fais un test";
  char* dst = malloc(sizeof(char) * strlen(src) + 1);
  if (!dst)
    return 1;
  char* ret1 = strcpy(dst, src);
  char* ret2 = ft_strcpy(dst, src);
  printf("strcpy = %s\nft_strcpy = %s\n", ret1, ret2);
  free(dst);

  printf("\nft_strcmp :\n");
  int nb1 = strcmp("je fais un test", "je fais un toast");
  int nb2 = ft_strcmp("je fais un test", "je fais un toast");
  printf("strcmp = %d\nft_strcmp = %d\n", nb1, nb2);

  return 0;
}
