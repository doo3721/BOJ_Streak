#include <stdio.h>

int	main(void)
{
	int	n;
	int ans;
	
	scanf("%d", &n);

	ans = 0;
	while (n % 5)
	{
		n -= 3;
		ans++;
		if (n < 0)
			break ;
	}
	ans += n / 5;
	if (n < 0)
		ans = -1;
	printf("%d", ans);
	return (0);
}