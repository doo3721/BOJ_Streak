#include <stdio.h>

int	main(void)
{
	int	num;
	int	idx;

	scanf("%d", &num);

	idx = num;
	while (idx > 0)
	{
		printf("%d\n", idx);
		idx--;
	}
	return (0);
}