#include <stdio.h>

static int	z[41] = {0, };
static int	o[41] = {0, };

void	fibonacci(void)
{
	int	i;

	z[0] = 1;
	o[1] = 1;
	i = 2;
	while (i < 41)
	{
		z[i] = z[i - 1] + z[i - 2];
		o[i] = o[i - 1] + o[i - 2];
		i++;
	}
}

int	main(void)
{
	int t, n;

	scanf("%d", &t);
	fibonacci();
	while (t)
	{
		scanf("%d", &n);
		printf("%d %d\n", z[n], o[n]);
		t--;
	}
	return (0);
}