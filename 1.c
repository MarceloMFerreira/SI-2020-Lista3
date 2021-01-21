#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct bandas{
	char nome[99],genero[99];
	int integ,pos;	
} tbanda;
int qtd=0;

//----------------------------
void add(tbanda b[]){
	printf("***** Dados para banda %d *****\n",qtd+1);
	printf("Nome:");
	fflush(stdin); gets(b[qtd].nome);
	printf("Genero:");
	fflush(stdin); gets(b[qtd].genero);
	printf("Integrantes:");
	scanf("%d",&b[qtd].integ);
	printf("Ranking:");
	scanf("%d",&b[qtd].pos);
	qtd++;	
				
}
//---------------------------
void mostraBandas(tbanda b[]){
	int i;
	for(i=0;i<qtd;i++){	
	printf("\n----------- Banda %d ---------\n",i+1);
	printf("Nome:%s\nGenero:%s\nIntegrantes:%d\nRanking:%d",b[i].nome, b[i].genero,b[i].integ, b[i].pos);
	       }
	
}
//---------------------------
void bucaRank(tbanda b[]){
	int ranking,i,aux=0;
	printf("\n***** Buscar posicao *****\n");
	printf("Informe um valor de 1 a 10, correspondente a posicao da banda no ranking: ");
	scanf("%d",&ranking);
	for(i=0; i<qtd; i++){
		if(ranking == b[i].pos){
		aux=1;		
	printf("\n----------- Banda %d ---------\n",i+1);
	printf("Nome:%s\nGenero:%s\nIntegrantes:%d\nRanking:%d",b[i].nome, b[i].genero,b[i].integ, b[i].pos);
	}
	}
	if(aux==0){
		printf("Nenhuma banda foi cadastrada nessa posicao!");
	}
}
//---------------------------
void salvaBandas(tbanda b[]){
	int i;
	FILE *arq;
	arq = fopen("bandas.dat","wb"); 
	fwrite(&b[0],sizeof(tbanda),qtd,arq); 
	printf("Dados salvos com sucesso\n");
	fclose(arq);
}
//---------------------------
void buscaGen(tbanda b[]){
	char gen[99];
	int i;
	printf("Digite o genero a ser buscado: ");
	fflush(stdin); gets(gen); 
	printf("\n***** Bandas do genero %s *****\n",gen);	
	for(i=0; i<qtd; i++){
		if(strcmp(gen,b[i].genero)==0){
			printf("\n----------- Banda %d ---------\n",i+1);
	printf("Nome:%s\nIntegrantes:%d\nRanking:%d",b[i].nome,b[i].integ, b[i].pos);
					
		}
	}
}
//---------------------------
void carregaDados(tbanda b[]){
	FILE *arq;
	arq = fopen("bandas.dat","rb");
	if(arq==NULL)
	  printf("Arquivo nao encontrado!\n");
	else{
	 while(    fread(&b[qtd],sizeof(tbanda),1,arq) >0     )
	     qtd++;  
	 printf("Dados carregados com sucesso!\n");
	}
	fclose(arq);
}
//---------------------------
void bandaFav(tbanda b[]){
	char band[99];
	int i,aux;
	printf("\n***** Bandas favoritas *****\n");
	printf("Informe o nome da banda a ser buscada: ");
	fflush(stdin); gets(band);
	
	for(i=0; i<qtd; i++){
		if(strcmp(band,b[i].nome) == 0){
			aux=i;
		}
	}
	if(b[aux].pos <= 3){
		printf("A banda %s esta entre as favoritas!\nPosicao no ranking: %d",band,b[aux].pos);
	}else
	printf("A banda %s nao esta entre as favoritas!\nPosicao no ranking: %d",band,b[aux].pos);
	
}
//---------------------------
void delBanda(tbanda b[]){
	int i,j, encontrou=0,aux;
	char nomeBanda[40];
	printf("Informe a banda para ser excluida: ");
	fflush(stdin); gets(nomeBanda);
	for(i=0;i<qtd;i++){
		
		if(strcmp(nomeBanda, b[i].nome) == 0){
		aux=i; 
		for(aux=aux; aux<qtd; aux++){
		
		  strcpy(b[aux].nome,b[aux+1].nome);
		  strcpy(b[aux].genero,b[aux+1].genero);
		  b[aux].pos = b[aux+1].pos;
		  b[aux].integ = b[aux+1].integ;
		  
		  encontrou = 1;
		  }
		  qtd--; 
		  printf("Excluindo...");
		break; 
	   }
	}
	 if(encontrou!=1) 
	   printf("Banda nao encontrada :(");
}

//---------------------------
 void altReg (tbanda b[]){
 	char band[40],bandNova[40],genNovo[40];
 	int op,i,aux,encontrou=0,posNovo,integNovo;
 	printf("\n***** Alterar regsitro *****\n");
 	printf("Informe o nome da banda que deseja alterar um registro:");
 	fflush(stdin); gets(band);
 	for(i=0; i<qtd; i++){
 		if(strcmp(band, b[i].nome) == 0 ){
 			aux=i;
 			encontrou=1;
 		}
		 } 
	if(encontrou==1){	 
 	printf("\n***** Alterar regsitro *****\n");
 	printf("1- Nome\n2- Genero\n3- Numero de integrantes\n4- Posicao no ranking\nQual registro deseja alterar:");
 	scanf("%d",&op);
 	
 	
	 if(op == 1){
	 	printf("Informe o novo nome a ser inserido: ");
	 	fflush(stdin); gets(bandNova);
	 	strcpy(b[aux].nome,bandNova);	
	 	
	 } else if(op == 2){
	 	printf("Informe o novo genero: ");
	 	fflush(stdin); gets(genNovo);
	 	strcpy(b[aux].genero,genNovo);
	 	
	 } else if(op == 3){
	 	printf("Informe o novo numero de integrantes: ");
	 	scanf("%d",&integNovo);
	 	b[aux].integ = integNovo;
	 	
	 } else if(op == 4){
	 	printf("Informe a nova posicao no ranking: ");
	 	scanf("%d",&posNovo);
	 	b[aux].pos = posNovo;
	 }
	 printf("Registro alterado...");
	} else
	printf("Banda nao encontrada :(");
 	
 }
//---------------------------
int menu(){
	int op;
	printf("1- Cadastrar banda\n");
	printf("2- Mostrar bandas\n");
	printf("3- Buscar banda pelo ranking\n");
	printf("4- Salvar bandas em arquivo\n");
	printf("5- Busca por genero\n");
	printf("6- Carregar dados\n");
	printf("7- Verificar bandas favoritas\n");
	printf("8- Excluir banda\n");
	printf("9- Alterar dados de um registro\n");
	printf("0- Sair\n");
	printf("Informe a opcao desejada:");
	scanf("%d",&op);
	return op;	
	
	
}
//---------------------------
int main(){
	tbanda bandas[10];
	int op;
	
	do{
		op = menu();
		switch(op){
			case 1:	add(bandas);
			 break;
			case 2: mostraBandas(bandas); 
			 break;
			case 3: bucaRank(bandas);
			 break;	
			case 0: printf("Saindo...");
			 break;
			case 4: salvaBandas(bandas);
			 break;
			case 5: buscaGen(bandas);
			 break;
			case 6: carregaDados(bandas);
			 break;
			case 7: bandaFav(bandas);
			 break;
			case 8: delBanda(bandas);
			 break;
			case 9: altReg(bandas);
			break;
	
	}
		getch(); 
		system("cls");
	}while(op!=0);

}
