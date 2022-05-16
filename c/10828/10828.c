#include <stdio.h>

static int	stack[1000000] = {0, };

void	ft_push(int num)
{
	int	idx;

	idx = 0;
	while (stack[idx])
		idx++;
	stack[idx] = num;
}

void	ft_pop(void)
{
	int	idx;

	idx = 0;
	while (stack[idx])
		idx++;
	if (!idx)
	{
		printf("-1\n");
		return ;
	}
	printf("%d\n", stack[--idx]);
	stack[idx] = 0;
}

void	ft_size(void)
{
	int	idx;

	idx = 0;
	while (stack[idx])
		idx++;
	printf("%d\n", idx);
}

void 	ft_empty(void)
{
	if (!stack[0])
		printf("1\n");
	else
		printf("0\n");
}

void	ft_top(void)
{
	int	idx;

	idx = 0;
	while (stack[idx])
		idx++;
	if (!idx)
	{
		printf("-1\n");
		return ;
	}
	printf("%d\n", stack[--idx]);
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
		else if (ft_strcmp(buf, "top"))
			ft_top();
		idx++;
	}
	return (0);
}