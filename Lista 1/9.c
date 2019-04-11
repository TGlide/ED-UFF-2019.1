#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

typedef struct ab{
	int info;
    int cor;  // 0 preto, 1 vermelho
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

int nf(TAB *a){
    if (!a) return 0;
    if (!(a->esq ) && !(a->dir))
        return 1;
    else{
        int n = 0;
        if (a->esq) n += nf(a->esq);
        if (a->dir) n += nf(a->dir);
        return n;
    }    
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
    
    printf("\nEssa arvore tem %d nós folha.\n", nf(a));
	
	libera(a);
	return 0;
}
