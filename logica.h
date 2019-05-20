#include <stdlib.h>
#include <time.h>

char FRASES[18][400] = {
"A mão do sucesso profissional...tem 6 dedos,cujos nomes são: Caráter,vocação,ética, talento, esforço e disciplina. - Meirira, Marily.",
"A ética difere um bom profissional de um profissional. - Carneiro, Bianca.",
"Na guerra não há vencedores. - Autor Desconhecido.",
"Olho por olho, e o mundo acabará cego. - Gandhi, Mohandas",
"Quando os ricos fazem a guerra, são sempre os pobres que morrem. - Sartre, Jean-Paul.",
"A guerra é um massacre entre pessoas que não se conhecem para proveito de pessoas que se conhecem mas não se massacram. - Valéry, Paul.",
"Se não acabarmos com a guerra, a guerra acabará conosco. - Wells, H. G.",
"É necessário cuidar da ética para não anestesiarmos a nossa consciência e começarmos a achar que tudo é normal. - Mario Sergio Cortella.",
"Só os mortos conhecem o fim da guerra. - Santayana, George.",
"A humanidade tem de acabar com a guerra antes que a guerra acabe com a humanidade. - Kennedy, John.",
"A maneira mais rápida de acabar com uma guerra é perdê-la. - Orwell, George.",
"Quem age corretamente não precisa escolher um lado, basta seguir reto. - Filizzola, Andreza.",
"A maneira mais estúpida para acabar com o melhor de uma sociedade é guerra. - Abel Perez Rojas.",
"A guerra torna o vencedor estúpido e o vencido rancoroso. - Nietzsche, Federico.",
"A paz mais desvantajosa é melhor do que a guerra mais justa. - Erasmo de Rotterdam.",
"A guerra é um mal que desonra a raça humana. - Fenelon.",
"Não existe o certo e o errado. Existe o que é ético e o que é conveniente. - Anagusko, Hideki.",
"O conhecimento serve para encantar as pessoas, não para humilhá-las. - Mario Sergio Cortella."
};



char * frasesFun(int pontuacao){
srand(pontuacao);
int x = rand() % 8;
char *ch = FRASES[x];
return ch;

};




