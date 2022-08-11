#include <stdio.h>
/*
static int	ahri[10];
static int	koogi[10];

int main(void)
{
	int n, m, i;

	scanf("%d%d", &n, &m);

	i = 0;
	while (i < 10)
		ahri[i++] = 1;
	
	i = 9;
	while (i >= 0)
	{
		if (n >= 1 << i)
		{
			n -= 1 << i;
			ahri[i]--;
		}
		i--;
	}
	if (!n)
		printf("No thanks");
	else
	{
		i = 9;
		while (i >= 0)
		{
			if (m >= 1 << i)
			{
				m -= 1 << i;
				koogi[i]++;
			}
			i--;
		}

		i = 9;
		while (i >= 0)
		{
			if (koogi[i] && n >= 1 << i)
			{
				n -= 1 << i;
				koogi[i]--;
			}
			i--;
		}
		
		if (!n)
			printf("Thanks");
		else
			printf("Impossible");
	}
	return (0);
}
*/

int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);

	n -= 1023;
	if (n <= 0)
	{
		printf("No thanks");
		return (0);
	}

	if ((n & m) == n)
		printf("Thanks");
	else
		printf("Impossible");
	return (0);
}