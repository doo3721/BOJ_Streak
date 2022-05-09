#include <stdio.h>

int	main(void)
{
	char	c;
	char	str[30];
	int		idx;

	fgets(str, sizeof(str), stdin);

	idx = 0;
	if (str[idx] == '1')
	{
		c = '1';
		while (str[idx])
		{
			if (str[idx] >= '1' && str[idx] <= '8')
			{
				if (c != str[idx])
					break ;
				c = c + 1;
			}
			idx++;
		}
		if (c == '9')
			printf("ascending");
		else
			printf("mixed");
	}
	else if (str[idx] == '8')
	{
		c = '8';
		while (str[idx])
		{
			if (str[idx] >= '1' && str[idx] <= '8')
			{
				if (c != str[idx])
					break ;
				c = c - 1;
			}
			idx++;
		}
		if (c == '0')
			printf("descending");
		else
			printf("mixed");
	}
	else
		printf("mixed");
	return (0);
}