#include <stdio.h>

int	main(void)
{
	char c;
	
	scanf("%c", &c);

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
		printf("%d", c);
	
	return (0);
}