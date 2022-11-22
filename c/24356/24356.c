#include <stdio.h>

int main(void)
{
	int	a, b, x, y, h, m;

	scanf("%d%d%d%d", &a, &b, &x, &y);
	if (b > y)
		h = (a >= x ? 24 + x - a : x - a) - 1;
	else
		h = a > x ? 24 + x - a : x - a;
	h *= 60;
	m = b > y ? 60 + y - b : y - b;
	printf("%d %d", h + m, (h + m)/30);
}
