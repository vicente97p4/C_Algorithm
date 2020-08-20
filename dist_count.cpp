#include<stdio.h>
#include<stdlib.h>
void dist_count(int a[], int n, int m) {
	int i;
	int* b, *count;
	b = (int*)malloc(sizeof(int)*n);
	count = (int*)malloc(sizeof(int)*(m + 1));
	for (i = 0; i <= m; i++) count[i] = 0;
	for (i = 0; i < n; i++) count[a[i]]++;
	for (i = 2; i <= m; i++) count[i] = count[i - 1] + count[i];
	for (i = n - 1; i >= 0; i--) b[--count[a[i]]] = a[i];
	for (i = 0; i < n; i++) a[i] = b[i];
	free(b);
	free(count);
}