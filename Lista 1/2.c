#include <stdio.h>
#include <stdlib.h>

typedef struct ab{
	int info;
	struct ab *esq, *dir;
}TAB;

TAB* cria(int info){
	TAB* a;
	a = malloc(sizeof(TAB));
	
	a->esq = esq;
	a->dir = dir;
	a->info = info;
}

TAB* espelho(TAB* a){
	TAB *res;
	res = cria(a->info, copia(a->dir), copia(a->esq));
	
	return res;
}

int main (void){
	
	
	return 0;
}
