#include<stdio.h>

void insertion_sort(int a[], int n) {
	int i, j, t;
	for (i = 1; i < n; i++) {
		t = a[i];
		j = i;
		while ( j > 0 && a[j - 1] > t) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = t;
	}
}

void indirect_insert_sort(int a[], int index[], int n) {
	int i, j;
	int t;
	for (i = 0; i < n; i++)
		index[i] = i;
	for (i = 1; i < n; i++) {
		t = index[i];
		j = i;
		while (j > 0 && a[index[j - 1]] > a[t]) {
			index[j] = index[j - 1];
			j--;
		}
		index[j] = t;
	}
}