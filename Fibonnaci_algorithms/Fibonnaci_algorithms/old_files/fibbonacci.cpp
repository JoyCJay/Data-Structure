/* AlGORITMOS PARA SÉRIE DE FIBBONACI POR ANDRÉA CYNTHIA E LYRENE FERNANDES*/

#include   <iostream.h>
#include   <fstream.h>
#include   <conio.h>
#include   <stdlib.h>
#include   <string.h>
#include   <time.h>
#include   <stdio.h>
#include   <dos.h>



/*****************************************************************
******************************************************************
O algoritmo 1 possui complexidade é exponencial em n
Recebe como parâmetro de entrada a posição da série de fibbonaci
******************************************************************
******************************************************************/
unsigned long fibonacci1(unsigned long n){
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
unsigned long fibonacci2(unsigned long posicao){
    unsigned long i=1, j=0;

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
unsigned long fibonacci3(unsigned long posicao){
  unsigned long i=1, j=0, k=0, h=1, t;
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
Algoritmo 4
******************************************************************
******************************************************************/




/********************************
*********************************
Programa principal***************
*********************************
********************************/
void main(){
     clock_t tInicial,tFinal;
     clrscr();
     cout << "P"  << "\t\t\t" << "s1" << "\t\t\t"
          << "t1" << "\t\t\t" << "s2" << "\t\t\t"
          << "t2" << "\t\t\t" << "s3" << "\t\t\t"
          << "t3"  << "\n";

     for(int n=1;n<=300;n++){
        cout << n << "\t\t\t";
        //algoritmo 1, de complexidade exponencial em n
   /*     tInicial= time(NULL);
        cout << fibonacci1(n) << "\t\t\t" ;
        cout << difftime(time(NULL), tInicial)<< "\t\t\t";*/



        //algoritmo 2, de complexidade linear
        //tInicial= time(NULL);
        tInicial=clock()/(CLOCKS_PER_SEC*1000);
        cout << fibonacci2(n) << "\t\t\t";
        tFinal=clock()/(CLOCKS_PER_SEC*1000);
        cout << (tFinal-tInicial)  << "\t\t\t";

        //algoritmo 3, de complexidade linear
        tInicial= clock();
        cout << fibonacci3(n) << "\t\t\t"; //algoritmo 3, de complexidade O(log(n))
        cout << (clock()- tInicial)  << "\n";
     }//end_for
}//end_main