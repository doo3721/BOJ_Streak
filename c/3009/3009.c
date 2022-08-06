#include <stdio.h>

static int	x[2];
static int	y[2];

int	main(void)
{
	int a, b, i;

	scanf("%d%d", &a, &b);
	x[0] = a;
	y[0] = b;

	scanf("%d%d", &a, &b);
	if (x[0] == a)
		x[0] = 0;
	else
		x[1] = a;
	if (y[0] == b)
		y[0] = 0;
	else
		y[1] = b;
	
	scanf("%d%d", &a, &b);
	if (!x[1])
		x[1] = a;
	else if (x[0] == a)
		x[0] = 0;
	else if (x[1] == a)
		x[1] = 0;
	if (!y[1])
		y[1] = b;
	else if (y[0] == b)
		y[0] = 0;
	else if (y[1] == b)
		y[1] = 0;
	
	i = 0;
	while (i < 2)
	{
		if (x[i] != 0)
			printf("%d ", x[i]);
		i++;
	}

	i = 0;
	while (i < 2)
	{
		if (y[i] != 0)
			printf("%d", y[i]);
		i++;
	}
	return (0);
}