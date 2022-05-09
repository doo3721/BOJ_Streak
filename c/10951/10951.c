#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[1000000];
	char	buf[5];
	int		idx;
	int		num;

	while (fgets(buf, sizeof(buf), stdin) > 0)
		strcat(str, buf);

	idx = 0;
	while (str[idx] != '\0')
	{
		num = 0;
		while (str[idx] != '\n' && str[idx] != '\0')
		{
			if (str [idx]>= '1' && str[idx] <= '9')
				num = num + str[idx] - '0';
			idx++;
		}
		printf("%d\n", num);
		if (str[idx] != '\0')
			idx++;
	}
	return (0);
}