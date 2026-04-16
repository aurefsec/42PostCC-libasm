# include "libasm.h"

int main(void)
{
  printf("TEST 1 : ft_atoi_base\n");
  int binary = ft_atoi_base("11111111", "01");
  int hex = ft_atoi_base("FF", "0123456789ABCDEF");
  int decimal = ft_atoi_base("44", "0123456789");
  int error = ft_atoi_base("123", "01123456789");
  printf("binary = %d\n, hex = %d\n, decimal = %d\n, error = %d\n", binary, hex, decimal, error);
}
