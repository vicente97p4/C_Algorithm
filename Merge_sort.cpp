#include<stdio.h>
#include<stdlib.h>
void merge_sort(int a[], int n) {
	int i, j, k, first, second, size;
	int *b;
	b = (int*)malloc(sizeof(int)*n);
	for (size = 1; size < n; size *= 2) {
		first = -2 * size;
		second = first + size;
		
		while (second + size * 2 < n) {
			first = second + size;
			second = first + size;
			i = first;
			j = second;
			k = first;
			while (i < first + size || (j < second + size && j < n)) {
				if (a[i] <= a[j]) {
					if (i < first + size)
						b[k++] = a[i++];
					else
						b[k++] = a[j++];
				}
				else {
					if (j < second + size && j < n)
						b[k++] = a[j++];
					else
						b[k++] = a[i++];
				}
			}
		}
		for (i = 0; i < n; i++)
			a[i] = b[i];
	}
	free(b);
}