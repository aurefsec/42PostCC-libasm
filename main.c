# include "libasm.h"
# include <stdio.h>
# include <string.h>

int main(void)
{
  char* s = "je fais un test";
  printf("strlen = %d\nft_strlen = %d\n", strlen(s), ft_strlen(s));
}
