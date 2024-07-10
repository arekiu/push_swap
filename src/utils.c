#include "push_swap.h"

int	count_nums(char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (counter);
		counter++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (counter);
}