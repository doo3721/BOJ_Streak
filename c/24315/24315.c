#include <stdio.h>

int main(void)
{
	int a1, a0, c1, c2, n0;

	scanf("%d%d%d%d%d", &a1, &a0, &c1, &c2, &n0);

	if ((c1 * n0 <= a1 * n0 + a0 && c1 <= a1)
		&& (a1 * n0 + a0 <= c2 * n0 && a1 <= c2))
		printf("1");
	else
		printf("0");
	return (0);
}