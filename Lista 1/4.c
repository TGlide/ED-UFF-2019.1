#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ab{
	int info;
	struct ab *esq, *dir;
}TAB;

TAB* cria(int info, TAB* esq, TAB* dir){
	TAB* a;
	a = malloc(sizeof(TAB));
	
	a->esq = esq;
	a->dir = dir;
	a->info = info;
}

void libera(TAB *a) {
	if (!a) return;
	libera(a->esq);
	libera(a->dir);
	free(a);
}

int menor(TAB* a){
	if (!a) return INT_MAX;
	int n = a->info;
	int esq = menor(a->esq);
	int dir = menor(a->dir);
	
	if (esq < n) n = esq;
	if (dir < n) n = dir;
	
	return n;
}

int main(void){
	TAB *a, *b, *c;
	b = cria(6, cria(2, cria(20, NULL , NULL), NULL), NULL);
	c = cria(5, cria(9, NULL, NULL), NULL);
	a = cria(15, b, c);
	
	printf("Menor é %d\n", menor(a));
	
	free(a);
	
	return 0;
}
