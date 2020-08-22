#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

typedef struct _node {
	int key;
	struct _node *left;
	struct _node *right;
}node;

node* bti_search(int key, node* base, int *num) {
	node* s;
	s = base->left;
	while (key != s->key && s != NULL) {
		if (key < s->key) s = s->left;
		else s = s->right;
	}
	if (s == NULL) return NULL;
	else return s;
}

node* bti_insert(int key, node *base, int *num) {
	node *p, *s;
	p = base;
	s = base->left;
	while (s != NULL) {
		p = s;
		if (key < s->key) s = s->left;
		else s = s->right;
	}
	if ((s = (node*)malloc(sizeof(node))) == NULL) return NULL;
	s->key = key;
	s->left = NULL;
	s->right = NULL;
	if (key < p->key || p == base) p->left = s;
	else p->right = s;
	(*num)++;
	return s;
}

node* bti_delete1(int key, node* base, int *num) {//����ȭ���� ���� �������
	node* parent, *son, *del, *nexth;
	parent = base;
	del = base->left;
	
	while (key != del->key && del != NULL) {
		parent = del;
		if (key < del->key) del = del->left;
		else del = del->right;
	}

	if (del == NULL) return NULL;
	if (del->left == NULL && del->right == NULL) son = NULL; // ��������� ��
	else if (del->left != NULL && del->right != NULL) { // �ڽ��� 2�� ���� ��
		nexth = del->right;
		if (nexth->left != NULL) {//������ �ڽĳ�忡 ���� �ڽ� ��尡 ���� ��
			while (nexth->left->left != NULL) nexth = nexth->left;
			son = nexth->left;
			nexth->left = son->right;
			son->left = del->left;
			son->left = del->left;
			son->right = del->right;
		}
		else { // ������ �ڽ� ��忡 ���� �ڽ� ��尡 ���� ��
			son = nexth;
			son->left = del->left;
		}
	}
	else {//�� �� �ڽĸ� ���� ��
		if (del->left != NULL) son = del->left;//���ʿ��� �ڽ��� ���� ��
		else son = del->right; // �����ʿ��� �ڽ��� ���� ��
	}
	if (key < parent->key || parent == base) parent->left = son;
	else parent->right = son;
	free(del);
	(*num)--;
	return parent;
}

node* bti_delete(int key, node* base, int *num) {
	node* parent, *son, *del, *nexth;
	parent = base;
	del = base->left;
	while (key != del->key && del != NULL) {
		parent = del;
		if (key < del->key) del = del->left;
		else del = del->right;
	}
	if (del == NULL) return NULL;
	if (del->right == NULL) son = del->left;
	else if (del->right->left == NULL) {
		son = del->right;
		son->left = del->left;
	}
	else {
		nexth = del->right;
		while (nexth->left->left != NULL) nexth = nexth->left;
		son = nexth->left;
		nexth->left = son->right;
		son->left = del->left;
		son->right = del->right;
	}
	if (key < parent->key || parent == base) parent->left = son;
	else parent->right = son;
	free(del);
	(*num)--;
	return parent;
}

int index = 0;
int array[MAX];

void bti_sort(node* p) {
	if (p != NULL) {
		bti_sort(p->left);
		array[index++] = p->key;
		bti_sort(p->right);
	}
}

node *_balance(int n) {
	int nl, nr;
	node* p;
	if (n > 0) {
		nl = (n - 1) / 2;
		nr = n - nl - 1;
		p = (node*)malloc(sizeof(node));
		p->left = _balance(nl);
		p->key = array[index++];
		p->right = _balance(nr);
		return p;
	}
	else return NULL;
}

void bti_balance(node* base, int *num) {
	int ntmp;
	index = 0;
	bti_sort(base->left);
	ntmp = *num;
	index = 0;
	base->left = _balance(ntmp);
	*num = ntmp;
}