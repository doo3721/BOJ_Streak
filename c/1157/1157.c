#include <stdio.h>



int	main(void)
{
	char	str[1000000];
	char	max_c;
	int		idx;
	int		max_count;
	int		a_arr[26];

	fgets(str, sizeof(str), stdin);
	idx = 0;
	while (str[idx])
	{
		if (str[idx] >= 'a' && str[idx] <= 'z')
			a_arr[str[idx] - 'a']++;
		else if (str[idx] >= 'A' && str[idx] <= 'Z')
			a_arr[str[idx] - 'A']++;
		idx++;
	}
	idx = 0;
	max_count = 0;
	while (idx < 26)
	{
		if (max_count < a_arr[idx])
		{
			max_count = a_arr[idx];
			max_c = idx + 'A';
		}
		else if (max_count == a_arr[idx])
			max_c = '?';
		idx++;
	}
	printf("%c", max_c);
	return (0);
}