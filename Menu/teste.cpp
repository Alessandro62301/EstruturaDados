
/*O gerente de uma loja de carros decide premiar seus funcionários e te chama para bolar um sistema.

A cada mês, as vendas totais de um vendedor serão computadas. Se o total de vendas for superior a R$ 500.000, ele receberá uma medalha de ouro. Se suas vendas estiverem entre R$ 250.000 e R$ 499.999, então ele receberá uma medalha de prata.

Além disso, quando um vendedor chegar a R$ 200.000 em vendas totais, ele passa a receber uma comissão adicional de 1%. Esta comissão só é adicionada se a vend
Esta comissão só é adicionada se a venda passar de R$100.000 (inclusive a venda que fez ele bater 200.000);

Ou seja, se o vendedor fez uma venda de 200.000 e depois ele vender mais R$ 150.000, ele teve como total 350.000, ganha medalha de prata e ganhará R$ 3.500 em comissão.

Agora, se o vendedor fez uma venda de 100.000, depois outra de 100.000 e depois ele vender mais R$ 150.000, ele teve como total 350.000, ganha medalha de prata e ganhará R$ 1.500 em comissão, pois a segunda venda não ultr
ultrapassou 100.000 e não gerou comissão.
📝 Exercício
Escreva um programa em que o usuário possa continuar inserindo as vendas feitas e pergunta se quer continuar inserindo. O usuário digita o caractere n para parar de inserir valores. Quando isso acontecer, pare de perguntar ao usuário por entrada e faça o seguinte:

Calcule e mostre as vendas totais feitas
Determine e mostre se o vendedor ganhou alguma medalha
Determinar e mostrar quanto de comissão que o vendedor ganhou
Enviar mensagem para todos

11:34
*/

#include <stdio.h>

int main() {
   //Lembre de inicializar variáveis acumuladoras!!!
   float vendasTotais=0,venda=0,comissao=0;
   char op;

   do{
     printf("Insira o valor da venda:");
     scanf("%f", &venda);

     vendasTotais += venda;

     if(venda > 100000 && vendasTotais > 200000){
     comissao += venda/100;
     }
     printf("Quer continuar?");
     scanf("%s", &op);
   }
   while (op != 'n');

  
    
         printf("Vendas totais: %.2f\n",vendasTotais);

     if(vendasTotais > 500000)
         printf("Ganhou medalha de ouro!\n");
     if(vendasTotais > 250000 && vendasTotais < 499999)
         printf("Ganhou medalha de prata!\n");
    
         printf("Ganhou %.2f reais de comissão",comissao);
        
// int x,total;
//         printf("insira um valor :");
//         scanf("%d",&x);

     

//         do
//         {
//             printf("insira um valor :");
//             scanf("%d",&x);
//             total  = total +x;

//         } while (x > 0);
//         printf("O total e : %d",total);
        
  int num,soma =0;
printf("Insira um valor:");
scanf("%d",&num);

for (int i = 0 ; i < num ; i++)
{
  soma += i;
  i++;
}
printf("A soma dos pares e %d",soma);

  return 0;
}



//float x ;
// float calculo,resultado;
// printf("Inserir um valor: ");
// scanf("%f",&x);

// for(int i = 1 ; i < 20 ; i++){

// calculo = 1/(x+i);
// resultado +=calculo;
// }
// printf("%.3f",resultado);

