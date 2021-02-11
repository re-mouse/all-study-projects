#include <stdlib.h>
#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main()
{
    char **strs;
    char *a;
    char *sep;

    strs = malloc(sizeof(char*) * 10);
    a = "Привет сказал один человек";
    strs[0] = a;
    a = "Как дела?";
    strs[1] = a;
    a = "Это тест =)";
    strs[2] = a;
    a = "Если у тебя это последняя и она показалась, ты молодец!";
    strs[3] = a;
    sep = "\nИ ему ответили: ";
    printf("%s", ft_strjoin(4, strs, sep));
}