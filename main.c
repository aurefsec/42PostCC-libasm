# include "libasm.h"
# include <stdio.h>
# include <string.h>

int main(void)
{
  printf("ft_strlen : \n");
  char* s = "je fais un test";
  size_t l1 = strlen(s);
  size_t l2 = ft_strlen(s);
  printf("strlen = %ld\nft_strlen = %ld\n", l1, l2);

  printf("\nft_strcpy : \n");
  char* src = "je fais un test";
  char* dst = "ej siaf nu tset";
  char* ret1 = strcpy(dst, src);
  char* ret2 = ft_strcpy(dst, src);
  printf("strcpy = %s\nft_strcpy = %s\n", ret1, ret2);

  return 0;


}
