#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct _node {
	int key;
	struct _node *left;
	struct _node *right;
}node;

node *head, *tail;
node *stack[MAX];
int top;

void init_stack() {
	top = -1;
}

node* push(node* t) {
	if (top >= MAX - 1) {
		printf("\n	Stack overflow.");
		return NULL;
	}
	stack[++top] = t;
	return t;
}

node* pop() {
	if (top < 0) {
		printf("\n	Stack underflow");
		return NULL;
	}
	return stack[top--];
}

int is_stack_empty() {
	return top == -1;
}

node* queue[MAX];
int front, rear;

void init_queue() {
	rear = front = 0;
}

node *put(node *k) {
	if ((rear + 1) % MAX == front) {
		printf("\n	Queue overflow.");
		return NULL;
	}
	queue[rear] = k;
	rear = ++rear % MAX;
	return k;
}

node *get() {
	node *i;
	if (front == rear) {
		printf("\n	Queue underflow.");
		return NULL;
	}
	i = queue[front];
	front = ++front % MAX;
	return i;
}

int is_queue_empty() {
	return front == rear;
}

void init_tree() {
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->left = tail;
	head->right = tail;
	tail->left = tail;
	tail->right = tail;
}

int is_operator(int k) {
	return (k == '+' || k == '-' || k == '*' || k == '/');
}

node* make_parse_tree(char *p) {
	node* t;
	while (*p) {
		while (*p == ' ') {
			p++;
		}

		t = (node*)malloc(sizeof(node));
		t->key = *p;
		t->left = tail;
		t->right = tail;
		if (is_operator(*p)) {
			t->right = pop();
			t->left = pop();
		}
		push(t);
		p++;
	}
	return pop();
}

int is_legal(char *s) {
	int f = 0;
	while (*s) {
		while (*s == ' ') {
			s++;
		}
		if (is_operator(*s)) {
			f--;
		}
		else f++;
		if (f < 1) break;
		s++;
	}
	return f == 1;
}

void visit(node* t) {
	printf("%c ", t->key);
}

void preorder_traverse(node *t) {
	if (t != tail) {
		visit(t);
		preorder_traverse(t->left);
		preorder_traverse(t->right);
	}
}

void inorder_traverse(node *t) {
	if (t != tail) {
		inorder_traverse(t->left);
		visit(t);
		inorder_traverse(t->right);
	}
}

void postorder_traverse(node *t) {
	if (t != tail) {
		postorder_traverse(t->left);
		postorder_traverse(t->right);
		visit(t);
	}
}

void levelorder_traverse(node *t) {
	put(t);
	while (!is_queue_empty()) {
		t = get();
		visit(t);
		if (t->left != tail) put(t->left);
		if (t->right != tail) put(t->right);
	}
}

int main() {
	char post[256];
	init_stack();
	init_queue();
	init_tree();
	while (1) {
		printf("\n\nInput Postfix expression -> ");
		gets_s(post);
		if (*post == NULL) {
			printf("\n	Program ends...");
			exit(0);
		}
		if (!is_legal(post)) {
			printf("\nExpression is not legal.");
			continue;
		}
		head->right = make_parse_tree(post);

		printf("\nPreorder traverse -> ");
		preorder_traverse(head->right);

		printf("\n\nInorder traverse -> ");
		inorder_traverse(head->right);

		printf("\nPostorder traverse -> ");
		postorder_traverse(head->right);

		printf("\nLevelorder traverse -> ");
		levelorder_traverse(head->right);
	}
}