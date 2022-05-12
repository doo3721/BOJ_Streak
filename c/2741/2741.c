#include <stdio.h>

int	main(void)
{
	int	num;
	int	idx;

	scanf("%d", &num);

	idx = 1;
	while (idx <= num)
	{
		printf("%d\n", idx);
		idx++;
	}
	return (0);
}