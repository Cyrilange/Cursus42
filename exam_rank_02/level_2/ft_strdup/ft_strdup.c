/*The  strdup()  function  returns a pointer to a new string which is a duplicate of
       the string s.  Memory for the new string is obtained with malloc(3),  and  can  be
       freed with free(3).
       
       On success, the strdup() function returns a pointer to the duplicated string.   It
       returns  NULL if insufficient memory was available, with errno set to indicate the
       error.
       */
    //  #include <stdio.h>
     // #include <stdlib.h>

    int ft_strlen(char *str)
    {
        int i = 0;
        while (str[i])
            i++;
        return (i);
    }

      char *ft_strdup(char *src)
      {
        int len = ft_strlen(src);
        char *new;
        new = (char*)malloc(sizeof(*new) * (len + 1));
        if (new == NULL)
            return (NULL);

        int i = 0;
        while (src[i])
        {
            new[i] = src[i];
            i++;
        }
        new[len] = '\0';
        return (new);
      }
/*
      int main(void)
      {
        char *dupliacte = ft_strdup("hi there\n");
        if (dupliacte)
        {
            printf("%s", dupliacte);
            free(dupliacte);

        }
        else
        {
            printf("error");
        }
      
      return (0);
      } */