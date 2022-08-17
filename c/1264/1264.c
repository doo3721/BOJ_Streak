#include <stdio.h>
#include <unistd.h>

static char	*v = "aeiouAEIOU";

static int	ft_strchr(char t)
{
	int i;

	i = 0;
	while (v[i])
	{
		if (v[i] == t)
			return (i);
		i++;
	}
	return (-1);
}

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
			if (ft_strchr(s[i]) != -1)
				c++;
			i++;
		}
		printf("%d\n", c);
	}
	return (0);

	// 왜 틀리는거지?
}