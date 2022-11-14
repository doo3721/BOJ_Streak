/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10757.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 00:10:19 by doohkim           #+#    #+#             */
/*   Updated: 2022/11/15 00:10:22 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	ft_big_sum(char *dest, char *src, int d_len, int s_len)
{
	int		idx, sum, s_idx;
	char	fnt;

	idx = 1;
	fnt = '0';
	while (s_len - idx >= 0)
	{
		sum = dest[d_len - idx] + src[s_len - idx] - '0' * 2;

		if (sum >= 10)
		{
			if (d_len - idx > 0)
			{
				s_idx = 1;
				while (d_len - idx - s_idx >= 0 && dest[d_len - idx - s_idx] - '0' + 1 >= 10)
				{
					dest[d_len - idx - s_idx] = '0';
					fnt = '1';
					s_idx++;
				}

				if (d_len - idx - s_idx >= 0)
				{
					fnt = '0';
					dest[d_len - idx - s_idx] += 1;
				}

				dest[d_len - idx] = sum % 10 + '0';
			}
			else
			{
				fnt = '1';
				dest[d_len - idx] = sum % 10 + '0';
			}

		}
		else
			dest[d_len - idx] = sum + '0';
 		idx++;
	}

	return (fnt);
}

int main(void)
{
	char	a[10002];
	char	b[10002];
	char	fnt;
	int		a_len, b_len;

	scanf("%s%s", a, b);

	a_len = strlen(a);
	b_len = strlen(b);

	if (a_len >= b_len)
	{
		fnt = ft_big_sum(a, b, a_len, b_len);
		if (fnt == '1')
			printf("%c%s", fnt, a);
		else
			printf("%s", a);
	}
	else
	{
		fnt = ft_big_sum(b, a, b_len, a_len);
		if (fnt == '1')
			printf("%c%s", fnt, b);
		else
			printf("%s", b);
	}

	return (0);
}
