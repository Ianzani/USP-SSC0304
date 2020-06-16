/*!
  * USP - Escola de Engenharia de São Carlos
  * Introducao a Programacao para Eng. Eletrica - prof. Jo Ueyama
  * @file    game.c
  * @author  Ian Zaniolo Sirbone (Ianzani)
  * @author  Lucas Daudt Franck  (LDFranck)
  * @date    2020
  * @brief   Jogo de Batalha Naval
*/

////! Bibliotecas.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

////! Simbolos Gráficos.
#define Q_ES (218)
#define Q_EI (192)
#define Q_DS (191)
#define Q_DI (217)
#define T_HO (196)
#define T_VE (179)
#define SP_D (180)
#define SP_I (193)
#define SP_S (194)
#define SP_E (195)
#define CRUZ (197)

////! Constantes.
#define PA (11) //!< Tamanho do Porta Aviao.
#define CO (10) //!< Tamanho do Couracado.
#define TP (7)  //!< Tamanho do Torpedeiro.
#define HA (8) //!< Tamanho Hidroavião.
#define N_TOTAL (16*16) //!< Tamanho total do tabuleiro.

////! Prototipos.
typedef struct _jogador jogador;
typedef struct _partida partida;

void cmdMenu(void);
void runGame(void);
void printAjuda(void);
void printMenu(void);
void printGame(partida game);
void vitoriaGame(partida game);
void gravarGame(partida game, char nome[]);
int contArmada(jogador player);
partida initPartida(void);
partida debugGame(partida game);
partida powGame(partida game, char input[]);
partida carregarGame(partida game, char nome[]);
jogador initJogador(int cont);
long int getTempo(partida game);

////! Estruturas.
struct _jogador{ //<! Estrutura com dados individuais dos jogadores.
    int score; //!< Pontuacao.
    unsigned char tabuleiro[16][16]; //!< Tabuleiro.
    unsigned char armada[4]; //!< Numero de peças restantes da armada. 0 - PA, 1 - CO, 2 - TP, 3 - HA.
    char matPrint[16][16]; //!< Tabuleiro visível.
};

struct _partida{ //<! Estrutura com dados da partida.
    jogador player[2]; //!< Dados dos jogadores.
    int turn; //! Turno do jogador.
    time_t tempo; //!< Tempo da partida.
};

////! Funções.
int contArmada(jogador player){ //!< Se retornar 0, player afundou todos os barcos.
    int temp = 0;
    for(int cont=0; cont<4; cont++)temp += player.armada[cont];
    return temp;
}

void printMenu(){ //!< Responsavel pelos graficos do menu.
    int cont;

    system("cls");
    printf("\n                         __    __    __\n");
    printf("                        |==|  |==|  |==|\n");
    printf("                      __|__|__|__|__|__|_\n");
    printf("                   __|___________________|___\n");
    printf("                __|__[]__[]__[]__[]__[]__[]__|___\n");
    printf("               |............................o.../\n");
    printf("               \\.............................../\n");
    printf("            _,~')_,~')_,~')_,~')_,~')_,~')_,~')_,~')_");
    printf("\n  ____        _        _ _             _   _                  _ \n");
    printf(" |  _ \\      | |      | | |           | \\ | |                | |\n");
    printf(" | |_) | __ _| |_ __ _| | |__   __ _  |  \\| | __ ___   ____ _| |\n");
    printf(" |  _ < / _` | __/ _` | | '_ \\ / _` | | . ` |/ _` \\ \\ / / _` | |\n");
    printf(" | |_) | (_| | || (_| | | | | | (_| | | |\\  | (_| |\\ V / (_| | |\n");
    printf(" |____/ \\__,_|\\__\\__,_|_|_| |_|\\__,_| |_| \\_|\\__,_| \\_/ \\__,_|_|\n\n");
    //! Primeira linha de blocos:
    printf("\t\t %c", Q_ES);
    for(cont=0; cont<12; cont++)putchar(T_HO);
    printf("%c\t %c", Q_DS, Q_ES);
    for(cont=0; cont<12; cont++)putchar(T_HO);
    printf("%c\n", Q_DS);
    printf("\t\t %c (1) JOGAR  %c\t %c (2) AJUDA  %c\n", T_VE, T_VE, T_VE, T_VE);
    printf("\t\t %c", Q_EI);
    for(cont=0; cont<12; cont++)putchar(T_HO);
    printf("%c\t %c", Q_DI, Q_EI);
    for(cont=0; cont<12; cont++)putchar(T_HO);
    printf("%c\n", Q_DI);
    //! Segunda linha de blocos:
    printf("\t\t\t  %c", Q_ES);
    for(cont=0; cont<11; cont++)putchar(T_HO);
    printf("%c\n", Q_DS);
    printf("\t\t\t  %c (3) SAIR  %c\n", T_VE, T_VE);
    printf("\t\t\t  %c", Q_EI);
    for(cont=0; cont<11; cont++)putchar(T_HO);
    printf("%c\n", Q_DI);
}

long int getTempo(partida game){ //!< Retorna o tempo da partida.
    return difftime(time(NULL), game.tempo); //!< Diferenca entre tempo inicial e atual.
}

void printAjuda(){ //!< Responsavel pela pagina de ajuda.
    char comd;
    int cont, aux = 68;

    system("cls");
    putchar(Q_ES);
    for(cont=0; cont<aux; cont++)putchar(T_HO);
    printf("%c\n%c ", Q_DS, T_VE);
    printf("> Comandos:%*c\n%c", aux-11, T_VE, T_VE);
    printf(" - pow <linha><coluna>: atira na coordenada indicada (ex: pow D5);%*c\n%c", aux-65, T_VE, T_VE);
    printf(" - reset: inicia uma nova partida;%*c\n%c", aux-33, T_VE, T_VE);
    printf(" - acaso: inicia um novo tabuleiro aleatorio;%*c\n%c", aux-44, T_VE, T_VE);
    printf(" - ajuda: exibe os comandos do jogo;%*c\n%c", aux-35, T_VE, T_VE);
    printf(" - gravar <nome>: salva os dados do jogo em um arquivo;%*c\n%c", aux-54, T_VE, T_VE);
    printf(" - carregar <nome>: carrega dados do jogo de um arquivo;%*c\n%c", aux-55, T_VE, T_VE);
    printf(" - sair: encerra o jogo.%*c\n%c %*c\n%c", aux-23, T_VE, T_VE, aux, T_VE, T_VE);
    printf(" > Legenda:%*c\n%c", aux-10, T_VE, T_VE);
    printf(" - P = Porta-Avioes - 11 blocos (x1);%*c\n%c", aux-36, T_VE, T_VE);
    printf(" - C = Couracado - 10 blocos (x2);%*c\n%c", aux-33, T_VE, T_VE);
    printf(" - T = Torpedeiro - 7 blocos (x3);%*c\n%c", aux-33, T_VE, T_VE);
    printf(" - H = Hidroaviao - 8 blocos (x4);%*c\n%c", aux-33, T_VE, T_VE);
    printf("%*c4) VOLTAR %c\n", aux-10, '(', T_VE);
    putchar(Q_EI);
    for(cont=0; cont<aux; cont++)putchar(T_HO);
    printf("%c\n ", Q_DI);
    while(comd = getch(), comd!='4');
}

void printGame(partida game){ //!< Responsavel pelos graficos do jogo.
    int cont, cont1, aux = 68;

    system("cls");
    putchar(Q_ES);
    for(cont=0; cont<aux; cont++)putchar(T_HO);
    printf("%c\n%c ", Q_DS, T_VE);
    printf(" %*cimestamp: %04ld:%02ld %c\n%c", aux-20, 't', getTempo(game)/60, getTempo(game)%60, T_VE, T_VE);
    printf(" > Jogador %d %*ccore: %07d %c\n%c", game.turn+1, aux-27, 's', game.player[game.turn].score, T_VE, SP_E);
    for(cont=0; cont<aux; cont++)putchar(T_HO);
    printf("%c\n%c    %c", SP_D, T_VE, T_VE);

    for(cont=65; cont<(65+16); cont++)printf(" %c %c", cont, T_VE);

    for(cont=0; cont<16; cont++){
        printf("\n%c ", T_VE);
        for(cont1=0; cont1<16; cont1++)printf("%c%c%c%c", T_HO,T_HO,T_HO, CRUZ);
        printf("%c%c%c%c", T_HO, T_HO, T_HO, SP_D);
        printf("\n%c %02d %c", T_VE, cont+1, T_VE);
        for(cont1=0; cont1<16; cont1++)printf(" %c %c", game.player[game.turn].matPrint[cont][cont1], T_VE);
    }
    printf("\n%c%c", Q_EI, T_HO);
    for(cont=0; cont<16; cont++)printf("%c%c%c%c", T_HO, T_HO, T_HO, SP_I);
    printf("%c%c%c%c\n", T_HO, T_HO, T_HO, Q_DI);
}

void cmdMenu(){ //!< Inicializa o Menu.
    char comd;

    printMenu();
    while(comd = getch(), comd!='3'){
        switch (comd) {
            case '1': //!< Jogar.
                runGame();
                printMenu();
                break;

            case '2': //!< Ajuda.
                printAjuda();
                printMenu();
                break;
        }
    }
}

partida initPartida(){ //<! Funcao que inicializa dados da partida.
    partida aux = {0};
    aux.tempo = time(NULL); //!< Salva o tempo inicial da partida.

    aux.player[0] = initJogador(0); //!< Gera tabuleiro do jogador1.
    aux.player[1] = initJogador(7); //!< Gera tabuleiro do jogador2.

    return aux;
}

void gravarGame(partida game, char nome[]){ //!< Salva partida em arquivo.txt.

    char nomeArquivo[80];
    sprintf(nomeArquivo, "%s.txt",  nome);

    game.tempo = getTempo(game); //!< Atualiza tempo da partida.
    FILE *pArquivo = fopen(nomeArquivo, "wb");
    if(!pArquivo) {
        printf("Problema ao salvar... Pressione qualquer tecla para continuar...");
        getch();
        return;
    }
    fwrite(&game, sizeof(game), 1, pArquivo);
    fclose(pArquivo);
    printf("Jogo salvo... Pressione qualquer tecla para continuar...");
    getch();
}

partida carregarGame(partida game, char nome[]){ //!< Carrega partida de um arquivo.txt.

    partida aux = {0};
    char nomeArquivo[80];

    sprintf(nomeArquivo, "%s.txt", nome);
    FILE *pArquivo = fopen(nomeArquivo, "rb");
    if(!pArquivo){
        printf("Falha ao abrir... Pressione qualquer tecla para continuar...");
        getch();
        return game;
    }
    fread(&aux, sizeof(partida), 1, pArquivo);

    fclose(pArquivo);
    aux.tempo = time(NULL) - aux.tempo; //!< Atualiza o tempo da partida.
    return aux;
}

partida powGame(partida game, char input[]){ //!< Funcao do comando POW.
    int num;
    input[0] = tolower(input[0]);
    if(input[0]>='a' && input[0]<='p'){ //!< Verifica se letra é válida.
        num = atoi(input+1); //!< Converte os caracteres do numero para valor inteiro.
        if(num>=1 && num<=16){ //!< Verifica se numero é válido.
            if(game.player[game.turn].matPrint[num-1][input[0]-'a']==' ' || \
               game.player[game.turn].matPrint[num-1][input[0]-'a']=='x') { //!< Verufica se a célula já foi atacada. ' ' = não atacada.

                switch (game.player[game.turn].tabuleiro[num-1][input[0]-'a']) { //!< Coloca no tabuleiro visível o caracter correspondente.
                    case 0: //!< Agua.
                        game.player[game.turn].matPrint[num-1][input[0]-'a'] = '*';

                        game.player[game.turn].score -= (N_TOTAL-contArmada(game.player[game.turn]))*100./N_TOTAL;
                        if (game.player[game.turn].score < 0) game.player[game.turn].score = 0;
                    break;

                    case 1: //!< Porta Aviao.
                        game.player[game.turn].matPrint[num-1][input[0]-'a'] = 'P';

                        game.player[game.turn].score += (game.player[game.turn].armada[0]*1.*PA/N_TOTAL)*1000;
                        game.player[game.turn].armada[0]--;
                    break;

                    case 2: //!< Couracado.
                        game.player[game.turn].matPrint[num-1][input[0]-'a'] = 'C';

                        game.player[game.turn].score += (game.player[game.turn].armada[1]*1.*CO/N_TOTAL)*1000;
                        game.player[game.turn].armada[1]--;
                    break;

                    case 3: //!< Torpedeiro.
                        game.player[game.turn].matPrint[num-1][input[0]-'a'] = 'T';

                        game.player[game.turn].score += (game.player[game.turn].armada[2]*1.*TP/N_TOTAL)*1000;
                        game.player[game.turn].armada[2]--;
                    break;

                    case 4: //!< Hidroavião.
                        game.player[game.turn].matPrint[num-1][input[0]-'a'] = 'H';

                        game.player[game.turn].score += (game.player[game.turn].armada[3]*1.*HA/N_TOTAL)*1000;
                        game.player[game.turn].armada[3]--;
                    break;

                }

                printGame(game);
                printf("Pressione qualquer tecla para continuar...\n");
                getch();
                game.turn = !game.turn;

                return game; //!< Retorna dados atualizados.
            }
        }
    }
    printf("Coordenada Invalida... Pressione qualquer tecla para continuar...\n");
    getch();
    return game;
}

void vitoriaGame(partida game){ //!< Responsavel pelos graficos da vitoria.
    char comd;
    int cont;

    system("cls");
    printf("\n%*c__      ___ _    __       _       _ \n", 13, ' ');
    printf("%*c\\ \\    / (_) |  /_/      (_)     | |\n", 13, ' ');
    printf("%*c \\ \\  / / _| |_ ___  _ __ _  __ _| |\n", 13, ' ');
    printf("%*c \\ \\/ / | | __/ _ \\| '__| |/ _` | |\n", 14, ' ');
    printf("%*c  \\  /  | | || (_) | |  | | (_| |_|\n", 14, ' ');
    printf("%*c   \\/   |_|\\__\\___/|_|  |_|\\__,_(_)\n", 14, ' ');
    printf("%*c_______________\n", 25, ' ');
    printf("%*c|@@@@|     |####|\n", 24, ' ');
    printf("%*c|@@@@|     |####|\n", 24, ' ');
    printf("%*c|@@@@|     |####|\n", 24, ' ');
    printf("%*c\\@@@@|     |####/\n", 24, ' ');
    printf("%*c\\@@@|     |###/\n", 25, ' ');
    printf("%*c `@@|_____|##'\n", 25, ' ');
    printf("%*c      (O)\n", 25, ' ');
    printf("%*c   .-'''''-.\n", 25, ' ');
    printf("%*c .'  * * *  `.\n", 25, ' ');
    printf("%*c:  *       *  :\n", 25, ' ');
    printf("%*c: *  JOGADOR  * :\n", 24, ' ');
    printf("%*c: *     %d     * :\n", 24, ' ', (!game.turn)+1);
    printf("%*c:  *       *  :\n", 25, ' ');
    printf("%*c `.  * * *  .'\n", 25, ' ');
    printf("%*c   `-.....-'\n", 25, ' ');

    printf("%*c", 22, Q_ES);
    for(cont=0; cont<20; cont++)putchar(T_HO);
    printf("%c\n%*c %*cCORE %*c\n", Q_DS, 22, T_VE, 8, 'S', 7, T_VE);
    printf("%*c Jogador 1: %07d %c\n", 22, T_VE, game.player[0].score, T_VE);
    printf("%*c Jogador 2: %07d %c\n%*c", 22, T_VE, game.player[1].score, T_VE, 22, Q_EI);
    for(cont=0; cont<20; cont++)putchar(T_HO);
    printf("%c\n%*c4) MENU\n", Q_DI, 29, '(');

    while(comd = getch(), comd!='4');

    return;
}

void runGame(){ //!< Laço do jogo.

    const char comandos[8][9] = {"pow", "ajuda", "acaso", "gravar", "carregar", "reset", "sair", "ssc0304"};
    char *pToken = NULL;
    char input[31], cont1, cont2;
    int aux;

    partida game = initPartida(); //!< Cria nova partida.

    printGame(game);
    printf(" Digite o comando:\n");
    printf(" > ");

    while (fflush(stdin), fgets(input, 31, stdin)){
        pToken = strtok(input, " \n"); //!< Pega primeira parte da string - até um espaço ou '\n'.
        if(pToken){
            aux = strlen(pToken);
            for(cont1 = 0; cont1 < aux; cont1++)pToken[cont1] = tolower(pToken[cont1]);
            for(cont1 = 0; cont1 < 8; cont1++)if(!strcmp(pToken, comandos[cont1]))break; //!< Verifica o comando digitado.
        } else cont1 = 8;

        switch (cont1) {
            case 0: //!< Comando pow.
                pToken = strtok(NULL, " \n");
                if(!pToken) {
                    printf("Comando invalido... Pressione qualquer tecla para continuar...");
                    getch();
                    break;
                } else {
                    game = powGame(game, pToken);
                    if(!contArmada(game.player[!game.turn])){
                        vitoriaGame(game);
                        return;
                    }
                }
            break;

            case 1: //!< Comando ajuda.
                printAjuda();
            break;

            case 2: //!< Comando acaso.
                for(cont2 = 0; cont2 < 2; cont2++){
                    aux = game.player[cont2].score;
                    game.player[cont2] = initJogador(cont2);
                    game.player[cont2].score = aux;
                }
            break;

            case 3: //!< Comando gravar.
                pToken = strtok(NULL, "\n");
                if(!pToken) {
                    printf("Comando invalido... Pressione qualquer tecla para continuar...");
                    getch();
                    break;
                } else gravarGame(game, pToken);
            break;

            case 4: //!< Comando carregar.
                pToken = strtok(NULL, "\n");
                if(!pToken) {
                    printf("Comando invalido... Pressione qualquer tecla para continuar...");
                    getch();
                    break;
                } else game = carregarGame(game, pToken);
            break;

            case 5: //!< Comando reset.
                game = initPartida();
            break;

            case 6: //!< Comando sair.
                return;
            break;

            case 7: //!< Comando oculto - debug.
                game = debugGame(game);

            default:
                printf("Comando invalido... Pressione qualquer tecla para continuar...");
                getch();
            break;
        }
        printGame(game);
        printf(" Digite o comando:\n");
        printf(" > ");
    }
}

partida debugGame(partida game){ //!< Comando oculto para ajudar o debug.
    FILE* pDebug = fopen("debug.exe", "r");
    if(!pDebug) return game;
    fclose(pDebug);

    pDebug = fopen("dev_debug.txt", "wb");
    if(!pDebug) return game;
    fwrite(&game, sizeof(game), 1, pDebug);
    fclose(pDebug);

    system("debug.exe");

    pDebug = fopen("dev_debug.txt", "rb");
    if(!pDebug) return game;
    fread(&game, sizeof(partida), 1, pDebug);
    fclose(pDebug);

    remove("dev_debug.txt");

    return game;
}

jogador initJogador(int cont){ //<! Funcao que inicializa dados dos jogadores.

    jogador temp = {0};

    //! Dados da armada: PA = [1], CO = [2], TP = [3], HA = [4].
    unsigned char armada[4][3] = {{1, PA, 1}, //!< Quantidade: 1, Tamanho: 11, Printar: 1.
                                  {2, CO, 2},
                                  {3, TP, 3},
                                  {4, HA, 4}};

    enum direcao {horizontal, vertical} aux;
    int linha, coluna;
    int verdade, flagSorteio;

    srand(time(NULL)+cont); //!< Inicializa seed do sorteio.

    for(cont=0; cont<4; cont++)temp.armada[cont] = armada[cont][0] * armada[cont][1]; //!< Numero total de casas por tipo de barco.
    for(linha=0; linha<16; linha++)
        for(coluna=0; coluna<16; coluna++)
            temp.matPrint[linha][coluna] = ' '; //!< Preenche tabuleiro visível com "vazio".

    for(int clinha=0; clinha<4; clinha++){ //!< Laço para preencher tabuleiro com armada.
        for(int caux=armada[clinha][0]; caux>0; caux--){
            flagSorteio = 1;
            while(flagSorteio){ //!< Enquanto a peça não for corretamente alocada no tabuleiro fica no loop.
                verdade = 0;
                aux = rand()%2; //!< Sorteia se a peça ficará na horizontal (0) ou vertical (1).
                if(aux == horizontal){
                    coluna = rand()%(16-armada[clinha][1]);
                    linha = rand()%16;
                    for(int cont=coluna; cont<=(armada[clinha][1]+coluna); cont++){ //!< Verifica se espaço está vazio.
                        verdade += temp.tabuleiro[linha][cont];
                    }
                    if(verdade==0)flagSorteio = 0; //!< Se os espaço está disponível, sair do loop.
                }
                else{ //!< Caso na vertical.
                    coluna = rand()%16; //!< Sorteia uma coluna do tabuleiro.
                    linha =  rand()%(16-armada[clinha][1]); //!< Sorteia uma linha do tabuleiro.
                    for(int cont=linha; cont<=(armada[clinha][1]+linha); cont++){ //!< Verifica se espaço está vazio.
                        verdade += temp.tabuleiro[cont][coluna];
                    }
                    if(verdade==0)flagSorteio = 0; //!< Se os espaço está disponível, sair do loop.
                }
            }
       //! Quando encontrada uma posição válida no tabuleiro.
            if(aux == horizontal){ //!< Preenche horizontalmente as células.
            for(int cont=coluna; cont<(armada[clinha][1]+coluna); cont++)
            temp.tabuleiro[linha][cont] = armada[clinha][2];
            }
            else{ //!< Preenche verticalmente as células.
                for(int cont=linha; cont<(armada[clinha][1]+linha); cont++)
                temp.tabuleiro[cont][coluna] = armada[clinha][2];
            }
        }
    }
   return temp; //!< Retorna dados atualizados.
}

int main() { //!< Função principal.
    cmdMenu(); //!< Inicializa o Menu.
    return 0;
}
