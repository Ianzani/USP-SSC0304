// Author: LDFranck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//! Estrutura dados do Estudante.
typedef struct _student{
   char pnome[16], snome[16]; //!< Primeiro nome, Sobrenome
   int nusp; //!< Numero USP
   float nota[4]; //!< Notas Avaliações: 0 - PA, 1 - SA, 2 - TR, 3 - MED
}Student;

//! Estrutura de uma turma.
typedef struct _class{
   Student* members; //!< Matriz de estudantes
   int numOfStudents; //!< Numero de estudantes na turma.
   struct _class* nxtClass; //!< Ponteiro para a proxima turma (Lista Encadeada)
}Class;

//! Le do usuario informacoes dos estudantes - OK.
void readStudentData(Student* pStudent){
   fflush(stdin); //!< Limpa buffer.
   scanf("%15[^ ] %15[^\n]", pStudent->pnome, pStudent->snome);
   scanf("%d", &pStudent->nusp);
   scanf("%f %f %f", &pStudent->nota[0], &pStudent->nota[1], &pStudent->nota[2]);
   pStudent->nota[3] = (pStudent->nota[0] + pStudent->nota[1] + pStudent->nota[2])/3; //!< Calcula a media.
}

//! Aloca dinamicamente um array de Students - OK.
Student* newStudentArray(int num){
   int cont;
   Student* pStudent = malloc(sizeof(Student)*num);

   for(cont=0; cont<num; cont++)readStudentData(&pStudent[cont]); //!< Le informacoes dos estudantes.

   return pStudent;
}

//! Aloca dinamicamente uma turma nova - Lista Encadeada - OK.
void newClass(Class** pClass){
   if(!(*pClass)){ //!< Verifica se elemento é o último da lista.
      int num;
      scanf("%d", &num); //!< Le numero de estudantes da turma.

      *pClass = malloc(sizeof(Class));
      (*pClass)->members = newStudentArray(num);
      (*pClass)->numOfStudents = num;
      (*pClass)->nxtClass = NULL;
   } else newClass(&(*pClass)->nxtClass); //!< Verifica se proximo elemento é o último da lista.
}

//! Procura estudante dentro do Array Estudantes - OK.
int searchStudentArray(Student* list, int pos, int num, const char* name){
   if(pos>=num)return -1; //!< Se estudante nao encontrado retorna -1.
   if(!strcmp((list+pos)->pnome, name))return pos; //!< Se estudante encontrado retorna posicao no array.
   else return searchStudentArray(list, pos+1, num, name);
}

//! Procura e imprime os dados de determinado estudante - OK.
void printStudentData(Class *pClass, const char* name){
   if(pClass){ //!< Se o ponteiro inicial for NULL, não existe turmas.
      int index = searchStudentArray(pClass->members, 0, pClass->numOfStudents, name); //!< Procura estudante na turma atual.
      if(index != -1){ //!< Caso encontrar estudante, imprimir dados.
         printf("Nome: %s %s\n", pClass->members[index].pnome, pClass->members[index].snome);
         printf("P1: %.1f\n", pClass->members[index].nota[0]);
         printf("P2: %.1f\n", pClass->members[index].nota[1]);
         printf("Trabalho: %.1f\n", pClass->members[index].nota[2]);
         printf("Media Final: %.2f\n", pClass->members[index].nota[3]);
      } else printStudentData(pClass->nxtClass, name); //!< Caso nao encontrado, procura no próximo elemento da lista.
   } else printf("Aluno nao encontrado.\n");
}

//! Deleta e libera espaço de uma turma da lista - OK.
void freeClass(Class** pClass){
   if((*pClass)){ //!< Verifica se existe algo a ser liberado.
      Class* aux = (*pClass)->nxtClass;
      free((*pClass)->members); //!< Libera estrutura Estudantes.
      (*pClass)->members = NULL;
      free((*pClass)); //!< Libera turma.
      (*pClass) = aux; //!< Transfere apontador para o proximo elemento da lista.
   }
}

//! Libera todo o espaço de memoria alocado - Lista Encadeada - OK.
void freeAll(Class** pClass){
   if((*pClass))freeAll(&(*pClass)->nxtClass);
   freeClass(pClass);
}

//! Conta o numero de turmas criadas - OK.
int contClass(Class* pClass){
   static int cont = 0;
   if(pClass){ //!< Verifica se lista chegou ao fim.
      cont++;
      contClass(pClass->nxtClass);
   } else {
      int aux = cont;
      cont = 0;
      return aux;
   }
}

//! Preenche vetor com dados estatisticos da turma - OK.
void statVector(Class* pClass, float vetor[]){
   int num, cont;
   num = pClass->numOfStudents; //!< Pega o numero de estudantes de determinada turma.

   for(cont=0; cont<5; cont++)vetor[cont] = 0; //!< Zera vetor.
   for(cont=0; cont<num; cont++){
      vetor[0] += pClass->members[cont].nota[0]; //!< Primeira Avaliacao.
      vetor[1] += pClass->members[cont].nota[1]; //!< Segunda Avaliacao.
      vetor[2] += pClass->members[cont].nota[2]; //!< Trabalho.
      vetor[3] += pClass->members[cont].nota[3]; //!< Media das notas.
      vetor[4] += (pClass->members[cont].nota[3]>=5)?1:0; //!< Alunos aprovados.
   }
   for(cont=0; cont<4; cont++)vetor[cont] /= num*1.; //!< Calcula a media.
   vetor[4] *= (100./num); //!< Calcula %.
}

//! Imprime dados estatisticos de forma formatada - OK.
void printStats(Class* pClass){
   if(pClass){
      float vetor[5];
      statVector(pClass, vetor); //!< Preenche vetor com estatísticas.
      printf("%.2f %.2f %.2f %.2f %.0f%%\n", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4]);
      printStats(pClass->nxtClass);
   }
}

//! Gera o arquivo com as estatisticas das turmas - OK.
void createStatFile(Class* pClass){
   if(pClass){
      float vetor[5];
      FILE *pArquivo = fopen("estat.bin", "wb"); //!< Abre arquivo para escrita binaria.
      do{
         statVector(pClass, vetor); //!< Preenche vetor com dados da turma.
         fwrite(vetor, sizeof(vetor), 1, pArquivo); //!< Escreve no arquivo o vetor.
      } while (pClass = pClass->nxtClass); //!< Verifica se existe uma proxima turma.
      fclose(pArquivo); //!< Fecha arquivo e libera o ponteiro.
   }
}

//! Gera arquivo com os dados dos alunos - OK.
void createTxtFile(Class* pClass){
   if(pClass){
      char nomeArq[31];
      FILE *pArquivo = NULL;
      do{
         fflush(stdin);
         scanf("%30[^\n]", nomeArq); //!< Recebe o nome do arquivo do usuario.
         pArquivo = fopen(nomeArq, "w"); //!< Abre arquivo para escrita de texto.

         for(int cont = 0; cont<(pClass->numOfStudents); cont++){ //!< Imprime os dados dos alunos.
            fprintf(pArquivo, "%s, %s, ", pClass->members[cont].pnome, pClass->members[cont].snome);
            fprintf(pArquivo, "%d, ", pClass->members[cont].nusp);
            fprintf(pArquivo, "%.1f, %.1f, ", pClass->members[cont].nota[0], pClass->members[cont].nota[1]);
            fprintf(pArquivo, "%.1f, %.2f\n", pClass->members[cont].nota[2], pClass->members[cont].nota[3]);
         }

         fclose(pArquivo); //!< Fecha arquivo e libera ponteiro.
      } while (pClass = pClass->nxtClass); //!< Verifica se existe uma proxima turma.
   }
}

int main(){
   int cmdo;
   char strAux[16];
   Class* pClass = NULL;

   while (scanf("%d", &cmdo), cmdo!=5){ //!< Laço do MENU - verifica comando do usuario.
      switch (cmdo) {
         case 1: //!< Cria turma.
            newClass(&pClass);
         break;

         case 2: //!< Procura aluno.
            fflush(stdin);
            scanf("%15[^\n]", strAux);
            printStudentData(pClass, strAux);
         break;

         case 3: //!< Imprime estatísticas das turmas.
            printStats(pClass);
         break;

         case 4: //!< Grava informações das turmas.
            createStatFile(pClass);
            createTxtFile(pClass);
         break;
      }
   }

   printf("Encerrando o sistema...\n");
   freeAll(&pClass); //!< Libera todos os ponteiros.

   return 0;
}
