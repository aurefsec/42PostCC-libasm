# include "libasm.h"
# include <stdio.h>
# include <string.h>

int main(void)
{
  char* s = "je fais un test";
  size_t l1 = strlen(s);
  size_t l2 = ft_strlen(s);

  printf("strlen = %ld\nft_strlen = %ld\n", l1, l2);
  return 0;
}
