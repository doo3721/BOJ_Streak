#include <stdio.h>

int main(void)
{
	int	n, num, count;

	scanf("%d", &n);

	count = 0;
	while (n)
	{
		num = n;
		while (!(num % 5))
		{
			num /= 5;
			count++;
		}
		n--;
	}
	
	printf("%d", count);
	return (0);
}