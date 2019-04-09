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

void retira(TAB* a, int n){
	if (!a) return;
	if (a->esq) {
        if (a->esq->info == n){
            TAB * esq = a->esq
            if (esq->esq && esq->dir) {
            
        }
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
