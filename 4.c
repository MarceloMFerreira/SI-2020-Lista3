#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct eletros{
	char nome[99];
	float potencia,tempo;
	
}teletro;
int qtd=0;
//---------------------------

void addEletro (teletro e[]){
	printf("**** Eletrodomestico %d ****\n",qtd+1);
	printf("Nome:");
	fflush(stdin); gets(e[qtd].nome);
	printf("Potencia:");
	scanf("%f",&e[qtd].potencia);
	printf("Tempo medio ativo por dia:");
	scanf("%f",&e[qtd].tempo);
	qtd++;
	
}
//---------------------------
void mostraCad (teletro e[]){
	int i;
	for(i=0; i<qtd; i++){
		printf("\n**** Eletrodomestico %d ****\n",i+1);
		printf("Nome: %s\n",e[i].nome);
		printf("Potencia: %.0f\n",e[i].potencia);
		printf("Tempo medio ativo por dia: %.0f\n",e[i].tempo);
		
	}
}
//---------------------------
void salvaDados (teletro e[]){
	FILE *arq;
	arq = fopen("eltro.dat","wb"); 
	fwrite(&e[0],sizeof(teletro),qtd,arq); 
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//---------------------------
void carregaDados (teletro e[]){
	FILE *arq;
	arq = fopen("eltro.dat","rb"); 
	if(arq==NULL)
	  printf("Arquivo nao encontrado!\n");
	else{
	 while(    fread(&e[qtd],sizeof(teletro),1,arq) >0     )
	     qtd++;  
	 printf("Dados carregados com sucesso!\n");
	}
	fclose(arq);
}
//---------------------------
void buscaNome(teletro e[]){
	char nomeB[99];
	int i,encontrou=0;
	printf("Informe o nome a ser buscado: ");
	fflush(stdin); gets(nomeB);
	for(i=0; i<qtd; i++){
		if(strcmp(e[i].nome,nomeB) == 0){
		printf("\n**** Eletrodomestico %d ****\n",i+1);
		printf("Nome: %s\n",e[i].nome);
		printf("Potencia: %.1f\n",e[i].potencia);
		printf("Tempo medio ativo por dia: %.0f\n",e[i].tempo);
		encontrou=1;	
		}
	}
	if(encontrou==0){
		printf("Cadastro nao encontrado!\n");
	}
}
//---------------------------
void buscaVal (teletro e[]){
	float val;
	int i,encontrou=0;
	printf("Informa o valor a ser buscado: ");
	scanf("%f",&val);
	printf("\nEletrodomesticos que gastam mais que %.2f\n",val);
	for(i=0; i<qtd; i++){
		if(val<e[i].potencia*e[i].tempo){
		printf("\n**** Eletrodomestico %d ****\n",i+1);
		printf("Nome: %s\n",e[i].nome);
		printf("Potencia: %.1f\n",e[i].potencia);
		printf("Tempo medio ativo por dia: %.0f\n",e[i].tempo);
		encontrou=1;	
		}
	}
	if(encontrou==0){
		printf("Cadastro nao encontrado!\n");
	}
	
}
//---------------------------
void buscaConsumo (teletro e[]){
	int i;
	float consumoMes=0,consumoPot;
	for(i=0; i<qtd; i++){
		consumoMes= consumoMes + e[i].potencia*e[i].tempo;
		consumoPot = consumoPot + e[i].potencia;
	}
	printf("Consumo diario em reais: %.2f\n",consumoMes);
	printf("Consumo diario em potencia: %0.f\n",consumoPot);
	printf("Consumo mensal em reais: %.2f\n",consumoMes*30);
	printf("Consumo mensal em potencia: %0.f\n",consumoPot*30);
	
}
//---------------------------
int menu(){
	int op;
	printf("1- Cadastrar eletrodomestico\n");
	printf("2- Mostrar cadastros\n");
	printf("3- Salvar dados\n");
	printf("4- Carregar dados\n");
	printf("5- Buscar pelo nome\n");
	printf("6- Buscar eletrodomesticos que gastam mais que um valor X\n");
	printf("7- Calcular consumo diario e mensal\n");
	printf("0- Sair\n");
	printf("Informe a opcao desejada:");
	scanf("%d",&op);
	
	return op;
}
//---------------------------
int main(){
	teletro eletros[99];
	int op;
	
	do{
		op = menu();
		switch(op){
			case 1: addEletro(eletros);
			break;
			case 2: mostraCad(eletros);
			break;
			case 3: salvaDados(eletros);
			break;
			case 4: carregaDados(eletros);
			break;
			case 5: buscaNome(eletros);
			break;
			case 6: buscaVal(eletros);
			break;
			case 7: buscaConsumo(eletros);
			break;
			case 0: printf("Saindo...");
			break;
					
		}
		
	getch(); 
	system("cls");	
	}while(op!=0);
		
}
