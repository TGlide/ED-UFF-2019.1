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

int igual(TAB* a, TAB* b){
	if ((!a && b) || (a && !b)) return 0;
	if (!a && !b) return 1;
	if (a->info != b->info) return 0;
	if (!igual(a->esq, b->esq) || !igual(a->dir, b->dir)) return 0;
	return 1;
}

TAB* copia(TAB* a){
	if(!a) return NULL;
	TAB *res;
	res = cria(a->info, copia(a->esq), copia(a->dir));
	
	return res;
}

int main(void){
	TAB *a, *b, *c;
	b = cria(6, cria(2, cria(20, NULL , NULL), NULL), NULL);
	c = cria(5, cria(9, NULL, NULL), NULL);
	a = cria(15, b, c);
	
	printf("a == b: %d\n", igual(a, b));
	copia(a);
	printf("a == copia(a): %d\n", igual(a, copia(a)));
	
	free(a);
	return 0;
}
