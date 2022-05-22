#include <stdio.h>

int main(void)
{
	int n, idx, t_idx, rank;
	int x[50] = {0, };
	int y[50] = {0, };

	scanf("%d", &n);

	idx = 0;
	while(idx < n)
	{
		scanf("%d%d", &x[idx], &y[idx]);
		idx++;
	}

	idx = 0;
	while (idx < n)
	{
		rank = n;
		t_idx = 0;
		while (t_idx < n)
		{
			if (x[idx] >= x[t_idx] || y[idx] >= y[t_idx])
				rank--;
			t_idx++;
		}
		printf("%d ", rank + 1);
		idx++;
	}
	return (0);
}