#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*ft_strdup(char *src);

int main()
{
    char str [80];
    char *p;
    char *a;
    strcpy(str, "this is a test");
    p = strdup(str);
    printf("original = %s", p);
    a = ft_strdup(str);
    printf("\nmoya     = %s", a);
}