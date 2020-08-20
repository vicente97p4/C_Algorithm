#include<stdio.h>
int bits(int x, int k, int j) {
	return (x >> k) && ~(~0 << j);
}
void radix_sort(int a[], int n, int b) {
	int t, i, j;
	if (n > 1 && b >= 0) {
		i = 0; j = n - 1;
		while (1) {
			while (bits(a[i], b, 1) == 0 && i < j) i++;
			while (bits(a[j], b, 1) != 0 && i < j)j--;
			if (i >= j)break;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		if (bits(a[n - 1], b, 1) == 0)j++;
		radix_sort(a, j, b - 1);
		radix_sort(a + j, n - j, b - 1);
	}
}