#include <stdio.h>

int main(void)
{
	int n, i, x, s, ans;
	int a[1001] = {0, };

	scanf("%d", &n);

	i = 0;
	while (i < n)
	{
		scanf("%d", &x);
		a[x]++;
		i++;
	}

	i = 1;
	s = 0;
	ans = 0;
	while (i <= 1000)
	{
		while (a[i])
		{
			s += i;
			ans += s;
			a[i]--;
		}
		i++;
	}

	printf("%d", ans);

	return (0);
}