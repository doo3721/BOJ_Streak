#include <stdio.h>

int main(void)
{
	int t, n, a, b;

	scanf("%d%d", &t, &n);

	while (n)
	{
		scanf("%d%d", &a, &b);
		t -= a * b;
		n--;
	}
	if (!t)
		printf("Yes");
	else
		printf("No");
	return (0);
}