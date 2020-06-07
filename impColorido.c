#include <stdio.h>
#include <windows.h>

int main(){

  HANDLE  hConsole;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

  for(int cont = 1; cont < 255; cont++) {
    SetConsoleTextAttribute(hConsole, cont);
    printf("%3d  %s\n", cont, "TESTE");
  }

  return 0;
}
