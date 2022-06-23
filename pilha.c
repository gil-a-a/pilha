
/*tem q consertar o pop e outras coisas talvez*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//botei essa var global aq só pra ficar fácil de testar
int a = 1;

//ponteiros
typedef struct nodes_da_pilha{
	int n;
	struct nodes_da_pilha *next;
}Node;

//função pra criar nó/raiz
Node* cria_no()
{
	Node *p;
	
	p = (Node*) malloc(sizeof(Node));
	if (p == NULL)
		return NULL;
	
	p->next = NULL;
	p->n = a++;
	
	return p;
}

//Funcoes gerais:
Node* EsvPilha(Node* P);
bool PilVaz(Node* P);
void Push(int x, Node* P);
//int Posic(int x, Node* L);
int Topo(Node* P);
void Pop(Node* P);
void Printa_Pilha(Node* node);

int main ()
{
	int x, p;
	char resp;
	Node *raiz, *no_aux;
	
	raiz = cria_no();
	
	no_aux = raiz;
	
	while (1){
		printf("Quer inserir mais um elemento na pilha?\n");
			scanf(" %c", &resp);
		if (resp != 'S' && resp != 's')
			break;
		
		no_aux->next = cria_no();
		no_aux = no_aux->next;
		printf("\ninfo: %d\n", no_aux->n);
	}
	
	printf("Insira o numero X para inseri-lo na pilha: ");
		scanf("%d", &x);
	Push(x, raiz);
	
	Printa_Pilha(raiz);
	PilVaz(raiz);
	
	//fazer funcao pra procurar um elemento na pilha
	/*
	printf("\nInsira o numero para procura-lo na pilha: ");
		scanf("%d", &x);
	printf("\nElemento %d encontrado em %d", x, Posic(x, raiz));
	*/
	
	printf("\nQuer ver o elemento do topo? ");
		scanf(" %c", &resp);
	if (resp != 'n' && resp != 'N')
		printf("Elemento: %d", Topo(raiz));
	
	printf("\nQuer retirar um elemento da pilha? ");
		scanf(" %c", &resp);
	if (resp != 'n' && resp != 'N')
		Pop(raiz);
	Printa_Pilha(raiz);
	
	printf("\nEsvaziando pilha...");
	raiz = EsvPilha(raiz);
	printf("\n");
	Printa_Pilha(raiz);
	PilVaz(raiz);
	
	return 0;
}

Node* EsvPilha(Node* P)
{
	if(P->next != NULL)
		EsvPilha(P->next);
	
	free(P);
	P = NULL;
	return P;
}

bool PilVaz(Node* P)
{
	if (P == NULL){
		printf("\nPilha vazia");
		return true;
	}
	else{
		printf("\nPilha nao vazia");
		return false;
	}
}

void Push(int x, Node* P)
{
	Node *aux, *aux_2;
	
	aux = P;
	
	aux_2 = cria_no();
	aux_2->n = x;
	
	while(aux->next != NULL)
		aux = aux->next; //anda até a o fim da pilha
	
	aux->next = aux_2;
}

/*
int Posic(int x, Node* L)
{
	int i = 1;
	Node *aux;
	
	aux = L;
	
	while (aux->n != x){
		i++;
		aux = aux->next;
	}
	
	printf("\n%d na pos: %d", x, i);
	return i;
}
*/

int Topo(Node* P)
{
	Node* aux;
	
	aux = P;
	while(aux->next != NULL)
		aux = aux->next; //anda até a o fim da pilha
	
	return aux->n;
}

void Pop(Node* P)
{
	Node *aux;
	
	aux = P;
	
	while(aux->next != NULL)
		aux = aux->next; //anda até a o fim da pilha

	aux = NULL;
	free(aux);
}

void Printa_Pilha(Node* node)
{
	if (node != NULL){
		Printa_Pilha(node->next);
		printf("\ninfo: %d", node->n);
	}
	else
		return;
}
