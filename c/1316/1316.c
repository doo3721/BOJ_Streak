#include <stdio.h>

int	ft_find(char *str, char f, int idx)
{
	while (str[idx] == f && str[idx])
		idx++;
	while (str[idx] != f && str[idx])
		idx++;
	if (str[idx])
		return (0);
	return (1);
}

int main(void)
{
	char	str[101];
	int		n, idx, count;

	scanf("%d", &n);

	count = 0;
	while (n)
	{
		scanf("%s", str);
		idx = 0;
		while (str[idx])
		{
			if (!ft_find(str, str[idx], idx))
				break ;	
			idx++;
		}
		if (!str[idx])
			count++;
		n--;
	}
	printf("%d", count);
	return (0);
}