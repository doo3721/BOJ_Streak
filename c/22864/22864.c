#include <stdio.h>

int main(void)
{
	int a, b, c, m, idx, a_n, ans;

	scanf("%d%d%d%d", &a, &b, &c, &m);

	idx = 0;
	a_n = 0;
	ans = 0;
	while (idx < 24)
	{
		if (a_n + a <= m)
		{
			a_n += a;
			ans += b;
		}
		else
		{
			a_n -= c;
			if (a_n < 0)
				a_n = 0;
		}
		idx++;
	}
	printf("%d", ans);
	return (0);
}