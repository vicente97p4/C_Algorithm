#include<stdio.h>

void selection_sort(int a[], int n) {
	int min;
	int minindex;
	int i, j;

	for (i = 0; i < n - 1; i++) {
		minindex = i;
		min = a[i];
		for (j = i + 1; j < n; j++) {
			if (min > a[j]) {
				min = a[j];
				minindex = j;
			}
		}
		a[minindex] = a[i];
		a[i] = min;
	}
}