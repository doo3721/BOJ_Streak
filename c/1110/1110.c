#include <stdio.h>

int main(void)
{
	int n, o_n, p_n, count;

	scanf("%d", &n);

	o_n = n;
	n = n % 10 * 10 + (n / 10 + n % 10) % 10;
	p_n = n;
	count = 1;

	while (o_n != n)
	{
		n = p_n % 10 * 10 + (n / 10 + n % 10) % 10;
		p_n = n;
		count++;
	}
	printf("%d", count);
	
	return (0);
}