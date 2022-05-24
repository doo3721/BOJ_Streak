#include <stdio.h>

int main(void)
{
	char	str[110];
	char	brks[110];
	int		idx, b_idx;

	while (1)
	{
		fgets(str, sizeof(str), stdin);
		if (str[0] == '.' && str[1] == '\n' && str[2] == 0)
			break ;
		
		idx = 0;
		b_idx = 0;
		while (str[idx])
		{
			if (str[idx] == '(' || str[idx] == '[')
				brks[b_idx++] = str[idx];
			else if (str[idx] == ')')
			{
				if (b_idx && brks[b_idx - 1] == '(')
					brks[--b_idx] = 0;
				else
					break ;
			}
			else if (str[idx] == ']')
			{
				if (b_idx && brks[b_idx - 1] == '[')
					brks[--b_idx] = 0;
				else
					break ;
			}
			idx++;
		}
		if (!b_idx && !str[idx])
			printf("yes\n");
		else
			printf("no\n");
	}	
	return (0);
}
/*
	괄호의 종류는 두가지이므로
	단순 counting으로는 제대로 된 형태인지 알 수 없다
	(ex) ([([(]])))
*/