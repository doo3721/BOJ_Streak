#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	n;

typedef	struct pokemon
{
	char	name[21];
	int		no;
}	poke;

void	ft_merge(poke *dex, int left, int right, int mid)
{
	int		i_l, i_r, i_t;
	poke	temp[n];

	i_l = left;
	i_r = mid + 1;
	i_t = left;

	while (i_l <= mid && i_r <= right)
	{
		if (strcmp(dex[i_l].name, dex[i_r].name) <= 0)
			temp[i_t++] = dex[i_l++];
		else
			temp[i_t++] = dex[i_r++];
	}
	while (i_l <= mid)
		temp[i_t++] = dex[i_l++];
	while (i_r <= right)
		temp[i_t++] = dex[i_r++];
	i_t--;

	while (i_t >= left)
	{
		dex[i_t] = temp[i_t];
		i_t--;
	}
}

void	ft_mergesort(poke *dex, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		ft_mergesort(dex, left, mid);
		ft_mergesort(dex, mid + 1, right);
		ft_merge(dex, left, right, mid);
	}
}

int	ft_no_search(poke *dex, char *t)
{
	int left, right, mid;

	left = 0;
	right = n - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (strcmp(t, dex[mid].name) < 0)
			right = mid - 1;
		else if (strcmp(t, dex[mid].name) > 0)
			left = mid + 1;
		else
			return (dex[mid].no);
	}

	return (0);
}

int main(void)
{
	int		m, idx, target_no;
	poke	*dex_name_sort;
	poke	*dex_no_sort;
	char	target[21];

	scanf("%d%d", &n, &m);

	dex_name_sort = malloc(sizeof(poke) * n);
	dex_no_sort = malloc(sizeof(poke) * n); 

	idx = 0;
	while (idx < n)
	{
		scanf("%s", dex_name_sort[idx].name);
		strcpy(dex_no_sort[idx].name, dex_name_sort[idx].name);
		dex_name_sort[idx].no = idx + 1;
		dex_no_sort[idx].no = idx + 1;
		idx++;
	}

	ft_mergesort(dex_name_sort, 0, n - 1);

	idx = 0;
	while (idx < m)
	{
		scanf("%s", target);

		if (target[0] >= '0' && target[0] <= '9')
		{
			target_no = atoi(target);
			printf("%s\n", dex_no_sort[target_no - 1].name);
		}
		else
			printf("%d\n", ft_no_search(dex_name_sort, target));
		idx++;
	}
	free(dex_name_sort);
	free(dex_no_sort);
	return (0);
}