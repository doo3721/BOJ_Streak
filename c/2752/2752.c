#include <stdio.h>
#include <stdlib.h>

static int a[3];

static int ft_cmp(const void *a, const void *b)
{
    int i_a = *(int *)a;
    int i_b = *(int *)b;
    return (i_a - i_b);
}

int main(void)
{
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    qsort(a, 3, sizeof(int), ft_cmp);
    printf("%d %d %d", a[0], a[1], a[2]);
    return (0);
}