/*Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);


DESCRIPTION
       The strcmp() function compares the two strings s1 and s2.  The locale is not taken
       into account (for a locale-aware comparison, see strcoll(3)).  The  comparison  is
       done using unsigned characters.

       strcmp() returns an integer indicating the result of the comparison, as follows:

       •  0, if the s1 and s2 are equal;

       •  a negative value if s1 is less than s2;

       •  a positive value if s1 is greater than s2.

       The  strncmp()  function is similar, except it compares only the first (at most) n
       bytes of s1 and s2.

RETURN VALUE
       The strcmp() and strncmp() functions return an integer less  than,  equal  to,  or
       greater  than zero if s1 (or the first n bytes thereof) is found, respectively, to
       be less than, to match, or be greater than s2.
*/

int    ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}