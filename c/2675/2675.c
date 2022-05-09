#include <stdio.h>
#include <string.h>

int	is_alphanumeric(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| c == '\\' || c == '$' || c == '%' || c == '*'
		|| c == '+' || c == '-' || c == '.' || c == '/'
		|| c == ':')
		return (1);
	return (0);
}

int	main(void)
{
	char	str[1000000];
	char	buf[50];
	int		r_count;
	int		idx;
	int		r_idx;

	while (fgets(buf, sizeof(buf), stdin))
		strcat(str, buf);

	idx = 0;
	while (str[idx] != '\n')
		idx++;
	idx++;
	while (str[idx])
	{
		r_count = str[idx] - '0';
		idx = idx + 2;
		while (str[idx] != '\0' && str[idx] != '\n')
		{
			r_idx = 0;
			if (is_alphanumeric(str[idx]))
			{
				while (r_idx < r_count)
				{
					printf("%c", str[idx]);
					r_idx++;
				}
			}
			idx++;
		}
		printf("\n");
		if (str[idx] != '\0')
			idx++;
	}
	return (0);
}