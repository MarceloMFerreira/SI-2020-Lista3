#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct livros{
	char titulo[30],autor[15];
	int ano,prateleira;	
} tlivro;
int qtd=0;
//---------------------------
void addLivro(tlivro t[]){
	printf("\n***** Dados do Livro %d *****\n",qtd+1);
	printf("Titulo:");
	fflush(stdin); gets(t[qtd].titulo);
	printf("Autor:");
	fflush(stdin); gets(t[qtd].autor);
	printf("Ano:");
	scanf("%d",&t[qtd].ano);
	printf("Prateleira:");
	scanf("%d",&t[qtd].prateleira);
	qtd++;
}
//---------------------------
void mostraLivro(tlivro t[]){
	int i;
	for(i=0; i<qtd; i++){
		printf("\n------ Livro %d -----\n",i+1);
		printf("Titulo: %s\n",t[i].titulo);
		printf("Autor: %s\n",t[i].autor);
		printf("Ano: %d\n",t[i].ano);
		printf("Prateleira: %d\n",t[i].prateleira);
	}
}
//---------------------------
void buscaLivro(tlivro t[]){
	char buscaTitulo[30];
	int i,aux,encontrou=0;
	
	printf("Informe o titulo a ser buscado: ");
	fflush(stdin); gets(buscaTitulo);
	for(i=0; i<qtd; i++){	
	if(strcmp(t[i].titulo,buscaTitulo) == 0){
		aux=i;
		encontrou=1;
	} 
	}
	if(encontrou==1){
	printf("\n------ Livro %d ------\n",aux+1);
	printf("Titulo: %s\n",t[aux].titulo);
	printf("Prateleira: %d\n",t[aux].prateleira);
	} else printf("Livro nao encontrado!");
}
//---------------------------
void buscaAno(tlivro t[]){
	int anobusc,i;
	printf("Informe o ano:");
	scanf("%d",&anobusc);
	for(i=0; i<qtd; i++){
		
		if(t[i].ano > anobusc){
		printf("--------------------\n");
		printf("Titulo: %s\n",t[i].titulo);
		printf("Autor: %s\n",t[i].autor);
		printf("Ano: %d\n",t[i].ano);
		printf("Prateleira: %d\n",t[i].prateleira);
		
			
		}
	}	
}
//---------------------------
int menu(){
	int op;
	printf("1- Cadastrar livro\n");
	printf("2- Mostrar livros\n");
	printf("3- Busca livro\n");
	printf("4- Apresentar todos os livros mais novos que o ano a ser informado\n");
	printf("0- Sair\n");
	printf("Informe a opcao desejada:");
	scanf("%d",&op);
	
	return op;
}
//---------------------------
int main(){
	tlivro livros[99];
	int op;
	
	do{
		op = menu();
		switch(op){
			case 1: addLivro(livros);
			break;
			case 0: printf("Saindo...");
			break;
			case 2: mostraLivro(livros);
			break;
			case 3: buscaLivro(livros);
			break;
			case 4: buscaAno(livros);
			break;
			
		}
	getch(); 
	system("cls");	
	}while(op!=0);
}
