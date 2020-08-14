#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NAME_SIZE 21
#define CORP_SIZE 31
#define TEL_SIZE 16
#define REC_SIZE (NAME_SIZE + CORP_SIZE + TEL_SIZE)

typedef struct _card {
	char name[NAME_SIZE];
	char corp[CORP_SIZE];
	char tel[TEL_SIZE];
	struct _card *next;
}card;

card *head, *tail;

void init_card() {
	head = (card*)malloc(sizeof(card));
	tail = (card*)malloc(sizeof(card));
	head->next = tail;
	tail->next = tail;
}

void input_card() {
	card* t;
	t = (card*)malloc(sizeof(card));

	printf("\nInput namecard menu: ");
	printf("\n	Input name -> ");
	gets_s(t->name);
	printf("\n	Input corporation -> ");
	gets_s(t->corp);
	printf("\n	Input telephone number -> ");
	gets_s(t->tel);

	t->next = head->next;
	head->next = t;
}

void print_card(card* t, FILE* f) {
	fprintf(f, "\n%-20s	%-30s	%-15s", t->name, t->corp, t->tel);
}

void print_header(FILE* f) {
	fprintf(f, "\nName		""Corporation		""Telephone number");
	fprintf(f, "\n----------	""---------------	""		----------");
}

int delete_card(char *s) {
	card *t;
	card *p;
	p = head;
	t = p->next;
	while (strcmp(s, t->name) != 0 && t != tail) {
		p = p->next;
		t = p->next;
	}
	if (t == tail) return 0;
	p->next = t->next;
	free(t);
	return 1;
}

card* search_card(char *s) {
	card *t;
	t = head->next;
	while (strcmp(s, t->name) != 0 && t != tail) {
		t = t->next;
	}
	if (t == tail) {
		return NULL;
	}
	else return t;
}

void save_cards(const char *s) {
	FILE *fp;
	card *t;
	if ((fp == fopen(s, "rw")) == NULL) {
		printf("\n	Error : Disk write failure.");
		return;
	}
	t = head->next;
	while (t != tail) {
		fwrite(t, REC_SIZE, 1, fp);
		t = t->next;
	}
	fclose(fp);
}

void load_cards(const char* s) {
	FILE* fp;
	card* t;
	card* u;
	if ((fp = fopen(s, "rw")) == NULL) {
		printf("\n	Error : %s is not exist.", s);
		return;
	}
	t = head->next;
	while (t != tail) {
		u = t; t = t->next; free(u);
	}
	head->next = tail;
	while (1) {
		t = (card*)malloc(sizeof(card));
		if (!fread(t, REC_SIZE, 1, fp)) {
			free(t);
			break;
		}
		t->next = head->next;
		head->next = t;
	}
	fclose(fp);
}

int select_menu() {
	int i;
	char s[10];
	printf("\n\nNAMECARD Manager");
	printf("\n-------------------");
	printf("\n1. Input Namecard");
	printf("\n2. Delete Namecard");
	printf("\n3. Search Namecard");
	printf("\n4. Load Namecard");
	printf("\n5. Save Namecard");
	printf("\n6. List Namecard");
	printf("\n7. Print Namecard");
	printf("\n8. End Program");
	do {
		printf("\n\n	: select operation -> ");
		i = atoi(gets_s(s));
	} while (i < 0 || i>8);
	return i;
}

int main() {
	const char* fname = "NAMECARD.DAT";
	char name[NAME_SIZE];
	int i;
	card *t;
	init_card();
	while ((i = select_menu()) != 8) {
		switch (i) {
		case 1: input_card();
				break;
		case 2: printf("\n	Input name to delete -> ");
			gets_s(name);
			if (!delete_card(name)) printf("\n	Can't find that name.");
				break;
		case 3: printf("\n	Input name to search -> ");
			gets_s(name);
			t = search_card(name);
			if (t == NULL) {
				printf("\n	Can't find that name.");
				break;
			}
			print_header(stdout);
			print_card(t, stdout);
				break;
		case 4: load_cards(fname);
				break;
		case 5: save_cards(fname);
				break;
		case 6: t = head->next;
			print_header(stdout);
			while (t != tail) {
				print_card(t, stdout);
				t = t->next;
			}
				break;
		case 7: t = head->next;
			print_header(stdout);
			while (t != tail) {
				print_card(t, stdout);
				t = t->next;
			}
				break;
		}
	}
	printf("\n\nProgram ends...");
}