#include <stdlib.h>
#include <time.h>

char FRASES[18][400] = {
"A m�o do sucesso profissional...tem 6 dedos,cujos nomes s�o: Car�ter,voca��o,�tica, talento, esfor�o e disciplina. - Meirira, Marily.",
"A �tica difere um bom profissional de um profissional. - Carneiro, Bianca.",
"Na guerra n�o h� vencedores. - Autor Desconhecido.",
"Olho por olho, e o mundo acabar� cego. - Gandhi, Mohandas",
"Quando os ricos fazem a guerra, s�o sempre os pobres que morrem. - Sartre, Jean-Paul.",
"A guerra � um massacre entre pessoas que n�o se conhecem para proveito de pessoas que se conhecem mas n�o se massacram. - Val�ry, Paul.",
"Se n�o acabarmos com a guerra, a guerra acabar� conosco. - Wells, H. G.",
"� necess�rio cuidar da �tica para n�o anestesiarmos a nossa consci�ncia e come�armos a achar que tudo � normal. - Mario Sergio Cortella.",
"S� os mortos conhecem o fim da guerra. - Santayana, George.",
"A humanidade tem de acabar com a guerra antes que a guerra acabe com a humanidade. - Kennedy, John.",
"A maneira mais r�pida de acabar com uma guerra � perd�-la. - Orwell, George.",
"Quem age corretamente n�o precisa escolher um lado, basta seguir reto. - Filizzola, Andreza.",
"A maneira mais est�pida para acabar com o melhor de uma sociedade � guerra. - Abel Perez Rojas.",
"A guerra torna o vencedor est�pido e o vencido rancoroso. - Nietzsche, Federico.",
"A paz mais desvantajosa � melhor do que a guerra mais justa. - Erasmo de Rotterdam.",
"A guerra � um mal que desonra a ra�a humana. - Fenelon.",
"N�o existe o certo e o errado. Existe o que � �tico e o que � conveniente. - Anagusko, Hideki.",
"O conhecimento serve para encantar as pessoas, n�o para humilh�-las. - Mario Sergio Cortella."
};



char * frasesFun(int pontuacao){
srand(pontuacao);
int x = rand() % 8;
char *ch = FRASES[x];
return ch;

};




