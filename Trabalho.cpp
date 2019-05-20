#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.c>
#include <string.h>
#include <locale.h>
#include "logica.h"

//1=azul(1 a 2)  10=verde(nenhum)  4=vermelho(3 a 4) 8=cinza(5 a 6) 6=Amarelo(7 a 8) 15=Branco

int escolhaOpcoes=-1,ajudaI=0,indicadorI=0,desenvolvedorI=0,dificuldade=2,local=0,pontuacao=0,score[10];


void ajudaFuncao(int indicadorI, int linha){
	if (indicadorI==1){
		printf("\t\t");
		if (linha ==2){
			textcolor(10);
			printf("Verde - Nao ha bombas por perto");
		}else{
			if(linha ==3){
				textcolor(9);
				printf("Azul - Perto de uma bomba.");
			}else{
				if (linha ==4){
					textcolor(8);
					printf("Cinza - Armadilha.");
				}
			}
		}
	}else{
		printf("\t\t");
		if (linha ==2){
			textcolor (10);
			printf("Verde - Nao ha bombas por perto");
		}else{
			if (linha ==3){
				textcolor(9);
			printf("Azul - 1 ou 2 bombas por perto.");
			}else{
				if (linha ==4){
					textcolor(12);
					printf("Vermelho - 3 ou 4 bombas por perto.");
				}else{
					if (linha ==5){
						textcolor(7);
						printf("Prata - 5 ou 6 bombas por perto.");
					}else{
						if (linha ==6){
							textcolor(8);
							printf("Cinza - Armadilha.");
						}
					}
				}
			}
		}
	}
} //fim da função ajudaFuncao()


	
void mostrar(char M[10][10], int pontuacao){
	
	int i, j;
	if(pontuacao > 0){
		printf("\n\n   ");
		char *frase = { frasesFun( pontuacao)};
		int x = 0, y = 0;
		
		while(frase[x] != '\0'){
			
			y++;
			if(frase[x]=='-'){
				printf("\n\t\t\t\t\t  %c",frase[x]);
			}else{
				printf("%c",frase[x]);
			}
			if(( frase[x] == ' ') && y > 50){
				printf("\n   ");
				y = 0;
			}
			
			x++;
		}
		
	}
	
	
	printf("\n\n      0   1   2   3   4   5   6   7   8   9");
	printf("\n    -----------------------------------------\n");
	
	for (i=0;i<10;i++){
		printf("  %d ",i);
		for (j=0;j<10;j++){
			printf("| ");
			if (M[i][j]=='G'){
				textcolor(10);
				printf("%c",M[i][j]);
				textcolor(15);
			}else{
				if(M[i][j]=='B'){
					textcolor(9);
					printf("%c",M[i][j]);
					textcolor(15);
				}else{
					if(M[i][j]=='R'){
						textcolor(12);
						printf("%c",M[i][j]);
						textcolor(15);
					}else{
						if(M[i][j]=='S'){
							textcolor(7);
							printf("%c",M[i][j]);
							textcolor(15);
						}else{
							if(M[i][j]=='Y'){
								textcolor(6);
								printf("%c",M[i][j]);
								textcolor(15);
							}else{
								if(M[i][j]=='O'){
									textcolor(15);
									printf("%c",M[i][j]);
								}else{
									if(M[i][j]=='X'){
										textcolor(8);
										printf("%c",M[i][j]);
										textcolor(15);
									}else{
										if (M[i][j]==' '){
											printf(" ");
										}
									}
								}
							}
						}
					}
				}
			}
			printf(" ");
		}
			printf("|");
			if (i==0){
				printf("\t\t\tPontuacao:%d",pontuacao);
				}
			
			// if (i>1 &&i<7)
			if(ajudaI==1){
				ajudaFuncao(indicadorI,  i);
				textcolor(15);
			}
			printf("\n    -----------------------------------------\n");
	}//fim do for externo
}//fim da função mostrar



void limparCampo(char campo[10][10]){
	int i, j;
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			campo[i][j] = 'G';
		}
	}
}


void limparChar(char visao[10][10]){
	int i, j;
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			visao[i][j] =' ';
		}
	}
}


void limparQuantidade(int quantidade[10][10]){
	int i, j;
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			quantidade[i][j] = 0;
		}
	}
}


/*
   gera boanbas e armadilhas na matriz do jogo
*/
void locais_diferentes(int *X,int *Y,char campo[10][10], int z){
	int diferente=0,cont=0;
	int i,j;
	
	for(i=0;i<z;i++){
		X[i] = 0;
		Y[i] = 0;
	}
	
	
	srand ((unsigned)time(NULL));
	while(diferente!=z){
		for (i=0;i<z;i++){
			X[i] = rand()%10;
			Y[i] = rand()%10;
			for (j=0;j<z;j++){
				if((X[i] == X[j] ) && (Y[i] == Y[j]) && (campo[X[i]][Y[i]]!='O')){
					cont++;
				}
			}
			if (cont == 1){
				diferente++;
			}else{
				cont = 0;
				i--;
			}
			cont = 0;
		}
	}
}

/*
  funcao que de acordo com a dificuldade gera mais ou menos bombas e armadilhas
*/
void bombas_armadilhas(char campo[10][10]){
	int i,j,z;
	
	if (dificuldade==1){
		z=10;
	}else{
		if (dificuldade==2){
			z=13;
		}else{
			if (dificuldade==3){
				z=20;
			}
		}
		
	}
	int posicaoBombaX[z],posicaoBombaY[z],posicaoArmadilhaX[z],posicaoarmadilhaY[z];
	
	locais_diferentes(posicaoBombaX,posicaoBombaY,campo, z);
	for (i=0;i<z;i++){
		campo[posicaoBombaX[i]][posicaoBombaY[i]] = 'O';
	}
	
	if (dificuldade==2 || dificuldade==3){
		locais_diferentes(posicaoArmadilhaX,posicaoarmadilhaY,campo, z);
		for (i=0;i<z;i++){
			campo[posicaoArmadilhaX[i]][posicaoarmadilhaY[i]] = 'X';
		}
	}
}


void numeracao(char campo[10][10],int quantidade[10][10]){
	int m,n, i, j;
	
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			if (campo[i][j] =='O'){
				for (m=i-1;m<=i+1;m++){
					for (n=j-1;n<=j+1;n++){
						if (((((campo[m][n]!='O' && m!=-1) && m!=10) && n!=-1) && n!=10) && campo[m][n]!='X'){
							quantidade[m][n]++;
						}
					}
				}
			}
		}
	}
}

void proximidade1(char campo[10][10]){
	int m,n,i,j;
	
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			if (campo[i][j] =='O'){
				for (m=i-1;m<=i+1;m++){
					for (n=j-1;n<=j+1;n++){
						if (((((campo[m][n]!='O' && m!=-1) && m!=10) && n!=-1) && n!=10) && campo[m][n]!='X'){
							campo[m][n] = 'B';
						}
					}
				}
			}
		}
	}
}


void letra(char campo[10][10],int quantidade[10][10]){
	int i, j;
	for (i=0;i<10;i++){
		for (j=0;j<10;j++){
			if(quantidade[i][j] == 1|| quantidade[i][j] == 2){
				campo[i][j] = 'B';
			}else{
				if (quantidade[i][j] == 3|| quantidade[i][j] == 4){
					campo[i][j] = 'R';
				}else{
					if(quantidade[i][j] == 5|| quantidade[i][j] == 6){
						campo[i][j] = 'S';
					}else{
						if(quantidade[i][j] == 7|| quantidade[i][j] == 8){
							campo[i][j] = 'Y';
						}
					}
				}
			}
		}
	}
}

void jogo(char campo[10][10],char visao[10][10]){
	int cordenadas[2],vivo=1;
	
	while(vivo==1){
		if(desenvolvedorI == 1){
			printf("\n");
			mostrar(campo, pontuacao);
		}
		printf("De as cordenadas X e Y:");
		scanf("%d %d",&cordenadas[0],&cordenadas[1]);
		visao[cordenadas[0]][cordenadas[1]] = campo[cordenadas[0]][cordenadas[1]];
		system("cls");
	   
		if(visao[cordenadas[0]][cordenadas[1]]== 'O'){
			vivo--;
		}else{
			if (visao[cordenadas[0]][cordenadas[1]] == 'G'){
				pontuacao++;
			}else{
				if (visao[cordenadas[0]][cordenadas[1]] == 'B'){
					pontuacao += 5;
				}else{
					if (visao[cordenadas[0]][cordenadas[1]] == 'R'){
						pontuacao += 20;
					}else{
						if (visao[cordenadas[0]][cordenadas[1]] == 'S'){
							pontuacao += 100;
						}else{
							if (visao[cordenadas[0]][cordenadas[1]] == 'Y'){
								pontuacao += 300;
							}						
						}
					}
				}
			}
		}
		mostrar(visao, pontuacao);  
	}
}

main(){
	
	setlocale(LC_ALL,"");
	char campo[10][10],visao[10][10],denovo,ajuda[15] = "Desabilitado.",indicador[15] = "Quantidade.",desenvolvedor[15] = "Desabilitado.",voltarMenu=1;
	int quantidade[10][10],escolhaMenu=-1,escolhaDificuldade=-1,erro=0;
	
	while (denovo!='n'){
		escolhaMenu=-1;
		escolhaDificuldade=-1;
		erro=0;
		voltarMenu=1;
		while (escolhaMenu!=1 && voltarMenu==1){
			textcolor(15);
			//Menu
			if(escolhaMenu != 0){
				escolhaOpcoes = -1;      
				escolhaOpcoes = -1;
				system("cls");
				printf("Menu:\n");
				printf("1 - Comecar jogo.\n");
				printf("2 - Opcoes.\n");
				printf("3 - Sair\n");
				scanf("%d",&escolhaMenu);
				if (escolhaMenu == 1){
				//Começar Jogo.
					system("cls");
					while (escolhaDificuldade != 0){
						printf("Dificuldade:\n");
						printf("1 - Facil.\n");
						printf("2 - Normal.\n");
						printf("3 - Filosofo Grego.\n");
						scanf("%d",&escolhaDificuldade);
						switch (escolhaDificuldade){
							case 1:
								dificuldade = 1;
								escolhaDificuldade = 0;
								voltarMenu = 0;
								break;
							case 2:
								dificuldade = 2;
								escolhaDificuldade = 0;
								voltarMenu = 0;
								break;
								
							case 3:
								dificuldade = 3;
								escolhaDificuldade = 0;
								voltarMenu = 0;
								break;
							case 4:
								escolhaDificuldade = 4;
								system("cls");
								break;		
						}
					}
					system("cls");
				}else{
					if(escolhaMenu == 2){
						//Opcoes
						while(escolhaOpcoes!=4){
							system("cls");
							printf("Opcoes:\n");
							printf("1 - Ajuda:");
							textcolor(10);
							printf(" %s\n",ajuda);
							textcolor(15);
							printf("2 - Indicador de Bombas:");
							textcolor(10);
							printf(" %s\n",indicador);
							textcolor(15);
							printf("3 - Modo Desenvolvedor:");
							textcolor(10);
							printf(" %s\n",desenvolvedor);
							textcolor(15);
							printf("4 - Voltar\n");
							scanf("%d",&escolhaOpcoes);
							switch(escolhaOpcoes){
								textcolor(10);
								case 1:
									ajudaI++;
									if(ajudaI%2 == 0){
										strcpy(ajuda,"Desabilitado.");
									}else{
										ajudaI=1;
										strcpy(ajuda,"Habilitado.");
									}
									break;
								case 2:
									indicadorI++;
									if(indicadorI%2 == 0){
										strcpy(indicador,"Proximidade.");
									}else{
										indicadorI=1;
										strcpy(indicador,"Quantidade.");
									}
									break;
								case 3:
									desenvolvedorI++;
									if(desenvolvedorI%2 == 0){
										strcpy(desenvolvedor,"Desabilitado.");
									}else{
										desenvolvedorI=1;
										strcpy(desenvolvedor,"Habilitado.");
									}
									break;
							}
						}
						//Fim Opcões
					}else{
						if (escolhaMenu == 3){
							system("cls");
							exit(0);
						}
					}
				}
			}
		}
		system("cls");
		limparCampo(campo);
		limparChar(visao);
		if (indicadorI==0){
			limparQuantidade(quantidade);
		}
		bombas_armadilhas(campo);
		if(indicadorI==0){
			numeracao(campo,quantidade);
			letra(campo,quantidade);
		}else{
			proximidade1(campo);	
		}
		mostrar(visao, pontuacao);
		/*if(ajudaI==1){
			ajudaFuncao(indicadorI, i);
		} */     
		jogo(campo,visao);
		while(erro==0){
			printf("\nVoce Perdeu.");
			printf("\nSua Pontuacao foi de :%d",pontuacao);
			printf("\nJogar denovo? s-Sim ou n-Nao.\n");
			scanf(" %s",&denovo);
			switch (denovo){
				case ('s'):
					erro++;
					break;
				case ('n'):
					erro++;
					break;
				default:
					system("cls");
					printf("\nVoce Perdeu.");
					printf("\nSua Pontuacao foi de :%d",pontuacao);
					break;
			}
		}
	}
}
