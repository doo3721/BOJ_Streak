#include <stdio.h>
#include <string.h>

int	main(void)
{
	int		sum;
	int		idx;
	char	buf[110];
	char	str[200];

	while (fgets(buf, sizeof(buf), stdin))
		strcat(str, buf);

	idx = 0;
	while (str[idx] != '\n')
		idx++;
	idx++;
	sum = 0;
	while (str[idx] && str[idx] != '\n')
	{
		sum += (str[idx] - '0');
		idx++;
	}
	printf("%d", sum);
	return (0);
}