#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_sp_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] && s2[idx])
		idx++;
	if (!s1[idx] && !s2[idx])
	{
		idx = 0;
		while (s1[idx] || s2[idx])
		{
			if (s1[idx] != s2[idx])
				return (s1[idx] - s2[idx]);
			idx++;
		}
	}
	return (s1[idx] - s2[idx]);
}

void	ft_strswap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_quicksort(char **strs, int left, int right)
{
	int		i_l;
	int		i_r;
	char	*pivot;

	i_l = left;
	i_r = right;
	pivot = strs[(left + right) / 2];
	while (i_l <= i_r)
	{
		while (ft_sp_strcmp(strs[i_l], pivot) < 0)
			i_l++;
		while (ft_sp_strcmp(pivot, strs[i_r]) < 0)
			i_r--;
		if (i_l <= i_r)
		{
			ft_strswap(&strs[i_l], &strs[i_r]);
			i_l++;
			i_r--;
		}
	}

	if (left < i_r)
		ft_quicksort(strs, left, i_r);
	if (i_l < right)
		ft_quicksort(strs, i_l, right);
}

int	main(void)
{
	char	**strs;
	char	buf[51];
	int		idx;
	int		count;

	scanf("%d", &count);

	strs = malloc(sizeof(char *) * count);
	if (!strs)
		return (0);
	idx = 0;
	while (idx < count)
	{
		scanf("%s", buf);
		strs[idx] = strdup(buf);
		if (!strs[idx])
			return (0); 
		idx++;
	}

	ft_quicksort(strs, 0, count - 1);

	idx = 0;
	while (idx < count)
	{
		if (idx == 0)
			printf("%s\n", strs[idx]);
		if (idx > 0 && ft_sp_strcmp(strs[idx - 1], strs[idx]) != 0)
			printf("%s\n", strs[idx]);
		idx++;
	}
	free(strs);
	return (0);
}