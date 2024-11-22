#include <unistd.h>

void    rev_wstr(char *str)
{
    int len = 0;
    int start;
    int end;

    
    while (str[len])
        len++;

    end = len; 

    while (end > 0)
    {
        
        while (end > 0 && (str[end - 1] == ' ' || str[end - 1] == '\t'))
            end--;

      
        start = end;
        while (start > 0 && str[start - 1] != ' ' && str[start - 1] != '\t')
            start--;

       
        if (start < end)
        {
            write(1, &str[start], end - start);
            if (start > 0) 
                write(1, " ", 1);
        }

        end = start;
    }
}


int main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}