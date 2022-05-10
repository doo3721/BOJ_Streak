#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buf[100];
	char	str[1000000];
	int		idx;
	int		score;
	int		count;

	while (fgets(buf, sizeof(buf), stdin))
		strcat(str, buf);

	idx = 0;
	while (str[idx] != '\n')
		idx++;
	idx++;
	while (str[idx])
	{
		score = 0;
		count = 0;
		while (str[idx] != '\n' && str[idx])
		{
			if (str[idx] == 'O')
			{
				count++;
				score += count;
			}
			else
				count = 0;
			idx++;
		}
		printf("%d\n", score);
		if (str[idx])
			idx++;
	}
	return (0);
}