#include <stdio.h>
#include <string.h>

static int	lcs[1001][1001];

static int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int	main(void)
{
	char	a[1001];
	char	b[1001];
	char	c[1001];
	int		i, j, idx;

	scanf("%s%s", a, b);
	j = 0;
	while (b[j])
	{
		i = 0;
		while (a[i])
		{
			if (a[i] == b[j])
				lcs[j + 1][i + 1] = lcs[j][i] + 1;
			else
				lcs[j + 1][i + 1] = ft_max(lcs[j][i + 1], lcs[j + 1][i]);
			i++;
		}
		j++;
	}
	printf("%d\n", lcs[j][i]);

	idx = 0;	
	while (i >= 0 && j >= 0)
	{
		if (lcs[j][i] == lcs[j - 1][i])
			j--;
		else if (lcs[j][i] == lcs[j][i - 1])
			i--;
		else
		{
			c[idx] = a[i - 1];
			idx++;
			i--;
			j--;
		}
	}

	while (--idx >= 0)
		printf("%c", c[idx]);
	return (0);
}