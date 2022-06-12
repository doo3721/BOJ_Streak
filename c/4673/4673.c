#include <stdio.h>

int ft_d(int n)
{
	char	num[6];
	int		sum, idx;

	sprintf(num, "%d", n);

	idx = 0;
	sum = n;
	while (num[idx])
		sum += (num[idx++] - '0');
	return (sum);
}

int main(void)
{
	int	n[10001] = {0, };
	int idx, d;

	idx = 1;
	while (idx <= 10000)
	{
		if (!n[idx])
			printf("%d\n", idx);
		d = ft_d(idx);
		if (d <= 10000)
			n[d] = 1;
		idx++;
	}
	return (0);
}