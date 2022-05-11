#include <stdio.h>

int	ft_find_char(char *str, char c_find)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == c_find)
			return (idx);
		idx++;
	}
	return (-1);
}

int	main(void)
{
	char	str[110];
	char	*alpha = "abcdefghijklmnopqrstuvwxyz";
	int		idx;

	fgets(str, sizeof(str), stdin);
	idx = 0;
	while (alpha[idx])
	{
		printf("%d ", ft_find_char(str, alpha[idx]));
		idx++;
	}
	return (0);
}