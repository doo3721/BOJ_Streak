#include <stdio.h>

int main(void)
{
    double	a, b, c;
    scanf("%lf%lf", &a, &b);

	c = a / 100 * (100 - b);
	c >= 100 ? printf("0") : printf("1");
    return (0);
}