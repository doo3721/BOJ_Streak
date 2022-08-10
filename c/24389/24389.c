#include <stdio.h>

int main(void)
{
	unsigned int n, t, i, c;

	scanf("%d", &n);
	t = -n;

	c = 0;
	i = 32;
	while (i)
	{
		if (n % 2 ^ t % 2)
			c++;
		n /= 2;
		t /= 2;
		i--;
	}
	printf("%d", c);
	return (0);
}