#include <stdlib.h>

int ft_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_w(char *str)
{
    int i = 0;
    int wc = 0;
    while (str[i])
    {
        while (str[i] && ft_space(str[i]))
            i++;
        if (str[i] && !ft_space(str[i]))
            wc++;
        while (str[i] && !ft_space(str[i]))
            i++;
    }
    return wc;
}
char *copy_word(char *src, int n)
{
    int i = 0;
    char *dst = malloc(sizeof(char) * (n + 1));
    if (!dst)
        return NULL;
    while (i < n)
    {
        dst[i] = src[i];
        i++;
    }
    dst[n] = NULL;
    return dst;

}
    
char    **ft_split(char *str)
{
    int wc = count_w(str);
    int w = 0;
    int i = 0;
    char **arr = malloc(sizeof(char *) * (wc + 1));
    if (!arr)
        return NULL;
    while (str[i])
    {
        while (str[i] && ft_space(str[i]))
            i++;
        int start = i;
        while (str[i] && !ft_space(str[i]))
            i++;
        if (i > start)
        {
            arr[w] = copy_word(&str[start], i - start);
            if (!arr[w])
            {
                while (w > 0)
                    free(arr[--w]);
                free(arr);
                return NULL;
            }
            w++;
        }
    }
    arr[w] = NULL;
    return arr;
}

/*
#include <stdio.h>
int	main(void)
{
	char *s = "There     should be an array of 8         words! ";
	char **array = ft_split(s);
	int i = 0;
	int count = count_w(s);
    printf("count_w: %d\n", count);

	while (i < count)
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
} */