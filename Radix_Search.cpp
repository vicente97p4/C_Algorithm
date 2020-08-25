#include<stdio.h>
#include<stdlib.h>
typedef struct _node {
	struct _node *left;
	struct _node *right;
	int key;
}node;

node *head;

void init_tree(node **p) {
	*p = (node*)malloc(sizeof(node));
	(*p) -> left = NULL;
	(*p)->right = NULL;
}

unsigned bits(unsigned x, int k, int j) {
	return (x >> k) & ~(~0 << j);
}

node *rdx_search(int key, node* base, size_t *num) {
	node* t;
	int b = 0;
	t = base->left;
	while ( t != NULL && key != t->key ) t = bits(key, b++, 1) ? t->right : t->left;
	return t;
}

node* rdx_insert(int key, node* base, size_t* num) {
	node *p, *t;
	int b = 0;
	p = base;
	t = base->left;
	while (t != NULL) {
		if (key == t->key) return NULL;
		p = t;
		t = bits(key, b++, 1) ? t->right : t->left;
	}
	if ((t = (node*)malloc(sizeof(node))) == NULL) return NULL;
	t->key = key;
	t->left = t->right = NULL;
	if (p != base && bits(key, b - 1, 1)  ) p->right = t;
	else p->left = t;
	(*num)++;
	return t;
}

node *rdx_delete(int key, node *base, size_t *num) {
	node *parent, *son, *del, *center;
	int b = 0;
	parent = base;
	del = base->left;
	while (del != NULL && key != del->key) {
		parent = del;
		del = bits(key, b++, 1) ? del->right : del->left;
	}
	if (del == NULL) return NULL;
	if (del->right == NULL) son = del->left;
	else if (del->right->left == NULL) {
		son = del->right;
		son->left = del->left;
	}
	else {
		center = del->right;
		while (center->left->left != NULL) center = center->left;
		son = center->left;
		center->left = son->right;
		son->left = del->left;
		son->right = del->right;
	}
	if (parent != base && bits(key, b - 1, 1))parent->right = son;
	else parent->left = son;
	(*num)--;
	return parent;
}