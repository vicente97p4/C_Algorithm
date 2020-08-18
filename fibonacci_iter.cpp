#include<stdio.h>

int main() {
	int r = 0, n;
	int a = 1, b = 1;
	
	scanf("%d", &n);

	if (n == 1 || n == 2) {
		return 1;
	}

	while (n-- > 2) {
		r = a + b;
		a = b;
		b = r;
	}

	printf("%d\n", r);
}