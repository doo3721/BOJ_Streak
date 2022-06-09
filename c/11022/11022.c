#include <stdio.h>

int main(void)
{
	int t, a, b, idx;

	scanf("%d", &t);

	idx = 1;
	while (idx <= t)
	{
		scanf("%d%d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", idx, a, b, a + b);
		idx++;
	}
	return (0);
}