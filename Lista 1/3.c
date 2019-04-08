#include <stdio.h>
#include <stdlib.h>

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

int maior(TAB* a){
	if (!a) return NULL;
	int n = a->info;
	int esq = maior(a->esq);
	int dir = maior(a->dir);
	
	if (esq > n) n = esq;
	if (dir > n) n = dir;
	
	return n;
}

void libera(TAB *a) {
	if (!a) return;
	libera(a->esq);
	libera(a->dir);
	free(a);
}

int main(void){
	TAB *a, *b, *c;
	b = cria(6, cria(2, cria(18, NULL , NULL), NULL), NULL);
	c = cria(5, cria(9, NULL, NULL), NULL);
	a = cria(15, b, c);
	
	printf("Maior é %d\n", maior(a));
	
	free(a);
	return 0;
}
