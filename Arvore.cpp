#include <stdio.h>
#include <stdlib.h>

#include "titulo.h"

typedef struct no {
	int valor;
	struct no* esq;
	struct no* dir;
} No;


No *mirror;

No* inicializa() {
	return NULL;
}

No* cria(int c, No* sae, No* sad) {
	
	No* p = (No*) malloc(sizeof(No));
	p->valor = c;
	p->esq = sae;
	p->dir = sad;
	return p;
	
}

int vazia(No* a) {
	
	return a == NULL;
}

void imprimePreOrdem(No* a) {   // IMPORTANTE - TRATAR RAIZ, PERCORRE ESQUERDA, PERCORRE DIREITA
	
	if (!vazia(a)) {
		
		printf(" %d ", a->valor);  // RAIZ
		imprimePreOrdem(a->esq);  // ESQUERDA
		imprimePreOrdem(a->dir);  // DIREITA
	}
}

void imprimeEmOrdem(No* a) {   // IMPORTANTE - PERCORRER ESQUERDA, TRATAR RAIZ, PERCORRER DIREITA
	
	if (!vazia(a)) {
		
		imprimeEmOrdem(a->esq);   // ESQUERDA 
		printf(" %d ", a->valor);  // RAIZ
		imprimeEmOrdem(a->dir);   // DIREITA
	}
}

void imprimePosOrdem(No* a) {    // IMPORTANTE - PERCORRER ESQUERDA, PERCORRER DIREITA, TRATAR RAIZ
	
	if (!vazia(a)) {
		
		imprimePosOrdem(a->esq);  // ESQUERDA
		imprimePosOrdem(a->dir);  // DIREITA
		printf(" %d ", a->valor);  // RAIZ
	}
}

No * mirrorTree(No* a) {
	
	
	if (!vazia(a)) {
		
		No *mirror = (No*) malloc(sizeof(No));
		
		mirror = a;
		
		No* aux;
		
		aux = mirror->esq;
		
		mirror->esq = mirror->dir;
		mirror->dir = aux;		
		
		mirrorTree(a->esq);
		mirrorTree(a->dir);
		
		return mirror;
		
	}
}

void printArvore(){
	
	FILE* arquivo = fopen("arvoresprint.txt", "r");
    if(arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.txt.");
    }

    char linha[4096];
    while(fgets(linha, sizeof(linha), arquivo) != NULL) {
    	/* note como não precisamos especificar uma nova linha, o fgets já a inclui na string linha quando a encontra */
        printf("%s", linha);
    }

    fclose(arquivo);
}

main(){
	
	No* a1 = cria(1, inicializa(),inicializa());
	No* a3 = cria(3, inicializa(),inicializa());
	No* a4 = cria(8, inicializa(),inicializa());
	No* a5 = cria(5, inicializa(),inicializa());
	
	No* a2 = cria(2, a1, a3);
		
	No* a6 = cria(10,a4,inicializa());
		
	No* a7 = cria(6, a5,a6);
	
	No* a = cria(4, a2, a7);
	
    assinatura();
	
	printf("\n Impressao Pre-Ordem (prefixa):\n");
	imprimePreOrdem(a);
	printf("\n Impressao Em Ordem (infixa):\n");
	imprimeEmOrdem(a);
	printf("\n Impressao Pos-Ordem (posfixa):\n");
	imprimePosOrdem(a);
	printf("\n\n");
	
	mirror = mirrorTree(a);
	printArvore();
	
	printf("\n Impressao Pre-Ordem (prefixa) - Espelho:\n");
	imprimePreOrdem(a);
	printf("\n Impressao Em Ordem (infixa) - Espelho:\n");
	imprimeEmOrdem(a);
	printf("\n Impressao Pos-Ordem (posfixa) - Espelho:\n");
	imprimePosOrdem(a);
}
