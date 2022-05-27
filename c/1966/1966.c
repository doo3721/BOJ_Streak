#include <stdio.h>

int main(void)
{
	int t, n, m, q_front, q_last, p_max, count;
	int queue[1000] = {0, };
	int prior[10] = {0, };

	scanf("%d", &t);

	while (t--)
	{
		scanf("%d%d", &n, &m);
		
		q_last = 0;
		while (q_last < n)
		{
			scanf("%d", &queue[q_last]);
			prior[queue[q_last]]++;
			q_last++;
		}

		p_max = 9;
		while (!prior[p_max] && p_max)
			p_max--;

		q_front = 0;
		count = 0;
		while (m >= q_front)
		{
			while (queue[q_front] < p_max)
			{
				queue[q_last] = queue[q_front];
				queue[q_front] = 0;
				if (m == q_front)
					m = q_last;
				q_front++;
				q_last++;
			}
			
			queue[q_front] = 0;
			q_front++;
			count++;
			prior[p_max]--;

			while (!prior[p_max] && p_max)
				p_max--;
		}

		printf("%d\n", count);
		while (p_max)
		{
			prior[p_max] = 0;
			p_max--;
		}
	}
	return (0);
}