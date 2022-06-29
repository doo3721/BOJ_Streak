#include <stdio.h>
#include <string.h>

int main(void)
{
	char	n[11];
	int		i, l, t;

	scanf("%s", n);
	l = strlen(n);

	while (l)
	{
		i = 0;
		while (i < l - 1)
		{
			if (n[i] < n[i + 1])
			{
				t = n[i];
				n[i] = n[i + 1];
				n[i + 1] = t;
			}
			i++;
		}
		l--;
	}

	printf("%s", n);
	return (0);
}