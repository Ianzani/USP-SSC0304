/*!
  * USP - Escola de Engenharia de São Carlos \n
  * Introducao a Programacao para Eng. Eletrica - prof. Jo Ueyama
  * @file    debug_game.c
  * @author  Ian Zaniolo Sirbone (Ianzani)
  * @author  Lucas Daudt Franck  (LDFranck)
  * @date    2020
  * @brief   Jogo de Batalha Naval
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

////! Constantes.
#define PA (11) //!< Tamanho do Porta Aviao.
#define CO (10) //!< Tamanho do Couracado.
#define TP (7)  //!< Tamanho do Torpedeiro.
#define HA (8) //!< Tamanho Hidroavião.
#define N_TOTAL (16*16) //!< Tamanho total do tabuleiro.

////! Prototipos.
typedef struct _jogador jogador;
typedef struct _partida partida;

int contTeste(jogador player);

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

int contTeste(jogador player){ //!< Se retornar 0, player afundou todos os barcos.
    int temp = 0;
    for(int cont=0; cont<4; cont++)temp += player.armada[cont];
    return temp;
}

int main(){

    FILE *pArquivo = fopen("dev_debug.txt", "rb");
    if(!pArquivo) return 0;

    int cont1, cont2, cont3;
    char aux;

    partida temp = {0};
    fread(&temp, sizeof(temp), 1, pArquivo);
    fclose(pArquivo);

////! Atira nas posicoes marcadas com 'x' - X marks the spot
    for(cont1=0; cont1<2; cont1++){
        cont2 = 0;
        cont3 = 0;
        while (contTeste(temp.player[cont1])>1) {
            if(temp.player[cont1].matPrint[cont2][cont3] == 'x')
            switch (temp.player[cont1].tabuleiro[cont2][cont3]){
                case 1: //!< Porta Aviao.
                    temp.player[cont1].matPrint[cont2][cont3] = 'P';

                    temp.player[cont1].score += (temp.player[cont1].armada[0]*1.*PA/N_TOTAL)*1000;
                    temp.player[cont1].armada[0]--;
                break;

                case 2: //!< Couracado.
                    temp.player[cont1].matPrint[cont2][cont3] = 'C';

                    temp.player[cont1].score += (temp.player[cont1].armada[1]*1.*CO/N_TOTAL)*1000;
                    temp.player[cont1].armada[1]--;
                break;

                case 3: //!< Torpedeiro.
                    temp.player[cont1].matPrint[cont2][cont3] = 'T';

                    temp.player[cont1].score += (temp.player[cont1].armada[2]*1.*TP/N_TOTAL)*1000;
                    temp.player[cont1].armada[2]--;
                break;

                case 4: //!< Hidroavião.
                    temp.player[cont1].matPrint[cont2][cont3] = 'H';

                    temp.player[cont1].score += (temp.player[cont1].armada[3]*1.*HA/N_TOTAL)*1000;
                    temp.player[cont1].armada[3]--;
                break;
            }
            cont3++;
            if(cont3>=16){
                cont3=0;
                cont2++;
                if(cont2>=16)break;
            }
        }
    }

////! Marca posicoes dos barcos com 'x'
    for(cont1=0; cont1<2; cont1++) //!< Jogador.
        for(cont2=0; cont2<16; cont2++) //!< Linha.
            for(cont3=0; cont3<16; cont3++) //!< Coluna.
                if(temp.player[cont1].tabuleiro[cont2][cont3] && \
                   temp.player[cont1].matPrint[cont2][cont3] == ' ')
                        temp.player[cont1].matPrint[cont2][cont3] = 'x';
////
    pArquivo = fopen("dev_debug.txt", "wb");
    if(!pArquivo) return 0;
    fwrite(&temp, sizeof(temp), 1, pArquivo);
    fclose(pArquivo);

    return 0;
}
