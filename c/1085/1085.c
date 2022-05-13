#include <stdio.h>

int	main(void)
{
	int	x;
	int	y;
	int	w;
	int	h;
	int min_len;

	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &w);
	scanf("%d", &h);

	min_len = x;

	if (min_len > (w - x))
		min_len = w - x;
	if (min_len > y)
		min_len = y;
	if (min_len > h - y)
		min_len = h - y;
	
	printf("%d", min_len);
	return (0);
}