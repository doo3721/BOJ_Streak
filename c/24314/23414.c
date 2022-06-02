#include <stdio.h>

int main(void)
{
	int a1, a0, c, n0;

	scanf("%d%d%d%d", &a1, &a0, &c, &n0);

	if (c * n0 <= a1 * n0 + a0 && c <= a1)
		printf("1");
	else
		printf("0");
	return (0);
}