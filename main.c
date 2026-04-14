# include "libasm.h"

int main(void)
{
  printf("TEST 1 : ft_strlen\n");
  char* s = "je fais un test";
  size_t l1 = strlen(s);
  size_t l2 = ft_strlen(s);
  printf("strlen = %ld\nft_strlen = %ld\n", l1, l2);

  printf("\nTEST 2 : ft_strcpy\n");
  char* src = "je fais un test";
  char* dst = malloc(sizeof(char) * strlen(src) + 1);
  if (!dst)
    return 1;
  char* ret1 = strcpy(dst, src);
  char* ret2 = ft_strcpy(dst, src);
  printf("strcpy = %s\nft_strcpy = %s\n", ret1, ret2);
  free(dst);
  dst = NULL;

  printf("\nTEST 3 : ft_strcmp\n");
  int nb1 = strcmp("je fais un test", "je fais un test");
  int nb2 = ft_strcmp("je fais un test", "je fais un test");
  printf("strcmp = %d\nft_strcmp = %d\n", nb1, nb2);

  printf("\nTEST 4 : ft_write\n");
  ssize_t w1 = write(1, "je fais un test\n", 16);
  ssize_t w2 = ft_write(1, "je fais un test\n", 16);
  printf("write = %zd\nft_write = %zd\n", w1, w2);

  printf("\nTEST 5 : ft_read\n");
  int fd1[2];
  int fd2[2];
  pipe(fd1);
  pipe(fd2);
  write(fd1[1], "je fais un test\n", 16);
  write(fd2[1], "je fais un test\n", 16);
  char buff1[50];
  char buff2[50];
  ssize_t r1 = read(fd1[0], buff1, 16);
  ssize_t r2 = ft_read(fd2[0], buff2, 16);
  buff1[r1] = '\0';
  buff2[r2] = '\0';
  printf("read return = %zd\nread buff = %s", r1, buff1);
  printf("ft_read return = %zd\nft_read buff = %s\n", r2, buff2);
  close(fd1[0]);
  close(fd1[1]);
  close(fd2[0]);
  close(fd2[1]);

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
    dst1 = NULL;
    return 1;
  }
  printf("strdup = %s\nft_strdup = %s\n", dst1, dst2);
  free(dst1);
  free(dst2);
  dst1 = NULL;
  dst2 = NULL;

  return 0;
}
