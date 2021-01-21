#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	int dia,mes,ano;
	char nome[30],emprestimo[0];	
}temprest;
//---------------------------
typedef struct{
	char titulo[30],console[15];
	int ano,ranking;
	temprest emp;	
}tjogo;

int qtd=0;
//---------------------------
void addJogo(tjogo j[]){
	printf("**** Jogo %d ****\n",qtd+1);
	printf("Titulo: ");
	fflush(stdin); gets(j[qtd].titulo);
	printf("Console: ");
	fflush(stdin); gets(j[qtd].console);
	printf("Ano:");
	scanf("%d",&j[qtd].ano);
	printf("Ranking: ");
	scanf("%d",&j[qtd].ranking);
	printf("-----------------------------------\n");
	printf("Este jogo esta emprestado?(S/N)");
	fflush(stdin); gets(j[qtd].emp.emprestimo);
	if(strcmp(j[qtd].emp.emprestimo,"S") == 0){
		printf("Data do emprestimo DD MM AA: ");
		scanf("%d%d%d", &j[qtd].emp.dia,&j[qtd].emp.mes,&j[qtd].emp.ano);
		printf("Nome da pessoa: ");
		fflush(stdin);gets(j[qtd].emp.nome);
	}else{
		printf("Cadastro feito com sucesso!");
	}
	qtd++;
	
}
//---------------------------
void salvaDados (tjogo j[]){
	FILE *arq;
	arq = fopen("jogos.dat","wb"); 
	fwrite(&j[0],sizeof(tjogo),qtd,arq); 
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//---------------------------
void carregaDados (tjogo j[]){
	FILE *arq;
	arq = fopen("jogos.dat","rb"); 
	if(arq==NULL)
	  printf("Arquivo nao encontrado!\n");
	else{
	 while(    fread(&j[qtd],sizeof(tjogo),1,arq) >0     )
	     qtd++;  
	 printf("Dados carregados com sucesso!\n");
	}
	fclose(arq);
}
//---------------------------
void buscaTitulo (tjogo j[]){
	char tit[30];
	int i,encontrou=0;
	printf("Informe o titulo a ser buscado: ");
	fflush(stdin); gets(tit);
	for(i=0; i<qtd; i++){
		if(strcmp(j[i].titulo,tit) == 0){
		printf("**** Jogo %d ****\n",i+1);
		printf("Titulo: %s\n",j[i].titulo);
		printf("Console: %s\n",j[i].console);
		printf("Ano: %d\n",j[i].ano);
		printf("Ranking: %d\n",j[i].ranking);
		encontrou=1;	
		}
	}
	if(encontrou==0){
		printf("Cadastro nao encontrado!\n");
	}
}
//---------------------------
void buscaCon (tjogo j[]){
	char con[30];
	int i,encontrou=0;
	printf("Informe o console a ser buscado: ");
	fflush(stdin); gets(con);
	for(i=0; i<qtd; i++){
		if(strcmp(j[i].console,con) == 0){
		printf("**** Jogo %d ****\n",i+1);
		printf("Titulo: %s\n",j[i].titulo);
		printf("Console: %s\n",j[i].console);
		printf("Ano: %d\n",j[i].ano);
		printf("Ranking: %d\n",j[i].ranking);
		encontrou=1;	
		}
	}
	if(encontrou==0){
		printf("Cadastro nao encontrado!\n");
	}
}
//---------------------------
void empJogo (tjogo j[]){
	char jog[30];
	int i,aux,encontrou=0;
	printf("Informe o titulo do jogo a ser emprestado: ");
	fflush(stdin); gets(jog);
	for(i=0; i<qtd; i++){
		if(strcmp(j[i].titulo,jog)==0){
			aux=i;
			encontrou = 1;
		}
	}
	if(encontrou == 0){
		printf("Cadastro nao encontrado!");
	}else
	if(strcmp(j[aux].emp.emprestimo,"N")==0){
		printf("Nome da pessoa: ");
		fflush(stdin); gets(j[aux].emp.nome);
		printf("Data do emprestimo DD MM AA: ");
		scanf("%d%d%d", &j[qtd].emp.dia,&j[qtd].emp.mes,&j[qtd].emp.ano);
		strcpy(j[aux].emp.emprestimo,"S");
	} else
		printf("Jogo ja esta emprestado!");
	
}
//---------------------------
void devJogo (tjogo j[]){
	char jog[30];
	int i,aux,encontrou=0;
	printf("Informe o titulo do jogo a ser devolvido: ");
	fflush(stdin); gets(jog);
	for(i=0; i<qtd; i++){
		if(strcmp(j[i].titulo,jog)==0){
			aux=i;
			encontrou = 1;
		}
	}
	if(encontrou == 0){
		printf("Cadastro nao encontrado!");
	}else
	if(strcmp(j[aux].emp.emprestimo,"N")==0){
		printf("Este jogo nao esta emprestado!");
	} else if(strcmp(j[aux].emp.emprestimo,"S")==0){
	
		strcpy(j[aux].emp.emprestimo,"N");
		printf("Jogo devolvido!");
	}
	
}
//---------------------------
void mostraEmp (tjogo j[]){
	int i,aux=0;
	printf("**** Jogos emprestados ****\n");
	for(i=0; i<qtd; i++){
		if(strcmp(j[i].emp.emprestimo,"S")==0){
			printf("Titulo: %s\nNome: %s\n\n",j[i].titulo,j[i].emp.nome);
			aux++;
		}
	}
	if(aux==0){
		printf("Nenhum jogo esta emprestado!");
	}
}
//---------------------------
int menu(){
	int op;
	printf("1- Cadastrar jogo\n");
	printf("2- Salvar dados\n");
	printf("3- Carregar dados\n");
	printf("4- Buscar jogo por titulo\n");
	printf("5- Buscar jogo por console\n");
	printf("6- Emprestar jogo\n");
	printf("7- Devolver jogo emprestado\n");
	printf("8- Mostrar jogos emprestados\n");
	printf("0- Sair\n");
	printf("Informe a opcao desejada:");
	scanf("%d",&op);
	
	return op;
}
//---------------------------
int main(){
	tjogo jogos[99];
	int op;
	
	do{
		op = menu();
		switch(op){
			case 1: addJogo(jogos);
			break;
			case 2: salvaDados(jogos);
			break;
			case 3: carregaDados(jogos);
			break;
			case 4: buscaTitulo(jogos);
			break;
			case 5: buscaCon(jogos);
			break;
			case 6: empJogo(jogos);
			break;
			case 7: devJogo(jogos);
			break;
			case 8: mostraEmp(jogos);
			break;
			case 0: printf("Saindo...");
			break;
					
		}
		
	getch(); 
	system("cls");	
	}while(op!=0);
		
}	
