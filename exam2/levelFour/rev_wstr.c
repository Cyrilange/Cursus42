#include <stdlib.h>
#include <unistd.h>

void rev_word(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		int end = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i--;
		int start = i + 1;
		int flag = i;
		while (start  <= end)
		{
			write(1, &str[start++], 1);
		}
		if (flag && str[i] > 0 && str[i + 1] != '\0')
		{
			write(1, " ", 1);
		}
		i--;
	}

}

int main(int argc, char **argv)
{
	if (argc == 2)
		rev_word(argv[1]);
	write(1, "\n", 1);
	return 0;
}
