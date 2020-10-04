//2017030073_¿Ã∞≠πŒ_11802
#include<stdio.h>

int arr[100003];
int ext[1000000];
int count = 0;
int excounter = 0;
void percDown(int index);
void percUp(int index);
void extract();
int main() {
	int key, value, index, sub;
	while (1) {
		scanf("%d", &key);
		if (!key) break;
		switch (key) {
		case 1:
			scanf("%d", &value);
			arr[++count] = value;
			percUp(count);
			break;
		case 2:
			if (count >= 1) extract();
			break;
		case 3:
			scanf("%d %d", &index, &sub);
			if (count >= 1) {
				arr[index] = sub;
				percUp(index);
			}
			break;
		}
	}
	for (int i = 1; i <= excounter; i++) printf("%d ", ext[i]);
	if(excounter)printf("\n");
	
	for (int i = 1; i <= count; i++) printf("%d ", arr[i]);
	if(count)printf("\n");
	
	return 0;
}
void percDown(int index) {
	int parent = index, child = index * 2, temp;
	while (child <= count) {
		if (child < count && arr[child] <= arr[child + 1])child++;
		if (arr[parent] < arr[child]) {
			temp = arr[parent];
			arr[parent] = arr[child];
			arr[child] = temp;
		}
		else break;
		parent = child;
		child = child * 2;
	}
}
void percUp(int index) {
	int parent = index;
	while (parent > 0) {
		percDown(parent);
		parent /= 2;
	}
}
void extract() {
	int i, child, last;
	ext[++excounter] = arr[1];
	last = arr[count--];

	for (i = 1; i * 2 <= count; i = child) {
		child = i * 2;
		if (child <= count && arr[child] <= arr[child + 1])child++;
		if (last < arr[child]) arr[i] = arr[child];
		else break;
	}
	arr[i] = last;
}