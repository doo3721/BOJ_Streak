#include <stdio.h>

static char	a[100001];
static char	b[100001];

int	main(void)
{
	int	i;
	
	scanf("%s", a);
	scanf("%s", b);

	i = 0;
	while (a[i])
	{
		printf("%d", (a[i] - '0') & (b[i] - '0'));
		i++;
	}
	printf("\n");

	i = 0;
	while (a[i])
	{
		printf("%d", (a[i] - '0') | (b[i] - '0'));
		i++;
	}
	printf("\n");

	i = 0;
	while (a[i])
	{
		printf("%d", (a[i] - '0') ^ (b[i] - '0'));
		i++;
	}
	printf("\n");

	i = 0;
	while (a[i])
	{
		printf("%d", (a[i] - '0') ^ 1);
		i++;
	}
	printf("\n");

	i = 0;
	while (b[i])
	{
		printf("%d", (b[i] - '0') ^ 1);
		i++;
	}
	return (0);
}