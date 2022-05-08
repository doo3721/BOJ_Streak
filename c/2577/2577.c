#include <stdio.h>

int	main(void)
{
	int		input;
	int		idx;
	int		num;
	char	c_arr[10];
	int		i_arr[10] = {0,};

	num = 1;
	idx = 0;
	while (idx < 3)
	{
		scanf("%d", &input);
		num = num * input;
		idx++;
	}

	sprintf(c_arr, "%d", num);

	idx = 0;
	while (c_arr[idx])
	{
		i_arr[c_arr[idx] - '0']++;
		idx++;
	}
	
	idx = 0;
	while (idx < 10)
	{
		printf("%d\n", i_arr[idx]);
		idx++;
	}
	return (0);
}