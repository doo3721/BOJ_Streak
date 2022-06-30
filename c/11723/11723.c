#include <stdio.h>
#include <string.h>

static int	s[21] = {0, };

void	ft_add(int x)
{
	if (!s[x])
		s[x] = 1;
}

void	ft_remove(int x)
{
	if (s[x])
		s[x] = 0;
}

void	ft_check(int x)
{
	printf("%d\n", s[x]);
}

void	ft_toggle(int x)
{
	if (s[x])
		s[x] = 0;
	else
		s[x] = 1;
}

void	ft_all(void)
{
	int i;

	i = 1;
	while (i <= 20)
		s[i++] = 1;
}

void	ft_empty(void)
{
	int i;

	i = 1;
	while (i <= 20)
		s[i++] = 0;
}

int main(void)
{
	int		n, x;
	char	str[7];

	scanf("%d", &n);

	while (n)
	{
		scanf("%s", str);

		if (!strcmp(str, "add"))
		{
			scanf("%d", &x);
			ft_add(x);
		}
		else if (!strcmp(str, "remove"))
		{
			scanf("%d", &x);
			ft_remove(x);
		}
		else if (!strcmp(str, "check"))
		{
			scanf("%d", &x);
			ft_check(x);
		}
		else if (!strcmp(str, "toggle"))
		{
			scanf("%d", &x);
			ft_toggle(x);
		}
		else if (!strcmp(str, "all"))
			ft_all();
		else if (!strcmp(str, "empty"))
			ft_empty();
			
		n--;
	}
	return (0);
}