#include <stdio.h>
#include <string.h>

/*
int main(void)
{
	char	s[260];
	int		i, c;
	
	while (read(0, s, 260) > 0)
	{
		if (s[0] == '#')
			break ;
		
		c = 0;
		i = 0;
		while (s[i] != '\n')
		{
			if (strchr("aeiouAEIOU", s[i]))
				c++;
			i++;
		}
		printf("%d\n", c);
	}
	return (0);

	// 왜 틀리는거지?
}
*/

int main(void)
{
	char	s[260];
	int		i, c;
	
	c = 0;
	while (scanf("%s", s) > 0)
	{
		if (s[0] == '#')
			break ;
		
		i = 0;
		while (s[i])
		{
			if (strchr(".?!", s[i]))
			{
				printf("%d\n", c);
				c = 0;
				break ;
			}
			if (strchr("aeiouAEIOU", s[i]))
				c++;
			i++;
		}
	}
	return (0);
}