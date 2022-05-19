#include <stdio.h>

int	main(void)
{
	int		count;
	int		idx;
	char	str[55];
	int		s_idx;
	int		check;

	scanf("%d", &count);
	idx = 0;
	while (idx < count)
	{
		scanf("%s", str);
		s_idx = 0;
		check = 0;
		while (str[s_idx])
		{
			if (str[s_idx] == '(')
				check++;
			else if (str[s_idx] == ')')
				check--;
			if (check < 0)
				break ;
			s_idx++;
		}
		if (!str[s_idx] && !check)
			printf("YES\n");
		else
			printf("NO\n");
		idx++;
	}
	return (0);
}