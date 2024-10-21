#include <unistd.h>

void ft_putnbr(int n)
{
    char c;
    if (n > 9)
    {
        ft_putnbr(n / 10);
    }
    c = (n % 10) + '0';
    write(1, &c, 1);
    
    
}

int		max(int* tab, unsigned int len)
{
    int i = 0;
    int result;
    if (len == 0)
        return (0);
    result = tab[0];
    while (i < len)
    {
        if (result < tab[i])
        {
            result = tab[i];
        }
        
        i++;
    }
    return (result);

}

/*int main(void)
{
int tab[] = {1, 7, 9, 10, 47};
int i = max(tab, 5);
ft_putnbr(i);
write(1, "\n", 1);
return (0);
}*/