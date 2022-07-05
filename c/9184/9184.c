#include <stdio.h>

static int w[21][21][21] = {0, };

int ft_w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return (1);
	if (a > 20 || b > 20 || c > 20)
		return ft_w(20, 20, 20);
	if (w[a][b][c] != 0)
		return (w[a][b][c]);
	if (a < b && b < c)
		return (w[a][b][c] = ft_w(a, b ,c - 1) + ft_w(a, b - 1, c - 1) - ft_w(a, b - 1, c));
		
	return (w[a][b][c] = ft_w(a - 1, b, c) + ft_w(a - 1, b - 1, c) + ft_w(a - 1, b, c - 1) - ft_w(a - 1, b - 1, c - 1));
}

int main(void)
{
	int a, b, c;

	while (1)
	{
		scanf("%d%d%d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)
			break ;
		
		printf("w(%d, %d, %d) = %d\n", a, b, c, ft_w(a, b, c));
	}
	return (0);
}