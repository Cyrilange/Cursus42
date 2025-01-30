
char *ft_rev(char *str)
{
    char start = *str;
    char end = *str;
    char temp;
    while (*str)
    {
        temp = start;
        start = end;
        end = temp;
        start++;
        end--;
    }
    return str;
}

int main()
{
    printf("%s", ft_rev("hello wordl"));
    return 0;

}