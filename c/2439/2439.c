#include <stdio.h>

int	main(void)
{
	int	num;
	int	i;
	int	j;

	scanf("%d", &num);

	i = 1;
	while (i <= num)
	{
		j = 1;
		while (j <= num)
		{
			if (j <= num - i)
				printf(" ");
			else
				printf("*");
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}