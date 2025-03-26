#include <stdio.h>
#include <string.h>
#define tam 100

typedef struct {
char nome[30];
float preco;
int quantidade;
} Produto;

void cadastrarProduto(Produto *produto){
    printf("Digite o nome do produto: ");
    fflush(stdin);
    getchar();
    fgets(produto->nome, sizeof(produto->nome), stdin);
    if (produto->nome[strlen(produto->nome) - 1] == '\n') {
        produto->nome[strlen(produto->nome) - 1] = '\0';
    }
    
    printf("Digite o preco desse produto: ");
    scanf("%f", &produto->preco);
    printf("Digite quantos produtos tem: ");
    scanf("%i", &produto->quantidade);
  
}

void listarProdutos(Produto produtos[], int quantidade){
    for(int i =0; i<quantidade; i++){
        printf("\tO nome do produto %i e %s\n", i+1, produtos[i].nome);
        printf("\tO preco do produto %i e %.2f\n", i+1, produtos[i].preco);
        printf("\tquantidade do produto %i e %i\n", i+1, produtos[i].quantidade);
        
    }
    
}
void atualizarPreco(Produto *produto){
   int indice;
   float novoPreco;
   
   printf("Qual produto voce quer alterar?");
   scanf("%i", &indice);
   if (indice < 1) {
    printf("Produto não encontrado.\n");
    
   }else{
   printf("Digite o novo preço para o produto %i: ", indice);
   scanf("%f", &novoPreco); 
   produto[indice - 1].preco = novoPreco;
   }
   
    
}

int main() {
    int opcao;
    int falha = 0;
    Produto produtos[tam];
    int totaldprodutos = 0;
    

    do {
        printf("\t1 - cadastrar um produto");
        printf("\t2 - listar produtos");
        printf("\t3 - modificar o preço de um produto");
        printf("\t4 - Sair\n");
        printf("\tEscolha uma opção: ");
        scanf("%d", &opcao);

        
        switch(opcao) {
            case 1:
                printf("Produto %i\n", totaldprodutos+1);
                cadastrarProduto(&produtos[totaldprodutos]);
                totaldprodutos = totaldprodutos+1;
                falha = 1;
                break;
            case 2:
                if(falha == 0){
                    printf("\tCadastre um produto primeiro...\n");
                } else {
                falha = 2;
                listarProdutos(produtos, totaldprodutos);
                }
                break;
            case 3:
                if(falha == 0){
                    printf("\tCadastre um produto primeiro...\n");
                } else {
               for(int i=0; i<totaldprodutos; i++){
              printf("Produto %i: %s\n", i+1, produtos[i].nome);
              printf("Preco : %.2f\n", produtos[i].preco);
             
                }
                printf("\tde 1 a %i\n", totaldprodutos);
                atualizarPreco(produtos);}
                break;
            case 4:
                printf("\tPrograma fechado!!\n");
                break;
            default:
                printf("\ta Opçao e invalida! Tente novamente.\n");
        }
 
    } while(opcao != 4); 
    return 0;
}


 
 


