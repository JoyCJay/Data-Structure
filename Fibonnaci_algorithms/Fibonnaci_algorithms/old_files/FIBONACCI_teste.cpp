/* AlGORITMOS PARA SÉRIE DE FIBBONACI POR ANDRÉA CYNTHIA E LYRENE FERNANDES*/

/* Como o limite do tipo de dados long é de 4 bytes (-2.147.483.648 a 2.147.483.647)
   os algoritmos abaixo calculam até o 47º elemento da série de Fibonacci */

#include   <iostream.h>
#include   <fstream.h>
#include   <conio.h>
#include   <stdlib.h>
#include   <string.h>
#include   <time.h>
#include   <stdio.h>
#include   <dos.h>
#include   <math.h>


/*****************************************************************
******************************************************************
O algoritmo 1 possui complexidade é exponencial em n
Recebe como parâmetro de entrada a posição da série de fibbonaci
******************************************************************
******************************************************************/
double fibonacci1(double n){
   if (n<2){
     return  n;
   }//end_if
   else{
      return fibonacci1(n-1)+fibonacci1(n-2);
   }//end_else
}//end_fibbonaci1



/*****************************************************************
******************************************************************
O algoritmo 2 possui complexidade é linear O(n)
Recebe como parâmetro de entrada a posição da série de fibbonaci
******************************************************************
******************************************************************/
double fibonacci2(int posicao){
    double i=1, j=0;

    for(int k=1;k<=posicao;k++){
        j=i+j;
        i=j-i;
    }//end_for

   return j;
}//end_fibbonaci2



/*****************************************************************
******************************************************************
O algoritmo 3 possui complexidade é linear O(log(n))
Recebe como parâmetro de entrada a posição da série de fibbonaci
******************************************************************
******************************************************************/
double fibonacci3(int posicao){
  double i=1, j=0, k=0, h=1, t;
  while (posicao>0){
    if((posicao%2)!=0){
      t=j*h;
      j=i*h + j*k + t;
      i=i*k + t;
    }//end_if
    t=h*h;
    h=2*k*h + t;
    k=k*k + t;
    posicao=posicao/2;
   };//end_while
  return j;
}//end_fibonacci3


/*****************************************************************
******************************************************************
Algoritmo 4 pela fórmula de binet - parte deste código foi inspirado
no trabalho "Efficiently Raising Matrices to an Integer Power" de
Victor J. Duvanenko's, Jun 1991
******************************************************************
******************************************************************/
double fibonacci4(int n)
{
  double static sr5, phi = 0.0;
  double static f[9] = {0.0, 1.0, 1.0, 2.0, 3.0, 5.0, 8.0, 13.0, 21.0};

  if (n <= 0)  return 0.0;
  if (n <= 8)  return f[n];
  if (phi == 0.0) {
    sr5 = sqrt(5.0);
    phi = 0.5 + sr5 / 2.0;
  }
  return  floor( 0.5 + pow( phi, n) / sr5);
}//end_fibonacci4


/* Find smallest n for which ffib(n) is not exactly correct */
int test( void)
{
  int n;
  for (n = 2; ; n++) {
    if (fibonacci4(n) != (fibonacci4(n - 1) + fibonacci4(n - 2))) {
      return 0;
    }//end_if
    else {
      return 1;
    }//end_else
  }//end_for
}//end_test

/********************************
*********************************
Programa principal***************
*********************************
********************************/
void main(){
     time_t tInicial;
     clrscr();
     cout << "P"  << "\t\t"
          << "t1" << "\t\t"
          << "t2" << "\t\t"
          << "t3" << "\t\t"
          << "t4" << "\t\t"
          << "\n";

     // cout << fibonacci1(100) << "\t\t";
      tInicial=time(NULL);
       for(int k=0;k<100;k++)
         fibonacci2(100);
      cout << difftime(time(NULL),tInicial) << "\t\t";

      tInicial=time(NULL);
      for(int k=0;k<100;k++)
        fibonacci3(100);
      cout << difftime(time(NULL),tInicial) << "\t\t";

      for(int k=0;k<100;k++)
        fibonacci4(100);
      cout << difftime(time(NULL),tInicial) << "\t\t";

}//end_main
