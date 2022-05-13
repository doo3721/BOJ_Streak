#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	main(void)
{
	char	n_str[6];
	int		len;
	int		idx;

	while (1)
	{
		scanf("%s", n_str);
		idx = 0;
		if (n_str[0] == '0')
			break ;
		len = ft_strlen(n_str);
		while (idx < (len / 2) )
		{
			if (n_str[idx] != n_str[len - 1 - idx])
				break ;
			idx++;
		}
		if (idx >= (len / 2))
			printf("yes\n");
		else
			printf("no\n");
	}
	return (0);
}