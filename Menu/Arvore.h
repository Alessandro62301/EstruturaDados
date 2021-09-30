#include <stdio.h>
#include <stdlib.h>


struct noArv{  
  int info;
  struct noArv *Esq;
  struct noArv *Dir;
};

// Definir estrutura ✔
// Criar ✔
// inserir elemento na árvore ✔
// Remover elemento	 ✔
// calcular a altura ✔
// Imprimir infixa ✔
// Imprimir prefixa ✔	
// Imprimir posfixa ✔
// Maior elemento ✔
// Menor elemento	✔
// Busca ✔
// Soma ✔
// Número de folha ✔
// Número de elementos ✔
// Número de nós com 1 filho ✔
// Média dos elementos ✔
// Apagar ✔
// Gravar árvore (arquivo texto) ✔
// Retorna os nós folhas✔

//!CRIAR ARVORE
int cria(int elem){
    struct noArv * novoNo;
    novoNo = (struct noArv*) malloc(sizeof(struct noArv));
    novoNo->info = elem;
    novoNo->Esq = NULL;
    novoNo->Dir = NULL;
}

//!INSERIR NA ARVORE
int insereArv(struct noArv ** arv, int elem){
  if (*arv == NULL ){
    struct noArv * novoNo;
    novoNo = (struct noArv*) malloc(sizeof(struct noArv));
    if (novoNo == NULL){
      return 0;
    }
    else{
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

//!APAGAR ARVORE
void apagar(noArv **arv){
  if (*arv != NULL)
  {
    apagar(&(*arv)->Esq);
    apagar(&(*arv)->Dir);
    free(*arv);
    *arv = NULL;
  } 
  
}
//!BUSCAR
int buscar(noArv *arv, int elem){
    if(arv == NULL){
      return -394;
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
//!ALTURA DA ARVORE
int alturaArv(struct noArv * arv){
    if(arv == NULL){
        return -1;
    }
    else{
        int esquerda = alturaArv(arv->Esq);
        int direita = alturaArv(arv->Dir);
        if(esquerda > direita){
            return esquerda + 1;
        }
        else{
            return direita + 1;
        }
    }
}

//!IMPRIME
void imprimeArv( noArv * arv){
  if (arv!=NULL){
     imprimeArv(arv->Esq);
     printf("-----%d-----", arv->info);
     imprimeArv(arv->Dir);
  }
}

//!IMPREME PREFIXA
void prefixa(noArv *noArv){
    if(noArv != NULL){
        printf("-----%d-----", noArv->info);
        prefixa(noArv->Esq);
        prefixa(noArv->Dir);
  }
}

//!IMPREME POSFIX
void posFixa(noArv *noArv){
    if(noArv != NULL){
      posFixa(noArv->Esq);
      posFixa(noArv->Dir);
      printf("-----%d-----",noArv->info);
  }
}

//!MAIOR ELEMENTO DA ARVORE
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

//!MENOR ELEMENTO DA ARVORE
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

//!SOMAR TODOS OS ELEMENTOS DA ARVORE
int somarValores(noArv *arv) {
     if (arv == NULL){
               return 0;
     }
     return somarValores(arv->Esq) + somarValores(arv->Dir) + arv->info;
}

//!SOMAR QUANTIDADE DE FOLHAS DA ARVORE
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

//!SOMAR QUANTIDADE DE FOLHAS DA ARVORE COM 1 FILHO
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

//!SOMAR QUANTIDADE DE NOS Elementos
 int contarNos( noArv *arv) {
   if(arv == NULL){
      return 0; 
   }
    return (contarNos(arv->Esq) + contarNos(arv->Dir) + 1);
}

//!MEDIA DOS ELEMENTOS DA ARVORE 
int media(noArv *arv){
  float soma = somarValores(arv);
  int quantidade = contarNos(arv);

  return soma/quantidade;
}

//!ESCREVER A ARVORE NO ARQUIVO
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
//!RETORNAR FOLHAS
int retornarFolhas(noArv *arv){
     if(arv == NULL){
       return 0;
     }
     if (arv->Esq == NULL && arv->Dir == NULL){
        return 0;
       }
       else{
        printf("end == %d\n",&arv);
        retornarFolhas(arv->Esq);
        retornarFolhas(arv->Dir);
     }
 }
//!REMOVER ELEMENTO DA ARVORE
noArv*retirar(noArv* arv, int elem)
{
 if (arv == NULL)
    return NULL;
 else if (arv->info > elem)
    arv->Esq = retirar(arv->Esq, elem);
 else if (arv->info < elem)
    arv->Dir = retirar(arv->Dir, elem);
 else {
    if (arv->Esq == NULL && arv->Dir == NULL){
       free(arv);
       arv = NULL;
    }
    else if (arv->Esq == NULL){
       noArv* aux1 = arv;
      arv = arv->Dir;
       free (aux1);
    }
    else if (arv->Dir == NULL){
       noArv* aux1 = arv;
       arv = arv->Esq;
       free (aux1);
    }
    else {
       noArv* aux2 = arv->Esq;
       while (aux2->Dir != NULL){
          aux2 = aux2->Dir;
       }
       arv->info = aux2->info;
       aux2->info = elem;
       arv->Esq = retirar(arv->Esq,elem);
    }
 }
return arv;
}