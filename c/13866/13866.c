#include <stdio.h>
#define abs(x) (x < 0 ? -x : x)

int main(void)
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d", abs(((a + d) - (b + c))));
    return (0);
}