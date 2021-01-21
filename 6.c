#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int mes,ano;
}tdata;
typedef struct{
	int cod,leite,alim,mes;
	char abate[1];
	tdata data;
}tgado;
int qtd=0;
//---------------------------
void addGado(tgado g[]){
	printf("Codigo: ");
	scanf("%d",&g[qtd].cod);
	printf("Litros de leite produzido p/ semana: ");
	scanf("%d",&g[qtd].leite);
	printf("Qtd de alimentos ingeridos p/ semana (Kg): ");
	scanf("%d",&g[qtd].alim);
	printf("Data de nascimento MM AA: ");
	scanf("%d%d",&g[qtd].data.mes,&g[qtd].data.ano);
	if(g[qtd].data.ano<2016 || g[qtd].leite < 40){
		strcpy(g[qtd].abate,"S");
	} else{
		strcpy(g[qtd].abate,"N");
	}
	qtd++;
	
}
//---------------------------
void salvaDados (tgado g[]){
	FILE *arq;
	arq = fopen("gados.dat","wb"); 
	fwrite(&g[0],sizeof(tgado),qtd,arq); 
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//---------------------------
void carregaDados (tgado g[]){
	FILE *arq;
	arq = fopen("gados.dat","rb"); 
	if(arq==NULL)
	  printf("Arquivo nao encontrado!\n");
	else{
	 while(    fread(&g[qtd],sizeof(tgado),1,arq) >0     )
	     qtd++;  
	 printf("Dados carregados com sucesso!\n");
	}
	fclose(arq);
}
//---------------------------
void mostraLeite (tgado g[]){
	int i,tot=0;
	for (i=00; i<qtd; i++){
		tot=tot+g[i].leite;
	}
	printf("Sao produzidos %d litros de leite!",tot);
}
//---------------------------
void mostraAlim (tgado g[]){
	int i,tot=0;
	for (i=00; i<qtd; i++){
		tot=tot+g[i].alim;
	}
	printf("Sao consumidos %d Kg de alimentos!",tot);
}
//---------------------------
void mostraAb (tgado g[]){
	int i,encontrou=0;
	printf("\n**** Animais para o abate ****\n");
	printf("----------------------------------------------------------\n");
	for(i=0; i<qtd; i++){
		if(strcmp(g[i].abate,"S")==0){
			printf("Codigo: %d\n",g[i].cod);
			printf("Litros de leite produzido p/ semana: %d\n",g[i].leite);
			printf("Qtd de alimentos ingeridos p/ semana (Kg): %d\n",g[i].alim);
			printf("Data de nascimento: %d - %d \n",g[i].data.mes,g[i].data.ano);
			encontrou = 1;
			printf("\n----------------------------------------------------------\n");
		}
	}
	if(encontrou==0){
		printf("Cadastro nao encontrado!\n");
	}
	
}
//---------------------------



int menu(){
	int op;
	printf("1- Cadastrar gado\n");
	printf("2- Salvar dados\n");
	printf("3- Carregar dados\n");
	printf("4- Leite produzido por semana\n");
	printf("5- Alimento consumido por semana\n");
	printf("6- Listar animais pro abate\n");
	printf("0- Sair\n");
	printf("Informe a opcao desejada:");
	scanf("%d",&op);
	
	return op;
}
//---------------------------
int main(){
	tgado gados[100];
	int op;
	
	do{
		op = menu();
		switch(op){
			case 1: addGado(gados);
			break;
			case 2: salvaDados(gados);
			break;
			case 3: carregaDados(gados);
			break;
			case 4: mostraLeite(gados);
			break;
			case 5: mostraAlim(gados);
			break;
			case 6: mostraAb(gados);
			break;
			case 0: printf("Saindo...");
			break;
					
		}
		
	getch(); 
	system("cls");	
	}while(op!=0);
		
}	
