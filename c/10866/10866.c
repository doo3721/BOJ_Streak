#include <stdio.h>
#define MAX 100000

static int	f_idx = 0;
static int	b_idx = MAX - 1;
static int	deque[MAX] = {0, };

void	ft_push_front(int num)
{
	int	idx;

	idx = f_idx;
	while (deque[idx])
		idx++;
	deque[idx] = num;
}

void	ft_push_back(int num)
{
	int	idx;

	idx = b_idx;
	while (deque[idx])
		idx--;
	deque[idx] = num;
}

void	ft_pop_front(void)
{
	int	idx;

	if (deque[f_idx])
	{
		idx = f_idx;
		while (deque[idx])
			idx++;
		printf("%d\n", deque[--idx]);
		deque[idx] = 0;
	}
	else if (deque[b_idx])
	{
		printf("%d\n", deque[b_idx]);
		deque[b_idx] = 0;
		b_idx--;
	}
	else
		printf("-1\n");
}

void	ft_pop_back(void)
{
	int	idx;

	if (deque[b_idx])
	{
		idx = b_idx;
		while (deque[idx])
			idx--;
		printf("%d\n", deque[++idx]);
		deque[idx] = 0;
	}
	else if (deque[f_idx])
	{
		printf("%d\n", deque[f_idx]);
		deque[f_idx] = 0;
		f_idx++;
	}
	else
		printf("-1\n");
}

void	ft_size(void)
{
	int	size;
	int	idx;

	idx = f_idx;
	while (deque[idx])
		idx++;
	size = (idx - f_idx);
	idx = b_idx;
	while (deque[idx])
		idx--;
	size += (b_idx - idx);
	printf("%d\n", size);
}

void 	ft_empty(void)
{
	if (!deque[f_idx] && !deque[b_idx])
		printf("1\n");
	else
		printf("0\n");
}

void	ft_front(void)
{
	int	idx;

	if (deque[f_idx])
	{
		idx = f_idx;
		while (deque[idx])
			idx++;
		printf("%d\n", deque[--idx]);
	}
	else if (deque[b_idx])
		printf("%d\n", deque[b_idx]);
	else
		printf("-1\n");
}

void	ft_back(void)
{
	int	idx;

	if (deque[b_idx])
	{
		idx = b_idx;
		while (deque[idx])
			idx--;
		printf("%d\n", deque[++idx]);
	}
	else if (deque[f_idx])
	{
		printf("%d\n", deque[f_idx]);
	}
	else
		printf("-1\n");
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
	char	buf[15];
	int		num;

	scanf("%d", &count);

	idx = 0;
	while (idx < count)
	{
		scanf("%s", buf);

		if (ft_strcmp(buf, "push_front"))
		{
			scanf("%d", &num);
			ft_push_front(num);	
		}
		else if (ft_strcmp(buf, "push_back"))
		{
			scanf("%d", &num);
			ft_push_back(num);	
		}
		else if (ft_strcmp(buf, "pop_front"))
			ft_pop_front();
		else if (ft_strcmp(buf, "pop_back"))
			ft_pop_back();
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