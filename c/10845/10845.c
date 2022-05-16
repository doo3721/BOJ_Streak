#include <stdio.h>
#define MAX 100000

static int	len = MAX;
static int	queue[MAX] = {0, };

void	ft_push(int num)
{
	int	idx;

	idx = len - 1;
	while (queue[idx])
		idx--;
	queue[idx] = num;
}

void	ft_pop(void)
{
	if (!queue[len - 1])
	{
		printf("-1\n");
		return ;
	}
	printf("%d\n", queue[len - 1]);
	queue[len - 1] = 0;
	len--;
}

void	ft_size(void)
{
	int	idx;

	idx = len - 1;
	while (queue[idx])
		idx--;
	printf("%d\n", (len - 1) - idx);
}

void 	ft_empty(void)
{
	if (!queue[len - 1])
		printf("1\n");
	else
		printf("0\n");
}

void	ft_front(void)
{
	if (!queue[len - 1])
	{
		printf("-1\n");
		return ;
	}
	printf("%d\n", queue[len - 1]);
}

void	ft_back(void)
{
	int	idx;

	idx = len - 1;
	if (!queue[idx])
	{
		printf("-1\n");
		return ;
	}
	while (queue[idx])
		idx--;
	printf("%d\n", queue[++idx]);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

int main(void)
{
	int		count;
	int		idx;
	char	buf[10];
	int		num;

	scanf("%d", &count);

	idx = 0;
	while (idx < count)
	{
		scanf("%s", buf);

		if (ft_strcmp(buf, "push"))
		{
			scanf("%d", &num);
			ft_push(num);	
		}
		else if (ft_strcmp(buf, "pop"))
			ft_pop();
		else if (ft_strcmp(buf, "size"))
			ft_size();
		else if (ft_strcmp(buf, "empty"))
			ft_empty();
		else if (ft_strcmp(buf, "front"))
			ft_front();
		else if (ft_strcmp(buf, "back"))
			ft_back();
		idx++;
	}
	return (0);
}