#include <stdio.h>

int main(void)
{
	int n;
	int idx;
	int ans;
	
	scanf("%d", &n);

	ans = 0;
	idx = 2;
	if (n == 1)
		ans = 1;
	while (idx <= n)
	{
		ans = ans + 2;
		if (idx < ans)
			ans = 2;
		idx++;
	}
	printf("%d", ans);
}