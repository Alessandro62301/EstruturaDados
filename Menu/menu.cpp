#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

void menu(lista*l);
void menuLista(lista*l);
// Insere     ✅       com posição
// Remove     ✅um elemento
// Tamanho   ✅
// Busca elemento ✅
// Get(lista, i) ✅
// Cheia ✅
// Ordena ✅
// Imprime ✅
// Escreve em arquivo ✅
// Ler arquivo
void menuPilha(lista*l);
// Empilha  ✅
// Desempilha ✅
// Mostra elemento do topo ✅
// Tamanho  ✅
// Imprime ✅
// Escreve em arquivo ✅
// Ler arquivo
void menuFila(lista*l);
// Enfileirar  ✅
// Desenfileirar  ✅
// Mostra elemento inicio  ✅
// Tamanho  ✅
// Imprime  ✅
// Escreve em arquivo ✅
// Ler arquivo

void menuLista(lista *l){
    int optionLista,aux,aux2;
    char end[50];
    while (1)
    {
        printf("<1> Inserir:\n ");
        printf("<2> Remover:\n ");
        printf("<3> Imprimir:\n ");
        printf("<4> buscar:\n");
        printf("<5> Get:\n");
        printf("<6> Ordena:\n");
        printf("<7> Cheia:\n");
        printf("<8> Escrever no arquivo:\n");
        printf("<9> Ler Arquivo\n");
        printf("<10> Tamanho\n");
        printf("<11> Voltar:\n");
        scanf("%d",&optionLista);


        switch (optionLista)
        {
        case 1:
        printf("Insira o Valor:\n");
        scanf("%d",&aux);
        printf("Insira a posicao:\n");
        scanf("%d",&aux2);
        addlista(&l,aux,aux2);
            break;
        case 2:
            printf("Insira a valor:\n");
            scanf("%d",&aux);
            retira(&l,aux);
            break;
        case 3:
            imprimir(l);
            break;
        case 4:
            printf("Insira o valor:\n");
            scanf("%d",&aux);
            buscar(l,aux);
            break;
        case 5:
            printf("Insira a Posicao:\n");
            scanf("%d",&aux);
            get(l,aux);
            break;
        case 6:
            printf("A lista foi ordenada");
            ordenar(l);
            break;
        case 7:
            aux = cheia();
            if(aux == 1){
                printf("Lista Cheia");
            }
            else    
                printf("Lista Com espaco disponivel");
            break;
        case 8:
            printf("Insira o endereco:\n");
            scanf("%s",end);
            escreverArquivo(l,end);
            break;
        case 9:
            printf("Insira o endereco:\n");
            scanf("%s",end);
            lerArquivo(l,end);
            break;   
        case 10:
            aux = tamanho(l);
            printf("O tamnho da lista == %d",aux);
            break;
        case 11:
            menu(l);
            break;
        default:
            printf("Opcao invalida!!!\n");
            break;
        }
            

    }
}

void menuPilha(lista *l){
     int optionLista,aux,aux2;
    char end[50];
    while (1)
    {
        printf("<1> Empilhar:\n ");
        printf("<2> Desempilhar:\n ");
        printf("<3> Mostrar Topo:\n ");
        printf("<4> tamahno:\n");
        printf("<5> imprimir:\n");
        printf("<6> Escrever no arquivo:\n");
        printf("<7> Ler Arquivo:\n");
        printf("<8> Voltar\n");
        scanf("%d",&optionLista);


        switch (optionLista)
        {
        case 1:
        printf("Insira o Valor:\n");
        scanf("%d",&aux);
        empilha(&l,aux);
            break;
        case 2:
            printf("Elemento do topo foi removido:\n");
            desempilha(&l);
            break;
        case 3:
            aux = topo(l);
            printf("O elemento do topo == %d\n",aux);
            break;
        case 4:
            aux = tamanho(l);
            printf("O tamanho da lista  == %d\n",aux);
            break;
        case 5:
            imprimir(l);
            break;
        case 6:
            printf("insira o endereco\n");
            scanf("%s",end);
            escreverArquivoPilha(l,end);
            break;
        case 7:
            printf("insira o endereco\n");
            scanf("%s",end);
            lerArquivoPilha(l,end);
            break;
        case 8:
            menu(l);
            break;
        default :
            printf("Opcao invalida!!!\n");
        }
            

    }
}
void menuFila(lista *l){
    int optionLista,aux,aux2;
    char end[50];
    while (1)
    {
        printf("<1> Emfileirar:\n ");
        printf("<2> Desenfileirar:\n ");
        printf("<3> Mostrar Inicio:\n ");
        printf("<4> Tamanho:\n");
        printf("<5> Imprime:\n");
        printf("<6> Escrever no arquivo:\n");
        printf("<7> Ler Arquivo\n");
        printf("<8> Voltar:\n");
        scanf("%d",&optionLista);


        switch (optionLista)
        {
        case 1:
            printf("Insira o Valor:\n");
            scanf("%d",&aux);
            enfileirar(l,aux);
            break;
        case 2:
            printf("O elemento foi removido");
            desenfileira(&l);
            break;
        case 3:
            aux = inicio(l);
            printf("O elemento do inicio == %d",aux);
            break;
        case 4:
            aux = tamanho(l);
            printf("O tamanho da fila == %d",aux);

            break;
        case 5:
            imprimir(l);
            break;
        
        case 6:
            printf("Insira o endereco:\n");
            scanf("%s",end);
            escreverArquivoFila(l,end);
            break;
        case 7:
            printf("Insira o endereco:\n");
            scanf("%s",end);
            lerArquivoFila(l,end);
            break;
        case 8:
            menu(l);
        default:
            printf("Opcao invalida!!!\n");
            break;
        }
            

    }
}


void menu(lista *l){
    int options;
   
        printf("<1> Lista\n ");
        printf("<2> Pilha\n ");
        printf("<3> Fila\n ");
        printf("<4> Sair\n");
        scanf("%d",&options);


        switch (options)
        {
        case 1:
        menuLista(l);
            break;
        case 2:
        menuPilha(l);
            break;
        case 3:
        menuFila(l);
            break;
        case 4:
        exit(1);
            break;
        }
}
int main(){
	int resp;
	lista * ini_lista;
	lista * proximo_lista;
	
	ini_lista = (lista*)malloc(sizeof(lista*));
	proximo_lista = ini_lista;


	proximo_lista->proximo = NULL;
	proximo_lista = ini_lista;

    menu(ini_lista);

    
return 0;
}
