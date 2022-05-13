#include <stdio.h>

int	ft_numlen(int num)
{
	int	len;

	len = 1;
	while (num > 9)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

int	main(void)
{
	int		num;
	char	n_str[8];
	int		c_num;
	int		n_len;
	int		cmp;
	int		idx;

	scanf("%d", &num);
	
	n_len = ft_numlen(num);

	c_num = 0;
	if ((num - n_len * 9) > 0)
		c_num = num - n_len * 9;
	
	while (c_num < num)
	{
		idx = 0;
		cmp = 0;
		sprintf(n_str, "%d", c_num);
		while (n_str[idx])
		{
			cmp += (n_str[idx] - '0');
			idx++;
		}
		cmp += c_num;
		if (cmp == num)
		{
			printf("%d", c_num);
			break ;
		}
		c_num++;
	}
	if (c_num == num)
		printf("0");
	return (0);
}