#include <stdio.h>

int main(void)
{
	char	str[100001];
	int		idx, count;

	scanf("%s", str);

	idx = 1;
	count = 1;
	while (str[idx])
	{
		if (str[idx - 1] >= str[idx])
			count++;
		idx++;
	}
	printf("%d", count);
	return (0);
}