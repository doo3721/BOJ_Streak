#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	s[500000][21];
static int	a[500000];

int	ft_cmp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int	ft_search(char s[][21], char *t, int n)
{
	int l, r, m;

	l = 0;
	r = n;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (!strcmp(s[m], t))
			return (m);
		else if (strcmp(s[m], t) > 0)
			r = m - 1;
		else
			l = m + 1;
	}
	return (-1);
}

int main(void)
{
	int		n, m, i, c, x;

	char	t[21];

	scanf("%d%d", &n, &m);

	i = 0;
	while (i < n)
		scanf("%s", s[i++]);

	qsort(s, n, sizeof(s[0]), ft_cmp);

	i = 0;
	c = 0;
	while (i < m)
	{
		scanf("%s", t);
		x = ft_search(s, t, n - 1);
		if (x != -1)
		{
			a[x] = 1;
			c++;
		}
		i++;
	}

	printf("%d\n", c);
	i = 0;
	while (i < n)
	{
		if (a[i])
			printf("%s\n", s[i]);
		i++;
	}
	return (0);
}