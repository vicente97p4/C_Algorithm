#include<stdio.h>
#include<stdlib.h>
typedef struct _node {
	int key;
	struct _node *next;
}node;
node* head;

void insert_nodes(int k) {
	node* t;
	int i;
	t = (node*)malloc(sizeof(node));
	t->key = 1;
	head = t;

	for (i = 2; i <= k; i++) {
		t->next = (node*)malloc(sizeof(node));
		t = t->next;
		t->key = i;
	}
	t->next = head;
}
void delete_after(node* t) {
	node* s;
	s = t->next;
	t->next = s->next;
	free(s);
}
void josephus(int n, int m) {
	node* t; node* first;
	int i, count=0;
	insert_nodes(n);
	t = head;
	first = t;
	printf("\nAnswer : ");
	printf("%d ", first->key);
	
	while (t != t->next) {
		for (i = 0; i < m - 1; i++) {
			t = t->next;
		}
		if (count == 0) {
			while (first->next != head)
				first = first->next;
			first->next = head->next;
			free(head);
		}
		
			printf("%d ", t->next->key);
			delete_after(t);
		
		count++;
	}
	printf("%d", t->key);
}

void main() {
	int n, m;
	printf("\nIf you want to quit, enter 0 or minus value");
	while (1) {
		printf("\nEnter N and M -> ");
		scanf("%d %d", &n, &m);
		if (n <= 0 || m <= 0) return;
		josephus(n, m);
	}
}