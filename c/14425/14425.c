#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_cmp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int	ft_search(char s[][501], char *t, int n)
{
	int l, r, m;

	l = 0;
	r = n;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (!strcmp(s[m], t))
			return (1);
		else if (strcmp(s[m], t) > 0)
			r = m - 1;
		else
			l = m + 1;
	}
	return (0);
}

int main(void)
{
	int		n, m, i, c;
	char	s[10000][501];
	char	t[501];

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
		c += ft_search(s, t, n - 1);
		i++;
	}

	printf("%d", c);
	return (0);
}