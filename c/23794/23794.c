#include <stdio.h>

int main(void)
{
	int n, idx, s_idx;

	scanf("%d", &n);

	idx = 1;
	while (idx <= n + 2)
	{
		s_idx = 1;
		if (idx == 1 || idx == n + 2)
		{
			while (s_idx <= n + 2)
			{
				printf("@");
				s_idx++;
			}
		}
		else
		{
			while (s_idx <= n + 2)
			{
				if (s_idx == 1 || s_idx == n + 2)
					printf("@");
				else
					printf(" ");
				s_idx++;
			}
		}
		printf("\n");
		idx++;
	}
	return (0);
}