#include<stdio.h>
#include<stdlib.h>
#define init_stack() (top=-1)
#define push(data) (stack[++top]=data)
#define pop() (stack[top--])
#define is_stack_empty() (top<0)

int top = -1;
int stack[1000];

void quick_sort(int a[], int n) {
	int v, t;
	int i, j;
	if (n > 1) {
		v = a[n - 1];
		i = -1;
		j = n - 1;
		while (1) {
			while (a[++i] < v);
			while (a[--j] > v);
			if (i >= j)break;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
		t = a[i];
		a[i] = a[n - 1];
		a[n - 1] = t;
		quick_sort(a, i);
		quick_sort(a + i + 1, n - i - 1);
	}
}

void quick_sort_iter(int a[], int n) {
	int v, t;
	int i, j;
	int l, r;
	init_stack();
	l = 0; r = n - 1;
	push(r);
	push(l);
	while (!is_stack_empty()) {
		l = pop();
		r = pop();
		if (r - 1 + 1 > 200) {
			t = (r + l) >> 1;
			if (a[l] > a[t]) {
				v = a[l];
				a[l] = a[t];
				a[t] = v;
			}
			if (a[l] > a[r]) {
				v = a[l];
				a[l] = a[r];
				a[r] = v;
			}
			if (a[t] > a[r]) {
				v = a[t];
				a[t] = a[r];
				a[r] = v;
			}
			v = a[t];
			a[t] = a[r - 1];
			a[r - 1] = v;
			i = l;
			j = r - 1;

			while (1) {
				while (a[++i] < v);
				while (a[--j] > v);
				if (i >= j)break;
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}

			t = a[i];
			a[i] = a[r];
			a[r] = t;
			push(r);
			push(i + 1);
			push(i - 1);
			push(l);

		}
		else {
			insert_sort(a + 1, r - l + 1);
		}
	}
	
}