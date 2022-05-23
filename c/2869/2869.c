#include <stdio.h>

int main(void)
{
	int a, b, v, count;

	scanf("%d%d%d", &a, &b, &v);

	count = (v - a) % (a - b) ? (v - a) / (a - b) + 1 + 1 : (v - a) / (a - b) + 1;
	printf("%d", count);
	return (0);
}