#include <stdio.h>

int main(void)
{
	int 	n, idx, s_idx, s_num, c_idx;
	int 	arr[100000] = {0, };
	int 	stack[100000] = {0, };
	char	str[400010] = "";

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
		scanf("%d", &arr[idx++]);
	
	idx = 0;
	s_num = 1;
	s_idx = 0;
	c_idx = 0;
	while (idx < n)
	{
		while (arr[idx] >= s_num)
		{
			stack[s_idx++] = s_num++;
			str[c_idx++] = '+';
			str[c_idx++] = '\n';
		}

		if (arr[idx] == stack[s_idx - 1])
		{
			stack[--s_idx] = 0;
			str[c_idx++] = '-';
			str[c_idx++] = '\n';
			idx++;
		}
		else
			break;
	}
	if (idx == n)
	{
		str[c_idx] = 0;
		printf("%s", str);
	}
	else
		printf("NO");
	return (0);
}