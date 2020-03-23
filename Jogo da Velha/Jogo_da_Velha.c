#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> //biblioteca para usar a função sleep

char velha[10], jogador1[11], jogador2[11] = "COMPUTADOR", xo, s, c;
int jogada,n;

void inicia_variaveis(){
	jogada = 0;
	xo = 'x';
	for(int i = 1; i < 10; i++){
		velha[i-1] = i+48;
	}
}

int sorteia_posicao(){
	srand(time(NULL));
	return 1 + rand() % 9;
}

int tem(int n){
	if(n < 1 || n > 9)
		return 0;
	else if(velha[n-1] != n+48)//somo +48 pois o codigo ASCII do 2 por exemplo é 50 e assim por diante.
		return 1;
	else
		return 0;
}//retorna 1 se já tiver alguma coisa naquela posição diferente do número n q passei

void vez_pc(){
	do{
		n = sorteia_posicao();	
	}while(tem(n));//só sai daqui depois q ele sortear um número q não tem ainda
	velha[n-1] = 'O';
}

void defende(){
	if(velha[0] == '1' && velha[3] == 'X' && velha[6] == 'X'){//1 4 7
		velha[0] = 'O';//defende-se no 1 pra não deixar o cara ganhar
	}else if(velha[0] == 'X' && velha[3] == '4' && velha[6] == 'X'){//1 4 7
		velha[3] = 'O';//defende-se no 4 pra não deixar o cara ganhar
	}else if(velha[0] == 'X' && velha[3] == 'X' && velha[6] == '7'){//1 4 7
		velha[6] = 'O';//defende-se no 7 pra não deixar o cara ganhar
	}else if(velha[1] == 'X' && velha[4] == 'X' && velha[7] == '8'){//2 5 8
		velha[7] = 'O';
	}else if(velha[1] == 'X' && velha[4] == '5' && velha[7] == 'X'){
		velha[4] = 'O';
	}else if(velha[1] == '2' && velha[4] == 'X' && velha[7] == 'X'){
		velha[1] = 'O';
	}else if(velha[2] == 'X' && velha[5] == '6' && velha[8] == 'X'){//3 6 9
		velha[5] = 'O';
	}else if(velha[2] == '3' && velha[5] == 'X' && velha[8] == 'X'){
		velha[2] = 'O';
	}else if(velha[2] == 'X' && velha[5] == 'X' && velha[8] == '9'){
		velha[8] = 'O';
	}else if(velha[0] == 'X' && velha[1] == 'X' && velha[2] == '3'){//1 2 3
		velha[2] = 'O';
	}else if(velha[0] == '1' && velha[1] == 'X' && velha[2] == 'X'){
		velha[0] = 'O';
	}else if(velha[0] == 'X' && velha[1] == '2' && velha[2] == 'X'){
		velha[1] = 'O';
	}else if(velha[3] == 'X' && velha[4] == '5' && velha[5] == 'X'){//4 5 6
		velha[4] = 'O';
	}else if(velha[3] == '4' && velha[4] == 'X' && velha[5] == 'X'){
		velha[3] = 'O';
	}else if(velha[3] == 'X' && velha[4] == 'X' && velha[5] == '6'){
		velha[5] = 'O';
	}else if(velha[6] == '7' && velha[7] == 'X' && velha[8] == 'X'){//7 8 9
		velha[6] = 'O';
	}else if(velha[6] == 'X' && velha[7] == '8' && velha[8] == 'X'){
		velha[7] = 'O';
	}else if(velha[6] == 'X' && velha[7] == 'X' && velha[8] == '9'){
		velha[8] = 'O';
	}else if(velha[0] == '1' && velha[4] == 'X' && velha[8] == 'X'){//1 5 9
		velha[0] = 'O';
	}else if(velha[0] == 'X' && velha[4] == '5' && velha[8] == 'X'){
		velha[4] = 'O';
	}else if(velha[0] == 'X' && velha[4] == 'X' && velha[8] == '9'){
		velha[8] = 'O';
	}else if(velha[2] == '3' && velha[4] == 'X' && velha[6] == 'X'){//3 5 7
		velha[2] = 'O';
	}else if(velha[2] == 'X' && velha[4] == '5' && velha[6] == 'X'){
		velha[4] = 'O';
	}else if(velha[2] == 'X' && velha[4] == 'X' && velha[6] == '7'){
		velha[6] = 'O';
	}else{
		vez_pc();
	}
}

void ataca(){
	if(velha[0] == '1' && velha[3] == 'O' && velha[6] == 'O'){//1 4 7
		velha[0] = 'O';//ataca no 1 pra ganhar
	}else if(velha[0] == 'O' && velha[3] == '4' && velha[6] == 'O'){//1 4 7
		velha[3] = 'O';//ataca no 4 pra ganhar
	}else if(velha[0] == 'O' && velha[3] == 'O' && velha[6] == '7'){//1 4 7
		velha[6] = 'O';//ataca no 7 pra ganhar
	}else if(velha[1] == 'O' && velha[4] == 'O' && velha[7] == '8'){//2 5 8
		velha[7] = 'O';
	}else if(velha[1] == 'O' && velha[4] == '5' && velha[7] == 'O'){
		velha[4] = 'O';
	}else if(velha[1] == '2' && velha[4] == 'O' && velha[7] == 'O'){
		velha[1] = 'O';
	}else if(velha[2] == 'O' && velha[5] == '6' && velha[8] == 'O'){//3 6 9
		velha[5] = 'O';
	}else if(velha[2] == '3' && velha[5] == 'O' && velha[8] == 'O'){
		velha[2] = 'O';
	}else if(velha[2] == 'O' && velha[5] == 'O' && velha[8] == '9'){
		velha[8] = 'O';
	}else if(velha[0] == 'O' && velha[1] == 'O' && velha[2] == '3'){//1 2 3
		velha[2] = 'O';
	}else if(velha[0] == '1' && velha[1] == 'O' && velha[2] == 'O'){
		velha[0] = 'O';
	}else if(velha[0] == 'O' && velha[1] == '2' && velha[2] == 'O'){
		velha[1] = 'O';
	}else if(velha[3] == 'O' && velha[4] == '5' && velha[5] == 'O'){//4 5 6
		velha[4] = 'O';
	}else if(velha[3] == '4' && velha[4] == 'O' && velha[5] == 'O'){
		velha[3] = 'O';
	}else if(velha[3] == 'O' && velha[4] == 'O' && velha[5] == '6'){
		velha[5] = 'O';
	}else if(velha[6] == '7' && velha[7] == 'O' && velha[8] == 'O'){//7 8 9
		velha[6] = 'O';
	}else if(velha[6] == 'O' && velha[7] == '8' && velha[8] == 'O'){
		velha[7] = 'O';
	}else if(velha[6] == 'O' && velha[7] == 'O' && velha[8] == '9'){
		velha[8] = 'O';
	}else if(velha[0] == '1' && velha[4] == 'O' && velha[8] == 'O'){//1 5 9
		velha[0] = 'O';
	}else if(velha[0] == 'O' && velha[4] == '5' && velha[8] == 'O'){
		velha[4] = 'O';
	}else if(velha[0] == 'O' && velha[4] == 'O' && velha[8] == '9'){
		velha[8] = 'O';
	}else if(velha[2] == '3' && velha[4] == 'O' && velha[6] == 'O'){//3 5 7
		velha[2] = 'O';
	}else if(velha[2] == 'O' && velha[4] == '5' && velha[6] == 'O'){
		velha[4] = 'O';
	}else if(velha[2] == 'O' && velha[4] == 'O' && velha[6] == '7'){
		velha[6] = 'O';
	}else{
		defende();
	}
}

int qm_comeca(){
	srand(time(NULL));
	return 1 + rand() % 2;
}

void imprime(){
	system("clear");
	for(int i = 0; i < 9; i++){
		printf("                  ");
		for(int j = 0; j < 3; j++){
			printf(" %c ",velha[i++]);
			if(j < 2)
				printf("|");
		}
		i--;
		if(i < 6)
			printf("\n                  -----------");
		printf("\n");
	}
}

void pega_nomes(char c){
	printf("Digite o nome do primeiro jogador com no máximo 10 letras: ");
	setbuf(stdin, NULL);
	scanf("%s", jogador1);
	printf("%s, você ficará com 'X';\n", jogador1);
	if(c == '1'){//terá 2 jogadores
		printf("Digite o nome do segundo jogador com no máximo 10 letras: ");
		setbuf(stdin, NULL);
		scanf("%s", jogador2);
		printf("%s, você ficará com 'O';\n", jogador2);
	}
}

void lance(char *jogador){
	do{
		printf("\nSua vez %s: ", jogador);
		setbuf(stdin, NULL);
		scanf("%d", &jogada);
		//jogada -= 48;//scanf("%d",&jogada);//pega o ASCII do número e transforma no número certo com -48
		if(jogada < 1 || jogada > 9)
			puts("\nDigite um número entre 1 e 9.");
		if(tem(jogada))
			puts("\nDigite outro número, pois este já foi digitado!");
	}while((jogada < 1 || jogada > 9) || tem(jogada));
}

int ganhou(){
	xo = velha[0];//1
	if(velha[3] == xo && velha[6] == xo){//1 4 7
		return 1;
	}else if(velha[4] == xo && velha[8] == xo){//1 5 9
		return 1;
	}else if(velha[1] == xo && velha[2] == xo){//1 2 3
		return 1;
	}else{
		xo = velha[1];//2
		if(velha[4] == xo && velha[7] == xo){//2 5 8
			return 1;
		}else{
			xo = velha[2];//3
			if(velha[4] == xo && velha[6] == xo){//3 5 7
				return 1;
			}else if(velha[5] == xo && velha[8] == xo){//3 6 9
				return 1;
			}else{
				xo = velha[3];//4
				if(velha[4] == xo && velha[5] == xo){//4 5 6
					return 1;
				}else {
					xo = velha[6];//7
					if(velha[7] == xo && velha[8] == xo){//7 8 9
						return 1;
					}else{
						for(int i = 0; i < 9; i++){
							if(velha[i] == i+49){//+49 pois i começa em 0;
								xo = 'x';
								return 0;//não ganhou
							}	
						}
						xo = 'V';
						return 1;
					}
				}
			}
		}
	}
}//retorna 0 se não tiver ganhado ainda

int alguem_ganhou(){
	if(ganhou() != 0){//houve vencedor, ou deu velha
		if(xo == 'X'){
			printf("Parabens %s você ganhou!\n", jogador1);
		}else if(xo == 'O'){
			printf("Parabens %s você ganhou!\n", jogador2);
		}else if(xo == 'V'){
			puts("Deu velha!, não houve ganhador!");
		}else{
			return 0;
		}
		return 1;//so retorna 1 se houver um ganhador
	}else{
		return 0;
	}
}

void espera(){
	printf("Vez do computador.\n");
	for(int i = 0; i < 5; i++){//faz com q epere 5 segundos
		printf(". ");
		sleep(1);//espera um segundo
	}
	printf("\n");
}

void ordem1(char c){
	do{
		lance(jogador1);
		velha[jogada-1] = 'X';
		imprime();
		if(alguem_ganhou())//quebra o while infinito
			break;
		if(c == '1'){//vai ser 2 jogadores
			lance(jogador2);
			velha[jogada-1] = 'O';
		}else{
			espera();
			ataca();
		}
		imprime();
		if(alguem_ganhou())//quebra o while infinito
			break;
	}while(1);
}

void ordem2(char c){
	do{
		if(c == '1'){//vai ser 2 jogadores
			lance(jogador2);
			velha[jogada-1] = 'O';
		}else{
			espera();
			ataca();
		}
		imprime();
		if(alguem_ganhou())//quebra o while infinito
			break;
		lance(jogador1);
		velha[jogada-1] = 'X';
		imprime();
		if(alguem_ganhou())//quebra o while infinito
			break;
	}while(1);
}

int main(){
	//system("color 0f");//deixa o fundo branco e a cor da fonte branco brilhante
	setlocale(LC_ALL, "ptb");
	do{
		system("clear");
		puts("ESCOLHA O MODO QUE DESEJA JOGAR:");
		do{
	        puts("1) Player 1. Vs. Player 2.\n2) Player 1. Vs. COMPUTADOR");
	        setbuf(stdin,NULL);
	        scanf("%c",&c);
	        if(c == '1' || c == '2')
	        	break;
	        else
	        	puts("\nDigite apenas 1 ou 2;");
    	}while(1);
		int comeca = qm_comeca();
		inicia_variaveis();
		imprime();
		pega_nomes(c);
		if(comeca == 1){
			printf("\n%s você começa.\n", jogador1);
			ordem1(c);	
		}else{
			printf("\n%s você começa.\n", jogador2);
			ordem2(c);
		}
		do{
	        puts("\n1. Jogar novamente\n2. Sair");
	        setbuf(stdin, NULL);
	        scanf("%c",&s);
	        if(s == '1' || s == '2')
	        	break;
	        else
	        	puts("\nDigite apenas 1 ou 2;");
    	}while(1);
    }while(s == '1');
	puts("Obrigado por jogar! Desenvolvido por Lucas Santos.");
    return 0;
}
