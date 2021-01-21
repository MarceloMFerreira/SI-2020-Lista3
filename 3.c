#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct alunos{
	int matricula;
	char nome[99];
	float nota[3];
}taluno;
int qtd=0;
//---------------------------
void addAluno(taluno a[]){
	printf("\n***** Dados do aluno %d *****\n",qtd+1);
	printf("Matricula:");
	scanf("%d",&a[qtd].matricula);
	printf("Nome:");
	fflush(stdin); gets(a[qtd].nome);
	printf("Nota da primeira prova: ");
	scanf("%f",&a[qtd].nota[0]);
	printf("Nota da segunda prova: ");
	scanf("%f",&a[qtd].nota[1]);
	printf("Nota da terceira prova: ");
	scanf("%f",&a[qtd].nota[2]);
	qtd++;
	
}
//---------------------------
void salvaDados(taluno a[]){
	FILE *arq;
	arq = fopen("alunos.dat","wb"); 
	fwrite(&a[0],sizeof(taluno),qtd,arq); 
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//---------------------------
void carregaDados(taluno a[]){
	FILE *arq;
	arq = fopen("alunos.dat","rb"); 
	if(arq==NULL)
	  printf("Arquivo nao encontrado!\n");
	else{
	 while(    fread(&a[qtd],sizeof(taluno),1,arq) >0     )
	     qtd++;  
	 printf("Dados carregados com sucesso!\n");
	}
	fclose(arq);
}
//---------------------------
void buscaNome(taluno a[]){
	int i,encontrou=0;
	char nomeb[99];
	printf("Digite o nome a ser buscado: ");
	fflush(stdin); gets(nomeb);
	for(i=0; i<qtd; i++){
		if(strcmp(a[i].nome,nomeb) == 0){
			printf("Matricula: %d\n",a[i].matricula);
			printf("Nome: %s\n",a[i].nome);
			printf("Nota da primeira prova: %.1f\n",a[i].nota[0]);
			printf("Nota da segunda prova: %.1f\n",a[i].nota[1]);
			printf("Nota da terceira prova: %.1f\n",a[i].nota[2]);
			encontrou=1;					
		}		
	}
	if(encontrou==0){
		printf("Aluno nao encontrado!");
	}
	
}
//---------------------------
void buscaMat(taluno a[]){
	int mat,i,encontrou=0;
	printf("Informe a matricula a ser buscada: ");
	scanf("%d",&mat);
	for(i=0; i<qtd; i++){
		if(mat == a[i].matricula){
			printf("Matricula: %d\n",a[i].matricula);
			printf("Nome: %s\n",a[i].nome);
			printf("Nota da primeira prova: %.1f\n",a[i].nota[0]);
			printf("Nota da segunda prova: %.1f\n",a[i].nota[1]);
			printf("Nota da terceira prova: %.1f\n",a[i].nota[2]);
			encontrou=1;					
		}		
	}
	if(encontrou==0){
		printf("Aluno nao encontrado!");
	}
	
}
//---------------------------
void buscaMaior(taluno a[]){
	float med[99],maior=0;
	int i,j,aux;
	for(i=0; i<qtd; i++){
		med[i]=0;
		for(j=0; j<3; j++){
			med[i] = med[i] + a[i].nota[j];
		}
		med[i]=med[i]/3;
		if(med[i] > maior){
			maior = med[i];
			aux=i;
		}
	}
	printf("Aluno com maior media geral: %s\n",a[aux].nome);
	printf("Nota da primeira prova: %.1f\n",a[aux].nota[0]);
	printf("Nota da segunda prova: %.1f\n",a[aux].nota[1]);
	printf("Nota da terceira prova: %.1f\n",a[aux].nota[2]);
	printf("Media: %.1f",med[aux]);
	
}
//---------------------------
void buscaAprov(taluno a[]){
	int i,j;
	float med[99];
	for(i=0; i<qtd; i++){
		med[i]=0;
		for(j=0; j<3; j++){
			med[i] = med[i] + a[i].nota[j];
		}
		med[i]=med[i]/3;
		if(med[i] >= 6){
			printf("*********************************\n");
			printf("O(a) aluno(a) %s foi aprovado(a)!\n",a[i].nome);
			printf("Media: %.1f\n",med[i]);
		} else {
		
		printf("*********************************\n");
		printf("O(a) aluno(a) %s foi reprovado(a)!\n",a[i].nome);
			printf("Media: %.1f\n",med[i]);
		}
	}

}
//---------------------------
int menu(){
	int op;
	printf("1- Cadastrar aluno\n");
	printf("2- Salvar Dados\n");
	printf("3- Carregar Dados\n");
	printf("4- Buscar aluno por nome\n");
	printf("5- Buscar aluno por matricula\n");
	printf("6- Aluno com maior media\n");
	printf("7- Verificar aprovacao dos alunos\n");
	printf("0- Sair\n");
	printf("Informe a opcao desejada:");
	scanf("%d",&op);
	
	return op;
}
//---------------------------
int main(){
	taluno alunos[100];
	int op;
	
	do{
		op = menu();
		switch(op){
			case 1: addAluno(alunos);
			break;
			case 0: printf("Saindo...");
			break;
			case 2: salvaDados(alunos);
			break;
			case 3: carregaDados(alunos);
			break;
			case 4: buscaNome(alunos);
			break;
			case 5: buscaMat(alunos);
			break;
			case 6: buscaMaior(alunos);
			break;
			case 7: buscaAprov(alunos);			
		}
	getch(); 
	system("cls");	
	}while(op!=0);
	
	
	
}
