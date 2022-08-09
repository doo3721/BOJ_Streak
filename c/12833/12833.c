#include <stdio.h>

int main(void)
{
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);

	if (c % 2)
		printf("%d", a ^ b);
	else
		printf("%d", a);
	
	return (0);
}