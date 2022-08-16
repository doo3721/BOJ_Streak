#include <stdio.h>

static int n, s;

int main(void)
{
	while (scanf("%d%d", &n, &s) > 0)
		printf("%d\n", s / (n + 1));
	return (0);
}