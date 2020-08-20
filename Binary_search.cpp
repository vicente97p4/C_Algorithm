#include<stdio.h>

int bi_search(int key, int a[], int n) {
	int mid;
	int left = 0;
	int right = n - 1;
	while (right >= left) {
		mid = (right + left) / 2;
		if (key == a[mid]) return mid;
		if (key < a[mid]) right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int bi_insert(int key, int a[], int *np) {
	int p = 0;
	int i;
	while (key > a[p] && p < *np) p++;
	for (i = *np; i > p; i--) a[i] = a[i - 1];
	a[p] = key;
	(*np)++;
	return p;
}

int bi_delete(int key, int a[], int *np) {
	int p;
	int i;
	if (*np > 0) {
		if ((p = bi_search(key, a, *np)) < 0) return -1;
		for (i = p + 1; i < *np; i++) a[i - 1] = a[i];
		(*np)--;
		return p;
	}
	return -1;
}