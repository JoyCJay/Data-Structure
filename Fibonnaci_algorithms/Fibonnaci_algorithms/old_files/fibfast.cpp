#include   <math.h>
#include   <string.h>
#include   <conio.h>
#include   <iostream.h>
#include   <fstream.h>
#include   <stdlib.h>
#include   <string.h>
#include   <time.h>
#include   <stdio.h>
#include   <dos.h>



double fibonacci4(int n)
{
  double static sr5, phi = 0.0;
  double static f[9] = {0.0, 1.0, 1.0, 2.0, 3.0, 5.0, 8.0, 13.0, 21.0};

  if (n <= 0)  return 0.0;
  if (n <= 8)  return f[n];
  if (phi == 0.0) {
    sr5 = sqrt( 5.0);
    phi = 0.5 + sr5 / 2.0;
  }
  return  floor( 0.5 + pow( phi, n) / sr5);
}//end_fibonacci4

/* --------------------------------------------------------------------- */
/* Find smallest n for which ffib(n) is not exactly correct */
int test( void)
{
  int n;
  for (n = 2; ; n++) {
    if (fibonacci4( n) != (fibonacci4( n - 1) + fibonacci4( n - 2))) {
      return 0;
    }//end_if
    else {
      return 1;
    }//end_else
  }//end_for
}//end_test

/* --------------------------------------------------------------------- */
int main(void) {
  time_t tInicial;
  for(int n=1;n<=48;n++){
   if(test()){
    tInicial= time(NULL);
    cout << fibonacci4(n) << "\t\t\t";
    cout << (difftime(time(NULL), tInicial)) << "\n";
    }//end_if
   else
    cout << "não calcula exato este número da série";
  }//end_for
}



