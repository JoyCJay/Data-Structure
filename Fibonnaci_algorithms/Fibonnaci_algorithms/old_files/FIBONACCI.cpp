/* Compute Fibonacci series by Andr�a Duhamel for experimental complexity evaluations*/

#include   <iostream.h>
#include   <fstream.h>
#include   <conio.h>
#include   <stdlib.h>
#include   <string.h>
#include   <time.h>
#include   <stdio.h>
#include   <dos.h>
#include   <math.h>


// Recursive algorithm with exponential computational complexity O(2^n)
double fibonacci1(double n){
   if (n<2){
     return  n;
   }//end_if
   else{
      return fibonacci1(n-1)+fibonacci1(n-2);
   }//end_else
}//end_fibbonaci1



//O(n) linear algorithm
double fibonacci2(int posicao){
    double i=1, j=0;

    for(int k=1;k<=posicao;k++){
        j=i+j;
        i=j-i;
    }//end_for

   return j;
}//end_fibbonaci2


//O(log n) algorithm
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


/********************************
*********************************
Programa principal***************
*********************************
********************************/
void main(){
     clock_t tInicial;
     //time_t tInicial;
     clrscr();
     cout << "P"  << "\t\t"
          << "t1" << "\n";

      for(int n=1;n<=49;n++){
        cout << n << "\t\t";

        //algoritmo 1, de complexidade exponencial em n
        double aux=n;
        tInicial= clock();
        for(int k=1;k<=10;k++)
           fibonacci1(aux);
        cout << (clock()-tInicial)/CLOCKS_PER_SEC << "\n";
       }//end_for


       cout<< "P"  << "\t\t"
           << "t2" << "\t\t"
           << "t3" << "\t\t"
           << "t4" << "\t\t"
           << "\n";
       for(int n=10;n<=500;n+=10){
          cout << n << "\t\t";

        //algoritmo 2, de complexidade linear
        tInicial= clock();
         for(long k=1;k<=1000000;k++)
           fibonacci2(n);
        cout << (clock()-tInicial)/CLOCKS_PER_SEC << "\t\t";

        //algoritmo 3, de complexidade O(log(n))
        tInicial= clock();
        for(long k=1;k<=1000000;k++)
           fibonacci3(n);
        cout << (clock()-tInicial)/CLOCKS_PER_SEC << "\t\t";


       }//end_for
     exit(0);
}//end_main