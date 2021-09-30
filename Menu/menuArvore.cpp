#include<stdio.h>
#include<stdlib.h>
#include"Arvore.h"

void menuArvore(noArv*arv);

// Definir estrutura ✔
// Criar ✔
// inserir elemento na árvore ✔
// Remover elemento	✔
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
// Número de nós com 1 filho
// Média dos elementos ✔
// Apagar ✔
// Gravar árvore (arquivo texto) ✔
// Retorna os nós folhas✔


void menuArvore(noArv*arv){
    int optionLista,aux,aux2;
    char end[50];
    while (1)
    {
        printf("\n<1> Inserir:\n ");
        printf("<2> Remover:\n ");
        printf("<3> Imprimir:\n ");
        printf("<4> Imprimir prefixa:\n ");
        printf("<5> Imprimir posfixa:\n ");
        printf("<6> buscar:\n");
        printf("<7> calcular a altura:\n");
        printf("<8> Maior elemento \n");
        printf("<9> Menor elemento	\n");
        printf("<10> Somar:\n");
        printf("<11> Numero de folha:\n");
        printf("<12> Numero de elementos:\n");
        printf("<13> Numero de nós com 1 filho:\n");
        printf("<14> Média dos elementos:\n");
        printf("<15> Apagar Arvore:\n");
        printf("<16> Gravar árvore:\n");
        printf("<17> Carregar árvore :\n");
        printf("<18> Retorna os nós folhas:\n");
        printf("<19> Voltar:\n");
        scanf("%d",&optionLista);


        switch (optionLista)
        {
        case 1:
        printf("Insira o Valor:\n");
        scanf("%d",&aux);
        insereArv(&arv,aux);
            break;
        case 2:
            printf("Insira o valor para Remover:");
            scanf("%d",&aux);
            retirar(arv,aux);
            break;
        case 3:
            imprimeArv(arv);
            break;
        case 4:
            prefixa(arv);
            break;
        case 5:
            posFixa(arv);
            break;
        case 6:
            printf("Insira o valor para buscar:");
            scanf("%d",&aux);
            aux2 = buscar(arv,aux);
            if(aux2 == -394)
                printf("Valor nao existe na Arvore!");
            else
            printf("-----%d-----",aux);
            break;
        case 7:
            printf("Altura == %d",alturaArv(arv));
            break;
        case 8:
            printf("-----%d-----", maiorArvore(arv));
            break;
        case 9:
             printf("-----%d-----", menorArvore(arv));
            break;   
        case 10:
            printf("-----%d-----", somarValores(arv));
            break;
        case 11:
            printf("-----%d-----", somarFolhas(arv));
            break;
        case 12:
            printf("-----%d-----", contarNos(arv));
            break;
        case 13:
           printf("-----%d-----", somarFolhascomfilho(arv));
            break;
        case 14:
           printf("-----%d-----", media(arv));
            break;
        case 15:
           apagar(&arv);
            break;
        case 16:
            printf("insira o endereco:\n");
            scanf("%s",end);
            escreverArquivo(arv,end);
            break;
        case 17:
            printf("insira o endereco:\n");
            scanf("%s",end);
            // ler(arv,end);
            break;
        case 18:
            retornarFolhas(arv);
            break;
        case 19:
            menuArvore(arv);
            break;
        default:
             printf("Opcao invalida!!!\n");
            break;
        }
            

    }
}

int main(){

    struct noArv *Arvore;
    Arvore = NULL;
   
    menuArvore(Arvore);

    
return 0;
}
