#include <stdio.h>

static int	n;
static char	bit[1000001];

int	main(void)
{
	int	i, ans;
	
	scanf("%d%s", &n, bit);

	ans = 0;
	i = 0;
	while (i < n)
		ans += (bit[i++] - '0');
	printf("%d", ans);
	return (0);
}