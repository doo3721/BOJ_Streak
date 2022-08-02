#include <stdio.h>

static int	graph[101][101];
static int	visit[101];

static void	ft_search_graph(int t, int n)
{
	int i;

	i = 1;
	while (i <= n)
	{
		if (graph[t][i])
		{
			visit[i] = 1;
			graph[t][i] = 0;
			ft_search_graph(i, n);
		}
		i++;
	}
}

int main(void)
{
	int	n, k, i, j, count;

	scanf("%d%d", &n, &k);

	while (k)
	{
		scanf("%d%d", &i, &j);
		graph[i][j] = 1;
		graph[j][i] = 1;
		k--;
	}

	ft_search_graph(1, n);

	count = 0;
	i = 2;
	while (i <= n)
		count += visit[i++];
	printf("%d", count);
	return (0);
}