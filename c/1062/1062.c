#include <stdio.h>

static int	alpha[50][26];
static char	str[50][16];

int	main(void)
{
	int	i, j, n, k;

	scanf("%d%d", &n, &k);
	i = 0;
	while (i < n)
	{
		scanf("%s", str[i]);
		while (str[i][j])
		{
			if (!alpha[i][str[i][j] - 'a'])
				alpha[i][str[i][j] - 'a'] = 1;
			j++;
		}
		i++;
	}
	
	if (k < 5)
	{
		printf("0");
		return (0);
	}
	else if (k == 26)
	{
		printf("%d", n);
		return (0);
	}
	

}
