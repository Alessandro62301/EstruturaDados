#include<stdio.h>
#include<stdlib.h>
typedef struct lista{	
		int valor;
		struct lista *proximo;
	}no;


lista *empilha(lista **l,int valor){
lista *ini_lista = *l;
int cont = tamanho(*l);
int pos = 0;

  if(pos>=0 && pos <=cont){
  


      lista *aux = (lista*)malloc(sizeof(lista*));
      aux->valor = valor;
      ini_lista->proximo = NULL;

      if(ini_lista == NULL){
        aux->proximo = *l;
        *l = aux;
      }
  
    
    else{

        lista *aux = ini_lista;
        for(int i =0 ; i < cont -1 ; i++){
        aux = aux->proximo;
        }
        aux->proximo = *l;
        cont++;
    }
  }

  void empilha1(lista **l,int valor){
lista *ini_lista = *l;
int cont = tamanho(*l);
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


lista *teste(lista**l,int valor,int pos){
      int i = 0;
      pos = tamanho(*l);
      lista *ini_lista = *l;
      lista *aux = (lista*)malloc(sizeof(lista*));
      aux->valor = valor;

      if(pos == 1 && ini_lista->valor == 0){
        aux->proximo = *l;
        *l = aux;
      }

      lista *cont = *l;
      while (cont->proximo!= NULL &&  i != pos - 1)
      {
        cont = cont->proximo;
        i++;
      }
      aux->proximo = cont->proximo;
      cont->proximo = aux;
      return aux;
      
}