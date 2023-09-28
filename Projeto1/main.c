#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include<conio.h>


#define MAX 50
#define IA 0
#define FA MAX-1

//Colocar data
//Senha
//Mostrar o nome*

int vendas = 0;
float lucro = 0;

struct passagem{
char local[60];
int pas;
float horario;
float preco;
};
void insercao(struct passagem LL[], int *IL, int *FL);
void remocao(struct passagem LL[], int *IL, int *FL);
void consulta(struct passagem LL[], int *IL, int *FL);
void compra(struct passagem LL[], int *IL, int *FL);
void organizar(struct passagem LL[], int *IL, int *FL);
void relatorio();
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int cod_op, IL=-1, FL=-1, senha;
    struct passagem LL[MAX];
    char op;

        do{

        printf("Usuário (U)?\n ou\nFuncionário (F)?\n");
        scanf("%s", &op);
            if(op=='F'){
                printf("Digite a Senha:\n");
                scanf("%d", &senha);
                    if(senha == 1){
                        printf("Bem-Vindo/a funcionário/a!\n");
                        printf("Qual opção deseja?\n");
                        printf("Opção 1 - Inserir Passagem Aérea.\n");
                        printf("Opção 2 - Remover Passagem Aérea.\n");
                        printf("Opção 3 - Consultar Estoque.\n");
                        printf("Opção 4 - Gerar Relatório.\n");
                        printf("Opção 5 - Organizar por Ordem Crescente.\n");
                        printf("Opção 0 - Sair do Programa.\n");
                        printf("Digite a opção desejada:\n");
                        scanf("%d", &cod_op);

                         switch(cod_op){
    case 1:
        insercao(LL, &IL, &FL);
        break;
    case 2:
        remocao(LL, &IL, &FL);
        break;
    case 3:
        consulta(LL, &IL, &FL);
        break;
    case 4:
        relatorio();
        break;
    case 5:
        organizar(LL, &IL, &FL);
        break;
    case 0:
        printf("Volte sempre!");
        break;
    default:
        printf("Opção inválida");
        }
                    }else{
                        printf("Senha incorreta!\n");
                    }
            }else if (op == 'U'){
        printf("Bem-Vindos a *Nome Genérico*, onde voamos como pássaros!\n");
        printf("Opção 1 - Comprar Passagem.\n");
        printf("Opção 0 - Sair do Programa.\n");
        printf("Digite a opção desejada:\n");
        scanf("%d", &cod_op);


        switch(cod_op){
    case 1:
        compra(LL, &IL, &FL);
        break;

    case 0:
        printf("Volte sempre!");
        break;

    default:
        printf("Opção inválida");

        }

        }

        }while(cod_op!=0);

        return 0;
}

void insercao(struct passagem LL[], int *IL, int *FL){
 int x;
    if((*IL==IA) && (*FL==FA))
        printf("Não foi possível adicionar a passagem.");
        else{
            if(*IL==-1){
                *IL=0;
                *FL=0;
            }else if(*IL>IA)
            (*IL)--;
                    else{
                        for(x=*FL;x>=*IL;x--)
                            LL[x+1] = LL[x];
                            (*FL)++;
                    }
                    printf("Digite o Local do Voo\n: ");
                    printf("Utilize (_) como espaço\n");
                    scanf("%s", &LL[*IL].local);
                    printf("Local do Voo: %s \n", LL[x].local);

                    printf("Digite o Número de Passagens: ");
                    scanf("%d", &LL[*IL].pas);
                    printf("Digite o Horário: \n");
                    printf("(Horário de Voo entre 5H até 22H)\n");
                    scanf("%f", &LL[*IL].horario);
                    if((LL[*IL].horario<5 || LL[*IL].horario>22))
                        printf("Não trabalhamos nesse horário.\n");
                        else{
                    printf("Digite o Preço: ");
                    scanf("%f", &LL[*IL].preco);
        }
        return 0;
        }
}
void remocao(struct passagem LL[], int *IL, int *FL){
int x, K;
        for(x=*IL; x<=*FL; x++){
            printf("Local do Voo: %s\n", LL[x].local);
            printf("Número das Passagens: %d\n", LL[x].pas);
            printf("Horário do Voo: %.2f\n", LL[x].horario);
            printf("Preço da Passagem: R$%.2f\n", LL[x].preco);}
    printf("Qual passagem gostaria?\n");
    scanf("%d", &K);

    if ((K<=-1) && (K>*FL-*IL+1))
        printf("Impossível");
        else{
            for(x=*IL+K-1;x<=*FL-1; x++)
                LL[x] = LL[x+1];

                (*FL)--;
             if (*FL==*IL-1) {
            *IL = 0;
            *FL = 0;
            }

}
}
void consulta(struct passagem LL[], int *IL, int *FL){
        int x;
        for(x=*IL; x<=*FL; x++){
            printf("Local do Voo: %s\n", LL[x].local);
            printf("Número das Passagens: %d\n", LL[x].pas);
            printf("Horário do Voo: %.2f\n", LL[x].horario);
            printf("Preço da Passagem: R$%.2f\n", LL[x].preco);
        }


}
void compra(struct passagem LL[], int *IL, int *FL){
 int x, K, quantidade;
 float saldo, total;
        for(x=*IL; x<=*FL; x++){
                //bug
            printf("Local do Voo: %s \n", LL[x].local);
            //puts(LL[x].local);
            printf("Número das Passagens: %d\n", LL[x].pas);
            printf("Horário do Voo: %.2f\n", LL[x].horario);
            printf("Preço da Passagem: R$%.2f\n", LL[x].preco);}
    printf("Qual passagem deseja comprar?\n");
    scanf("%d", &K);
    if ((K<=-1) && (K>*FL-*IL+1))
        printf("Impossível");
    printf("Quantas passagens deseja comprar?\n");
    scanf("%d", &quantidade);
   //total = quantidade * 10;
    total = quantidade * LL[K-1].preco;
    printf("Preço total: %.2f", total);
    printf("Digite seu saldo:\n");
    scanf("%f", &saldo);

    if (quantidade > LL[K-1].pas){
        printf("Impossivel\n");
        return 0;
    } else if (quantidade == LL[K-1].pas){
        for(x=*IL+K-1;x<=*FL-1; x++)
            LL[x] = LL[x+1];
            (*FL)--;
        if (*FL==*IL-1) {
            *IL = 0;
            *FL = 0;
        }
    }
    if(saldo>=total){
        LL[K-1].pas = LL[K-1].pas - quantidade;
        vendas += quantidade;
        lucro += total;
    } else {
        printf("Saldo insuficiente\n");
    }
}


void organizar(struct passagem LL[], int *IL, int *FL){
int flag, x;
struct passagem aux;
    if(LL[x].pas>0){
    flag = 1;
    while(flag){
        flag = 0;
        for(x=0;x<=*FL;x++){
            if(LL[x].pas>LL[x+1].pas){
                aux = LL[x];
                LL[x]=LL[x+1];
                LL[x+1]=aux;
                flag = 1;
            }
        }
    }

}
}

void relatorio(){
    printf("\nNumero de vendas: %d \nLucro: %.2f \n", vendas, lucro);
}


