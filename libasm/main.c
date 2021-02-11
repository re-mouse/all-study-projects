#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const char *buff, size_t bytes);
ssize_t	ft_read(int fd, const char *buff, size_t bytes);
char	*ft_strdup(const char *n1);

int main()
{
	char *c = "qwerty";
	char *b = "asdfgh";
	char *d = "";
	char *g = "123456";
	char *f = "012345";
	printf("STRCMP TEST\n======\n");
	printf("%d\n", strcmp("", ""));
	printf("%d\n", ft_strcmp("", ""));
	printf("%d\n", strcmp(b, b));
	printf("%d\n", ft_strcmp(b, b));
	printf("%d\n", strcmp(c, b));
	printf("%d\n", ft_strcmp(c, b));
	printf("%d\n", strcmp(g, f));
	printf("%d\n", ft_strcmp(g, f));
	printf("%d\n", strcmp(f, g));
	printf("%d\n", ft_strcmp(f, g));
	printf("%d\n", strcmp(c, d));
	printf("%d\n", ft_strcmp(c, d));

	printf("STRLENTEST\n======\n");
	printf("%lu\n", strlen(c));
	printf("%lu\n", ft_strlen(c));
	printf("%lu\n", strlen(b));
	printf("%lu\n", ft_strlen(b));
	printf("%lu\n", strlen(d));
	printf("%lu\n", ft_strlen(d));
	printf("%lu\n", strlen(g));
	printf("%lu\n", ft_strlen(g));
	printf("%lu\n", strlen(f));
	printf("%lu\n", ft_strlen(f));

	printf("STRCPYTEST\n======\n");
	char test[10];
	char test2[10];
	ft_strcpy(test, c);
	printf("%s\n", test);
	strcpy(test2, c);
	printf("%s\n", test2);
	char test3[15];
	char test4[15];
	printf("%s\n", ft_strcpy(test3, g));
	printf("%s\n", strcpy(test4, g));
	printf("%s\n", ft_strcpy(test3, d));
	printf("%s\n", strcpy(test4, d));

	printf("WRITETEST\n========\n");
	int wr1 = open("TEST", O_WRONLY | O_CREAT, 0777);
	int wr2 = open("TEST2", O_WRONLY | O_CREAT, 0777);
	ft_write(wr1, "ASDASD", 6);
	write(wr2, "ASDASD", 6);
	ft_write(1, d, ft_strlen(d));
	printf("\n");
	write(1, d, strlen(d));
	printf("\n");
	ft_write(1, f, ft_strlen(f));
	printf("\n");
	write(1, f, strlen(f));
	printf("\n");
	ft_write(1, c, 4);
	printf("\n");
	write(1, c, 4);
	printf("\n");

	printf("READTEST\n========\n");
	int fd1 = open("testfile", O_RDONLY);
	int fd2 = open("testfile", O_RDONLY);
	char buff1[100];
	char buff2[100];
	bzero(buff1, 100);
	bzero(buff2, 100);
	errno = 0;
	printf("%zd\n", read(fd1, buff1, 55));
	printf("%s\n", strerror(errno));
	errno = 0;
	printf("%zd\n", ft_read(fd2, buff2, 55));
	printf("%s\n", strerror(errno));
	printf("===\n%s\n===\n", buff1);
	printf("===\n%s\n===\n", buff2);
	errno = 0;
	printf("%zd\n", read(-1, buff1, 100));
	printf("%s\n", strerror(errno));
	errno = 0;
	printf("%zd\n", ft_read(-1, buff2, 100));
	printf("%s\n", strerror(errno));
	errno = 0;
	printf("%zd\n", read(1, buff1, -1));
	printf("%s\n", strerror(errno));
	errno = 0;
	printf("%zd\n", ft_read(1, buff2, -1));
	printf("%s\n", strerror(errno));
	printf("PRESS ENTER 2 TIMES, TEST TO NULL BUFFER\n");
	errno = 0;
	printf("%zd\n", read(1, NULL, 1));
	printf("%s\n", strerror(errno));
	errno = 0;
	printf("%zd\n", ft_read(1, NULL, 1));
	printf("%s\n", strerror(errno));
	char bufferchteniya[10];
	char bufferchteniya2[10];
	printf("ENTER TEXT 2 TIMES, TEST TO FT_READ AND FT_WRITE\n");
	ft_read(0, bufferchteniya, 10);
	read(0, bufferchteniya2, 10);
	ft_write(1, bufferchteniya, 10);
	write(1, bufferchteniya2, 10);

	printf("STRDUPTEST\n=======\n");
	char *k = ft_strdup("ETO CONST");
	char *j = strdup("ETO CONST");
	printf("%s\n", k);
	printf("%s\n", j);
	k[2] = '_';
	j[2] = '_';
	printf("%s\n", k);
	printf("%s\n", j);
}
