#include <stdio.h>

void	ft_check(int num, int *count)
{
	while (num)
	{
		if (num % 1000 == 666)
		{
			*count += 1;
			break ;
		}
		num /= 10;
	}
}

int main(void)
{
	int n, count, num;

	scanf("%d", &n);

	count = 0;
	num = 666;
	while (1)
	{
		ft_check(num, &count);
		if (count == n)
			break ;
		num++;
	}
	printf("%d", num);
	return (0);
}