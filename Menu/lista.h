/*Lista.h

criar um menu de opcao para cada funcao ;
inserir , criar ou remover { 
  lista ,fila,pilha{
    posicao, valor
  }
  ler uma lista de um aquivo
  escrever a lista de um arquivo 
}

Insere     ✅       com posição
Remove     ✅um elemento
Tamanho   ✅
Busca elemento ✅
Get(lista, i) ✅
Cheia ✅
Ordena ✅
Imprime ✅
Escreve em arquivo ✅


Pilha insere e remove no final

Empilha  ✅
Desempilha ✅
Mostra elemento do topo ✅
Tamanho  ✅
Imprime ✅

Fila insere no final e remove no comeco 

Enfileirar  ✅
Desenfileirar  ✅
Mostra elemento inicio  ✅
Tamanho  ✅
Imprime  ✅
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct lista{	
		int valor;
		struct lista *proximo;
	}no;

lista *teste;
int tam;
void empilha(lista *l,int valor);
void addlista(lista *l ,int valor,int pos);
void desenfileira( lista **l);

// RETORNA O TOTAL DE ELEMENTOS NA LISTA
int tamanho(lista *l){
    int cont = 0;
    while (l->proximo != NULL)
    {
    l = l->proximo;
    cont++;
    }
return cont + 1;
}

//RECEBE A POSICAO E RETORNA O VALOR
int buscar(lista *l,int elem){
    int cont = 0;
    while (l != NULL)
    {
        if(l->valor == elem){
            return cont +1;
            }
        l = l->proximo;
        cont++;
    }
return -1;
}

//RECEBER O VALOR DO ELEMENTO NA POSICAO ESCOLHIDA
int get(lista *l,int pos){
    

  int cont =0;
  while(l!=NULL && cont < pos)
  {
    l= l->proximo;
    cont++;
  }
  return l->valor;
}

//ESCREVER A LISTA EM UM ARQUIVO
void escreverArquivo(lista *l,char *end){

int cont = tamanho(l);

  FILE* arquivo = fopen(end,"w");
    if(arquivo == NULL) {
        printf("Erro ao abrir o lista.txt.\n");
        //return 1;
    }
  else{

  for(int i = 0 ; i < cont ; i++){
    fprintf(arquivo,"%d:%d\n",i,l->valor);
    l = l->proximo;
    }
        printf("O arquivo foi escrito com secesso\n");

  }

  
    
    fclose(arquivo);
    //return 0;
}

//LE UM ARQUIVO E RETORNA A LISTA

void lerArquivo(lista *l,char *end){
  int cont = 0,i;
  int valorLido;
  int result;

  FILE* arquivo = fopen(end, "r");
    if(arquivo == NULL) {
        printf("Erro ao abrir o lista.txt.\n");
    }

  else{

  
  while( (fscanf(arquivo,"%d:%d", &i, &valorLido))!=EOF ){
    printf("pos : %d  valor : %d \n",i,valorLido);
      empilha(l,valorLido);
      }
  
}
  
      fclose(arquivo);
      printf("O arquivo foi lido com secesso\n");

}
//IMPRIMIR A LISTA NO TERMINAL
int imprimir(lista *l){

  while(l != NULL){
         printf("valor : %d \n",l->valor);
          l = l->proximo;
     }
     return 0;
}

//RETIRA UM ELEMENTO DA LISTA
int retira(lista **l, int pos)
{
  int cont = 0;
  lista * apaga;
  if ((*l)->valor == pos)
  {
    apaga = *l;
    *l = (*l)->proximo;
    free(apaga);
    cont++;
  }
  else
  {
    lista * aux = *l;
    lista * ant = *l;
    while (aux != NULL)
    {
      if ((aux)->valor == pos)
      {
        apaga = aux;
        ant->proximo = aux->proximo;
        free(apaga);
        cont++;
      }
      ant = aux;
      aux = aux->proximo;
    }
  }
  return cont;
}

//ADICIONA UM ELEMENTO NA LISTA
void addlista(lista *l ,int valor,int pos){
lista *ini_lista = l;
int cont = tamanho(l);

  if(pos>=0 && pos <=cont){
    lista *l = (lista*)malloc(sizeof(lista*));
    l->valor = valor;
    l->proximo = NULL;

      if(pos == 0){
            lista *aux = (lista*)malloc(sizeof(lista*));
            aux->valor = valor;
            aux->proximo = l;

            l = aux;
        }
                 
      else if(pos == cont){//fim
        lista *aux = ini_lista;
        for(int i =0 ; i < tam -1 ; i++){
          aux = aux->proximo;
        }
      aux->proximo = l;
      }
      else{
          lista *aux = ini_lista;
          for(int i =0 ; i < pos -1 ; i++){
          aux = aux->proximo;
        }
        l->proximo = aux->proximo;
        aux->proximo = l;
      }
    }
 
  else
    printf("posicao invalida");

}

//ORDENA A LISTA
void ordenar(lista *l) {

    lista *aux = l;
    lista *t;
    int c;


    while (aux != NULL) {
        t = aux->proximo;
        while (t != NULL) {
            if (aux->valor > t->valor) {
                c = aux->valor;
                aux->valor = t->valor;
                t->valor = c;
            }
            t = t->proximo;
        }
        aux = aux->proximo;
    }

}

//VERIFICA SE TEM ESPACO PARA ALOCACAO
int cheia(){
  teste = (lista *)malloc(sizeof(lista *));
  if(teste == NULL){
    return 1;
  }

  return 0;
}

// FUNCAO PARA PILHA






//ADICIONAR NO FINAL DA LISTA
void empilha(lista *l,int valor){
lista *ini_lista = l;
int cont = tamanho(l);
int pos = 0;

  if(pos>=0 && pos <=cont){


        lista *l = (lista*)malloc(sizeof(lista*));
        l->valor = valor;
        l->proximo = NULL;

        lista *aux = ini_lista;
        for(int i =0 ; i < cont -1 ; i++){
        aux = aux->proximo;
        }
        aux->proximo = l;
        cont++;

   
      
  }

}

//REMOVER NO FINAL DA LISTA
void desempilha(lista **l){


  int cont = tamanho(*l);
  int pos = 0;
  lista * apaga = *l;

    lista * aux = *l;
    lista * ant = *l;
    while (aux != NULL)
    {
      if (pos == cont -1)
      {
        ant->proximo = aux->proximo;
        free(apaga);
        cont++;
      }
      ant = aux;
      aux = aux->proximo;
      pos = pos+1;
    }
  }
//RETONA O ELEMENTO DO TOPO
int topo(lista *l){



  int cont = tamanho(l);
  int pos = 1;
  lista * apaga;

    lista * aux = l;
    lista * ant = l;
    while (aux != NULL)
    {
      if (pos == cont)
      {
        //printf("O elemento : %d esta no topo.\n",aux->valor);
        return aux->valor;
      }
      ant = aux;
      aux = aux->proximo;
      pos = pos+1;
    }
    return 0;
  }

//RETORNA O TAMANHO DA LISTA
int tamanhoPilha(lista *l){
    int cont = 0;
    while (l->proximo != NULL)
    {
    l = l->proximo;
    cont++;
    }
return cont + 1;
}
  
//IMPRIME A PILHA
void imprimirPilha(lista *l){

  while(l != NULL){
         printf("valor : %d \n",l->valor);
          l = l->proximo;
     }
}

void escreverArquivoPilha(lista *l,char *end){

int cont = tamanho(l);

  FILE* arquivo = fopen(end, "w");
    if(arquivo == NULL) {
        printf("Erro ao abrir o lista.txt.\n");
        //return 1;
    }
  else{

  for(int i = 0 ; i < cont ; i++){
    fprintf(arquivo,"%d:%d\n",i,l->valor);
    l = l->proximo;
    }
        printf("O arquivo foi escrito com secesso\n");

  }

  
    
    fclose(arquivo);
    //return 0;
}

void lerArquivoPilha(lista *l,char *end){
  int cont = 0,i;
  int valorLido;
  int result;

  FILE* arquivo = fopen(end, "r");
    if(arquivo == NULL) {
        printf("Erro ao abrir o lista.txt.\n");
    }

  else{

  
  while( (fscanf(arquivo,"%d",&valorLido))!=EOF ){
      empilha(l,valorLido);
      }
  
}
  
      fclose(arquivo);
      printf("O arquivo foi lido com secesso\n");

}

// FUNCAO PARA FILA





void enfileirar(lista*l,int valor){
lista *ini_lista = l;
int cont = tamanho(l);
int pos = 0;

  if(pos>=0 && pos <=cont){


        lista *l = (lista*)malloc(sizeof(lista*));
        l->valor = valor;
        l->proximo = NULL;

        lista *aux = ini_lista;
        for(int i =0 ; i < cont -1 ; i++){
        aux = aux->proximo;
        }
        aux->proximo = l;
        cont++;

   
      
  }

}

void desenfileira( lista **l) {
  lista *aux = *l;            
   if (aux == NULL) 
   return;   

   *l = aux->proximo;                 
   free (aux);                          
}

int inicio(lista *l){



  int cont = tamanho(l);
  int pos = 1;
  lista*aux = l;

      if (aux == NULL) 
      return aux->valor;


      
    return 0;
  }

int tamanhoFila(lista *l){
    int cont = 0;
    while (l->proximo != NULL)
    {
    l = l->proximo;
    cont++;
    }
return cont + 1;
}

void imprimirFila(lista *l){

  while(l != NULL){
         printf("valor : %d \n",l->valor);
          l = l->proximo;
     }
}

void escreverArquivoFila(lista *l,char *end){

int cont = tamanho(l);

  FILE* arquivo = fopen(end, "w");
    if(arquivo == NULL) {
        printf("Erro ao abrir o lista.txt.\n");
        //return 1;
    }
  else{

  for(int i = 0 ; i < cont ; i++){
    fprintf(arquivo,"%d:%d\n",i,l->valor);
    l = l->proximo;
    }
        printf("O arquivo foi escrito com secesso\n");

  }

  
    
    fclose(arquivo);
    //return 0;
}

void lerArquivoFila(lista *l,char *end){
  int cont = 0,i;
  int valorLido;
  int result;

  FILE* arquivo = fopen(end, "r");
    if(arquivo == NULL) {
        printf("Erro ao abrir o lista.txt.\n");
    }

  else{

  
  while( (fscanf(arquivo,"%d:%d", &i, &valorLido))!=EOF ){
    printf("pos : %d  valor : %d \n",i,valorLido);
      enfileirar(l,valorLido);
      }
  
}
  
      fclose(arquivo);
      printf("O arquivo foi lido com secesso\n");

}