# include "libasm.h"

int main(void)
{
  printf("TEST 1 : ft_strlen\n");
  size_t l1 = ft_strlen("je fais un test");
  printf("ft_strlen = %ld\n", l1);

  printf("\nTEST 2 : ft_strcpy\n");
  char* dst = malloc(sizeof(char) * strlen(src) + 1);
  if (!dst)
    return 1;
  char* ret1 = strcpy(dst, "je fais un test");
  char* ret2 = ft_strcpy(dst, "je fais un test");
  printf("strcpy = %s\nft_strcpy = %s\n", ret1, ret2);
  free(dst);

  printf("\nTEST 3 : ft_strcmp\n");
  int nb1 = strcmp("je fais un test", "je fais un test");
  int nb2 = ft_strcmp("je fais un test", "je fais un test");
  printf("strcmp = %d\nft_strcmp = %d\n", nb1, nb2);

  printf("\nTEST 4 : ft_write\n");
  ssize_t w1 = ft_write(1, "je fais un test\n", 16);
  printf("ft_write = %zd\n", w1);

  printf("\nTEST 5 : ft_read\n");
  int fd1[2];
  pipe(fd1);
  write(fd1[1], "je fais un test\n", 16);
  char buff[50];
  ssize_t r1 = ft_read(fd1[0], buff, 16);
  buff[r1] = '\0';
  printf("ft_read return = %zd\nft_read buff = %s", r1, buff);
  close(fd1[0]);
  close(fd1[1]);

  printf("\nTEST 6 : ft_strdup\n");
  char* dst1 = strdup("je fais un test");
  if (!dst1)
  {
    printf("Error\n");
    return 1;
  }
  char* dst2 = ft_strdup("je fais un test");
  if (!dst2)
  {
    printf("Error\n");
    free(dst1);
    return 1;
  }
  printf("strdup = %s\nft_strdup = %s\n", dst1, dst2);
  free(dst1);
  free(dst2);
  return 0;
}
