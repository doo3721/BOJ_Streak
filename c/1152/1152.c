#include <stdio.h>

int	main(void)
{
	int		count;
	int		idx;
	char	buf[1000000];

	fgets(buf, sizeof(buf), stdin);
	idx = 0;
	count = 0;
	while (!(buf[idx] == 0 || buf[idx] == '\n'))
	{
		if (buf[idx] == ' ')
			idx++;
		if (buf[idx] == 0 || buf[idx] == '\n')
			break;
		count++;
		while (buf[idx] >= 33 && buf[idx] <= 126)
			idx++;
	}
	printf("%d", count);
	return (0);
}