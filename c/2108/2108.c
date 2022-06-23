#include <stdio.h>

void	ft_merge(int *a, int left, int right, int mid)
{
	int l, r, idx;
	int temp[500000];

	l = left;
	r = mid + 1;
	idx = 0;

	while (l <= mid && r <= right)
	{
		if (a[l] <= a[r])
			temp[idx++] = a[l++];
		else
			temp[idx++] = a[r++];
	}

	while (l <= mid)
		temp[idx++] = a[l++];
	while (r <= right)
		temp[idx++] = a[r++];

	l = left;
	idx = 0;

	while (l <= right)
		a[l++] = temp[idx++];
}

void	ft_mergesort(int *a, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		ft_mergesort(a, left, mid);
		ft_mergesort(a, mid + 1, right);
		ft_merge(a, left, right, mid);
	}
}

int main(void)
{
	int		n, idx, f_max, f_count;
	int 	fv[2];
	double	avg;
	int		arr[500000];

	scanf("%d", &n);
	idx = 0;
	avg = 0;
	while (idx < n)
	{
		scanf("%d", &arr[idx]);
		avg += (double) arr[idx++];
	}

	avg /= (float) n;

	ft_mergesort(arr, 0, n - 1);

	idx = 0;
	f_max = 0;
	fv[0] = arr[0];
	fv[1] = -10000;
	while (idx < n - 1)
	{
		f_count = 1;
		while (idx < n - 1 && arr[idx] == arr[idx + 1])
		{
			f_count++;
			idx++;
		}
		if (f_count > f_max)
		{
			fv[0] = arr[idx];
			fv[1] = -10000;
			f_max = f_count;
		}
		else if (f_count == f_max && fv[1] == -10000)
			fv[1] = arr[idx];
		idx++;
	}

	printf("%.f\n", ((avg >= -0.5 && avg < 0) ? -avg : avg));
	printf("%d\n", arr[n / 2]);
	printf("%d\n", (fv[1] != -10000 ? fv[1] : fv[0]));
	printf("%d", arr[n - 1] - arr[0]);

	return (0);
}