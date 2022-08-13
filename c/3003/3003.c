#include <stdio.h>

int main(void)
{
	int n, i;

	i = 0;
	while (i < 6)
	{
		scanf("%d", &n);
		if (i == 0 || i == 1)
			printf("%d ", 1 - n);
		else if (i == 5)
			printf("%d ", 8 - n);
		else
			printf("%d ", 2 - n);
		i++;
	}
	return (0);
}