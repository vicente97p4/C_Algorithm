#include<stdio.h>

int li_search(int key, int a[], int *num) {
	int i = 0;
	while (a[i] != key && i < *num) i++;
	return (i < *num ? i : -1);
}

int li_delete(int key, int a[], int *num) {
	int p;
	int i;
	if (*num > 0) {
		if ((p = li_search(key, a, num)) < 0) return -1;
		for (i = p + 1; i < *num; i++) a[i - 1] = a[i];
		(*num)--;
		return p;
	}
	return -1;
}