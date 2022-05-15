#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int	count;
	int	idx;
	int	h;
	int	w;
	int	n;
	int *answer;

	scanf("%d", &count);
	answer = malloc(sizeof(int) * count);
	if (!answer)
		return (0);
	
	idx = 0;
	while (idx < count)
	{
		scanf("%d", &h);
		scanf("%d", &w);
		scanf("%d", &n);

		answer[idx] = (n % h ? (n % h * 100) : (h * 100));
		answer[idx] += (n % h ? (n / h + 1) : (n / h));
		idx++;
	}

	idx = 0;
	while (idx < count)
	{
		printf("%d\n", answer[idx]);
		idx++;
	}
	free(answer);
	return (0);
}