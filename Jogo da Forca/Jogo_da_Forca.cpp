#include <ctype.h> //manipulação de caracteres
#include <locale.h> //funções que permitem uso da linguagem de acordo com o local especificado
#include <stdio.h> //funções de entrada e saída de dados
#include <stdlib.h> //funções de alocação de memória
#include <string.h> //manipulação de cadeia de caracteres
#include <time.h> //manipulação de dados no formato de data e hora

const char personagem[20] = {' ',' ','O',' ','\n',
                             ' ','_',':','_','\n',
                             ' ',' ','|',' ','\n',
                             ' ','/',' ','\\'};
char resultado[25] = {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}, procuradas[27], palavra[25];
int tentativas, n_repitidas, g, n_letra = 0;
FILE *arq = fopen("palavras.txt", "r"); //abertura do arquivo para leitura

void sorteia(){ 
    srand(time(0));//rand- geração de números 'aleatórios' (algoritmo é determinístico - dado uma certa entrada sempre produzir� uma mesma sa�da)//time(0)- semente para geração do número de acordo com a hora atual do sistema
    int num = 1 + rand() % 150; //intervalo de n�meros a ser sorteado: 1 até 150
    rewind(arq);//fseek(arq, 0, SEEK_SET); //reposiciona o cursor para o início do arquivo a cada sorteio
    for(int i = 0; i < num; i++){
    	fgets(palavra, 22, arq); //lê a palavra no arquivo até encontrar o \n
    }
    //printf("%s", palavra); //apenas pra mostar, retirar pois se não, não há graça
}
 
void inicia_variaveis(){
    system("clear");
    for(int i = 0; i < strlen(resultado); i++) 
        resultado[i] = '_';
    tentativas = 6;
    g = n_repitidas = 0; // equivalente a: g=0 e rep=0
    for(int i = 0; i < strlen(procuradas); i++)
    	procuradas[i] = '*'; // preenche o vetor procuradas com *
    sorteia(); //caso o usuário deseje jogar novamente, a função sorteia é chamada e as variáveis serão inicializadas
}
 
void imprime_letras(){ 
    for(int i = 0; i < strlen(palavra)-2; i++){ //o -2 é devido a contagem estar incluindo o \0 e \n
        printf("%c ", resultado[i]); //mostra na tela os espaços correspondentes ao tamanho da palavra sorteada
    }
    printf("\n");
}

int ganhou(){
    int b = 1;
    for(int i = 0; i < strlen(palavra)-2; i++){
        if(resultado[i] == '_'){ //percorre o vetor verificando se há algum espaço sem ser preenchido
            b = 0;
            break; //ignora o restante do bloco 
        }
    }
    return b;//Se ganhou retorna 1
}

int repetiu(char letra){
    int b = 0;
    for(int i = 0; i < strlen(procuradas); i++){
        if(procuradas[i] == toupper(letra) || procuradas[i] == tolower(letra)){ //verifica se a letra passada, sendo ela maiúscula ou minúscula, já foi digitada
		    b = 1;
		    break;
		}
    }
    return b;//retorna 1 se repetiu
}

int testa_letra(char letra){
    int b = 0;
    if(isalpha(letra)){ // verifica se o caracter passado pelo usuário é uma letra
	    for(int i = 0; i < strlen(palavra); i++){
	        if(palavra[i] == toupper(letra) || palavra[i] == tolower(letra)){ //compara se a letra passada est� contida no vetor palavra
	            resultado[i] = letra; //adiciona a letra no vetor resultado na posição correspondente
	            b = 1;
	        }
	    }
	    if(!repetiu(letra))
	    	procuradas[g++] = letra; // adiciona cada letra digitada no vetor procuradas
	}else{
		n_letra = 1;
		b = 1;
	}
    return b;//retorna zero caso não haja letra na palavra
}

void boneco(int tent){
    system("clear");
    printf("  ______\n");
    printf("  :    |\n");
    int t = tent;
    for(int i = 0; i < tent; i++){
        if(personagem[i] == '\n')
            printf("   |"); 
        printf("%c", personagem[i]);
        if(personagem[i] == ' ' || personagem[i] == '\n' || personagem[i] == ':')
            tent++;
    }
    if(t == 2 || t == 5){
    	printf("     |");
	}else if(t == 1 || t == 4){
		printf("    |");
	}else if(t == 3){
		printf("   |");
	}else if(t == 0){
		printf("       |");
	}
    for(int i = 0; i < 6-t; i++){
        printf("\n       |");
    }
    if(t == 6)
        printf("   |\n       |");
    printf("\n-----------");
}

void imprime_procuradas(){
    printf("Letras procuradas: ");
    for(int i = 0; i < strlen(procuradas); i++){
        if(procuradas[i] != '*')
            printf("%c, ", procuradas[i]);
    }
    printf("\n");
}

int main(){
	//system ("color 0B"); //altera a cor da fonte
    setlocale(LC_ALL, "ptb"); //permite utilizar acentuação
	system("clear"); //limpa a tela "cls" se for executar no Windows
    char letra, s;
    if (arq == NULL){
    	puts("Problemas na abertura do arquivo!!!\n");
    	return 1;//ERRO!
	}
    do{ 
        inicia_variaveis();
        puts("TENTE ACERTAR:");
        do{
            imprime_letras();
            puts("Digite a letra à ser procurada:");
            //setbuf(stdin, NULL); //remove o lixo da memória referente ao teclado
	        scanf(" %c", &letra);
            n_repitidas = repetiu(letra);
            if(testa_letra(letra)){ //verifica se tem a letra digitada na palavra
                if(ganhou()) //verifica se o usuário ganhou
                    break;
            }else{ //se não acertou a letra
            	if(!n_repitidas)
                	tentativas--;
            }
            boneco(6 - tentativas);
            printf("\nVocê tem %d tentativas.\n", tentativas);
            imprime_procuradas();
            if(n_repitidas)
                puts("Letra ja procurada!");
            if(n_letra){
            	n_letra = 0;
            	puts("Não é letra!");
			}
        }while(tentativas > 0);
        if(tentativas > 0){ 
            boneco(6 - tentativas); //só mesmo pra ilustrar
            printf("\nVocê GANHOU ainda restando %d tentativas.\n", tentativas);
            imprime_letras();
            puts("PARABENS!!! VOCÊ GANHOU O JOGO!");
        }else{
            puts("VOCÊ PERDEU O JOGO! INFELIZMENTE NÃO FOI DESTA VEZ.");
            printf("A PALAVRA ERA: %s", palavra); //mostra a palavra que foi sorteada quando o usuário perde
        }
        do{
	        puts("1) Jogar Novamente\n2) Sair");
	        //setbuf(stdin, NULL); //limpa lixo
	        scanf(" %c", &s);
	        if(s == '1' || s == '2')
	        	break;
	        else
	        	puts("Digite apenas 1 ou 2;");
    	}while(1);
    }while(s == '1');
    puts("Obrigado por jogar! Desenvolvido por Lucas Santos.");
    return 0;
}
