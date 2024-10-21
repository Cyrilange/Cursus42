/*Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

These  functions  copy the string pointed to by src, into a string at
              the buffer pointed to by dst.  The programmer is responsible for  al‐
              locating a destination buffer large enough, that is, strlen(src) + 1.
              For the difference between the two functions, see RETURN VALUE.
char *strcpy(char *restrict dst, const char *restrict src);

char    *ft_strcpy(char *s1, char *s2);(for the exam)*/

#include <unistd.h>
//#include <stdlib.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

/*int main(void)
{
    char *src = "hola";
    char *dst = " ";
    dst = (char *)malloc(sizeof(char) * sizeof(src) );
    ft_strcpy(dst, src);
   write(1,dst , sizeof(src) - 1); 
   write(1, "\n", 1);
   free(dst);
   return (0);
}
*/
