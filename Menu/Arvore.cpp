#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct noArv
{  
  int info;
  struct noArv *Esq;
  struct noArv *Dir;
};

//! http://www.facom.ufu.br/~madriana/EBD/dic_arqbin.cpp
void apagar(noArv **arv){
  if (*arv != NULL)
  {
    apagar(&(*arv)->Esq);
    apagar(&(*arv)->Dir);
    free(*arv);
    *arv = NULL;
  } 
  
}
int insereArv(struct noArv ** arv, int elem)
{
  if (*arv == NULL )
  {
    struct noArv * novoNo;
    novoNo = (struct noArv*) malloc(sizeof(struct noArv));
    if (novoNo == NULL)
    {
      return 0;
    }
    else
    {
      novoNo->info = elem;
      novoNo->Esq = NULL;
      novoNo->Dir = NULL;
      *arv = novoNo;
      return 1;
    }
  }
  else
  {
    if ((*arv)->info > elem)
      return insereArv(&(*arv)->Esq, elem);
    else
      return insereArv(&(*arv)->Dir, elem);
  }
}
void imprimeArv(struct noArv * arv)
{
  if (arv!=NULL)
  {
     
     printf("%d ", arv->info);
     imprimeArv(arv->Esq);
     imprimeArv(arv->Dir);
}
}
int buscar(noArv *arv, int elem){
    if(arv == NULL){
      return 404;
    }
    else{
      if(arv->info == elem){
        return arv->info;
      }
      else{
        if(elem < arv->info){
          return buscar(arv->Esq,elem);
        }
        else{
           return buscar(arv->Dir,elem);
        }
      }
    }
}
int cria(int elem){
    struct noArv * novoNo;
    novoNo = (struct noArv*) malloc(sizeof(struct noArv));
    novoNo->info = elem;
    novoNo->Esq = NULL;
    novoNo->Dir = NULL;
}
int alturaArv(struct noArv * arv){
    int esquerda;
    int direita;
    if(arv == NULL){
        return -1;
    }
    else{
         esquerda = alturaArv(arv->Esq);
         direita = alturaArv(arv->Dir);
        if(esquerda > direita){
            return esquerda + 1;
        }
        else{
            return direita + 1;
        }
    }
}
int maiorArvore(noArv *arv) {
    int maior, maiorAtual, esquerda, direita;

    maiorAtual = arv->info;
    maior = maiorAtual; 
    if (arv->Esq != NULL){
        esquerda = maiorArvore(arv->Esq);

        if (esquerda > maior){
            maior = esquerda;
        }
    }
    if (arv->Dir != NULL){
        direita = maiorArvore(arv->Dir);

        if (direita > maior){
            maior = direita;
        }
    }
    return maior;
}
int menorArvore(noArv *arv) {
    int menor, menorAtual, esquerda, direita;

    menorAtual = arv->info;
    menor = menorAtual; 
    if (arv->Esq != NULL){
        esquerda = menorArvore(arv->Esq);

        if (esquerda < menor){
            menor = esquerda;
        }
    }
    if (arv->Dir != NULL){
        direita = menorArvore(arv->Dir);

        if (direita < menor){
            menor = direita;
        }
    }
    return menor;
}
int somarValores(noArv *arv) {
     if (arv == NULL){
               return 0;
     }
     return somarValores(arv->Esq) + somarValores(arv->Dir) + arv->info;
}
int somarFolhas(noArv *arv){
     if(arv == NULL){
       return 0;
     }
     if (arv->Esq == NULL && arv->Dir == NULL){
          return 1+somarFolhas(arv->Esq)+somarFolhas(arv->Dir);
       }
       else{
         return somarFolhas(arv->Esq) + somarFolhas(arv->Dir);
     }
 }
int somarFolhascomfilho(noArv *arv){
     if(arv == NULL){
       return 0;
     }
     if (arv->Esq == NULL || arv->Dir == NULL){
          return 1+somarFolhascomfilho(arv->Esq)+somarFolhascomfilho(arv->Dir);
       }
       else{
         return somarFolhascomfilho(arv->Esq) + somarFolhascomfilho(arv->Dir);
     }
 }
int contarNos( noArv *arv) {
   if(arv == NULL){
      return 0; 
   }
    return (contarNos(arv->Esq) + contarNos(arv->Dir) + 1);
 }
int media(noArv *arv){
  float soma = somarValores(arv);
  int quantidade = contarNos(arv);

  return soma/quantidade;
}
void escreverArquivo(noArv *arv,char *end){

  FILE* arquivo = fopen(end,"a");

    if(arquivo == NULL) {
        printf("Erro ao abrir o lista.txt.\n");
    }
  else{
    if(arv != NULL){
        fprintf(arquivo,"%d ",arv->info);
        fseek(arquivo,0, SEEK_END);
        escreverArquivo(arv->Esq,end);
        escreverArquivo(arv->Dir,end);
        fclose(arquivo);
        if (arv->Esq == NULL || arv->Dir == NULL){
            fclose(arquivo);
        }   
    }    
  }
}
void lerArquivo(noArv *arv,char *end){

int valorLido;

  FILE* arquivo = fopen(end, "a");
    if(arquivo == NULL) {
        printf("Erro ao abrir o lista.txt.\n");
    }
    else{
      if(arv != NULL){ 
            fscanf(arquivo,"%d",&valorLido);
            insereArv(&arv,valorLido);
            lerArquivo(arv->Esq,end);
            lerArquivo(arv->Dir,end);
            fclose(arquivo);
          }
          else{
            fclose(arquivo);
            printf("O arquivo foi lido com secesso\n");
          }
            
        }
}




int main(void)
{
    int teste;
    struct noArv *Arvore;
    Arvore = NULL;
   
    insereArv(&Arvore,50);
    insereArv(&Arvore,50);
    insereArv(&Arvore,510);

    imprimeArv(Arvore);
    printf("(%d)",buscar(Arvore,520));
    return 0;
}