#include <stdio.h>

int	main(void)
{
	double	avg;
	int		idx;
	int		count;
	double	score;
	double	max_score;
	double	a_score[1000];

	scanf("%d", &count);
	idx = 0;
	max_score = 0;
	while (idx < count)
	{
		scanf("%lf", &score);
		a_score[idx] = score;
		if (max_score < score)
			max_score = score;
		idx++;
	}
	idx = 0;
	avg = 0;
	while (idx < count)
	{
		avg = avg + (a_score[idx] / max_score * 100);
		idx++;
	}
	printf("%lf", avg / (double) count);
	return (0);
}