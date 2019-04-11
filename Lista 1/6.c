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

TAB* buscaFolha(TAB* a){
    if (!a) return NULL;
    if (!a->esq && !a->dir) return a;
    TAB* b;
    if (a->esq){ 
        b = buscaFolha(a->esq);
        if (b) return b;
    }
    if (a->dir){
        b = buscaFolha(a->dir);
        if (b) return b;
    }
}

void retira(TAB* a, int n) {
    if (a->info == n) {
        if (!a->esq && !a->dir) a->info=-42;
        else{
            TAB * folha = buscaFolha(a);
            int temp = folha->info;
            folha->info = n;
            a->info = temp;
            //libera(folha);
            folha->info = -42;
        }
    } else{
        if(a->esq) retira(a->esq, n);
        if(a->dir) retira(a->dir, n);
    }
}

void retira_pares(TAB* a){
	if (!a) return;
	
    if (a->info%2 == 0) retira(a, a->info);
    if(a->esq) retira_pares(a->esq);
    if(a->dir) retira_pares(a->dir);
}

void pretty_print(TAB *a, int spaces) {
    if(!a) return;
    if (a->dir){ 
        pretty_print(a->dir, spaces + 4);
    }
    
    for (int i = 0; i<spaces;i++) printf(" ");
    printf("%d", a->info);
    printf("\n\n");
    
    if (a->esq){ 
        pretty_print(a->esq, spaces + 4);
    }
}

int main(void){
	TAB *a, *b, *c;
	b = cria(6, cria(20, cria(1, NULL, NULL), cria(1, NULL, NULL)), cria(18, cria(1, NULL, NULL), cria(1, NULL, NULL)));
	c = cria(5, cria(9, cria(1, NULL, NULL), cria(1, NULL, NULL)), cria(21, cria(1, NULL, NULL), cria(1, NULL, NULL)));
	a = cria(15, b, c);
	
    pretty_print(a, 0);
    printf("\n\n");
    //retira(a, 6);
    retira_pares(a);
    pretty_print(a,0);
	
	libera(a);
	return 0;
}

