#include <stdio.h>

int main(void)
{
	char	str[16];
	int		time, idx;

	scanf("%s", str);

	time = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= 'A' && str[idx] <= 'C')
			time += 3;
		else if (str[idx] >= 'D' && str[idx] <= 'F')
			time += 4;
		else if (str[idx] >= 'G' && str[idx] <= 'I')
			time += 5;
		else if (str[idx] >= 'J' && str[idx] <= 'L')
			time += 6;
		else if (str[idx] >= 'M' && str[idx] <= 'O')
			time += 7;
		else if (str[idx] >= 'P' && str[idx] <= 'S')
			time += 8;
		else if (str[idx] >= 'T' && str[idx] <= 'V')
			time += 9;
		else if (str[idx] >= 'W' && str[idx] <= 'Z')
			time += 10;
		idx++;
	}
	printf("%d", time);

	return (0);
}