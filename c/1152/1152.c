#include <stdio.h>

int	main(void)
{
	int		count;
	int		idx;
	char	buf[1000001];

	fgets(buf, sizeof(buf), stdin);
	idx = 0;
	count = 0;
	while (buf[idx] != 0 && buf[idx] != '\n')
	{
		if (buf[idx] == ' ')
			idx++;
		if (buf[idx] == 0 || buf[idx] == '\n')
			break;
		count++;
		while ((buf[idx] >= 'a' && buf[idx] <= 'z') || (buf[idx] >= 'A' && buf[idx] <= 'Z'))
			idx++;
	}
	printf("%d", count);
	return (0);
}