#include <stdio.h>

int main(void)
{
	char	str[101];
	int		idx, len;

	scanf("%s", str);

	idx = 0;
	len = 0;
	while (str[idx])
	{
		if ((str[idx] == 'c' && (str[idx + 1] == '=' || str[idx + 1] == '-'))
		|| (str[idx] == 'd' && str[idx + 1] == '-')
		|| ((str[idx] == 'l' || str[idx] == 'n') && str[idx + 1] == 'j')
		|| ((str[idx] == 's' || str[idx] == 'z') && str[idx + 1] == '='))
		{
			len++;
			idx += 2;
			continue;
		}
		else if (str[idx] == 'd' && (str[idx + 1] != 0 && str[idx + 1] == 'z' && str[idx + 2] == '='))
		{
			len++;
			idx += 3;
			continue;
		}
		len++;
		idx++;
	}
	printf("%d", len);
	return (0);
}