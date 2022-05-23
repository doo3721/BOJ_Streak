#include <stdio.h>

long long	ft_r_power(int pwr)
{
	long long	num;
	long long	temp;
	int	idx;

	idx = 0;
	num = 1;
	temp = 1;
	while (idx < pwr)
	{
		temp *= 31;
		if (temp > 1234567891)
		{
			if (num > 1234567891)
				num %= 1234567891;
			num *= (temp % 1234567891);
			temp = 1;
		}
		idx++;
	}
	if (num > 1234567891)
		num %= 1234567891;
	num *= (temp % 1234567891);
	return (num % 1234567891);
}

int main(void)
{
	int			l;
	char		str[60];
	int			idx;
	long long	num;

	scanf("%d%s", &l, str);

	idx = 0;
	num = 0;
	while (str[idx])
	{
		num += ((str[idx] - 'a' + 1) * ft_r_power(idx)) % 1234567891;
		idx++;
	}
	printf("%lld", num % 1234567891);
	return (0);
}