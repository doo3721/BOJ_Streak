#include <stdio.h>

int main(void)
{
	int h, m, t;

	scanf("%d%d%d", &h, &m, &t);

	h = (h + (m + t) / 60) % 24;
	m = (m + t) % 60;
	
	printf("%d %d", h, m);
	return (0);
}