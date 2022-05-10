#include <stdio.h>

int	main(void)
{
	int	num;
	int	idx;
	int	p_idx;

	scanf("%d", &num);

	idx = 1;
	while (idx <= num)
	{
		p_idx = 1;
		while (p_idx <= idx)
		{
			printf("*");
			p_idx++;
		}
		printf("\n");
		idx++;
	}
	return (0);
}