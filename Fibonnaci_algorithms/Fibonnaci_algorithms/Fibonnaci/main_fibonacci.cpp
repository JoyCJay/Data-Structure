/* Compute Fibonacci series by Andréa Duhamel for experimental complexity evaluations*/

#include <iostream>  // std::cout
#include <fstream>   // std::ifstream
#include <cstdio>    // std::cout
#include <cstdlib>
#include <string>
#include <ctime>


class Serie
{
  private:

  public:
	  // Class Constructeur
	  Serie(){ }
	  // Class Destructeur 
	  ~Serie(){ }
	  // Recursive algorithm with exponential computational complexity O(2^n)
	  int fibonacci1(int n) {
		  if (n < 2) { return  n; }
		  else { return fibonacci1(n - 1) + fibonacci1(n - 2); }
	  }

	  //O(n) linear algorithm
	  int fibonacci2(int n){
		  int i = 1, j = 0;

		  for (int k = 1; k <= n; k++){
			  j = i + j;
			  i = j - i;
		  }//end_for

		  return j;
	  }//end_fibbonaci2


	  //O(log n) algorithm
	  int fibonacci3(int n){
		  int i = 1, j = 0, k = 0, h = 1, t;
		  while (n>0){
			  if ((n % 2) != 0){
				  t = j*h;
				  j = i*h + j*k + t;
				  i = i*k + t;
			  }//end_if
			  t = h*h;
			  h = 2 * k*h + t;
			  k = k*k + t;
			  n = n / 2;
		  };//end_while
		  return j;
	  }//end_fibonacci3
};



/*******************************************************************************
******************************   Main program   ********************************
*******************************************************************************/
// Input parameter : the position of the fibonacci series to be computed
int main( int argc, char** argv ){
     clock_t	tInicial;		// variable used to compute the initial instant t of an algorithm
	 Serie		S;			// object of type Serie
	 int		position;		// position to be computed
  
	 if (argc > 1) {

		 position = atoi(argv[1]);
		 //position = 40;

		 std::cout << "-- Exponential algorithm --\n";
		 tInicial = clock();
		 std::cout << " F(" << position << ") = " << S.fibonacci1(position) << "\t";
		 std::cout << "Running time : " << (double)((clock() - tInicial) / CLOCKS_PER_SEC) << "s\t" << (double)((clock() - tInicial) / (CLOCKS_PER_SEC / 1000)) << "ms\n\n";
       
		 std::cout << "-- Linear algorithm --\n";
         tInicial= clock();
		 std::cout << " F(" << position << ") = " << S.fibonacci2(position) << "\t";
		 std::cout << "Running time : " << (double)((clock() - tInicial) / CLOCKS_PER_SEC) << "s\t" << (double)((clock() - tInicial) / (CLOCKS_PER_SEC / 1000)) << "ms\n\n";

		 std::cout << "-- Superlinear algorithm --\n";
         tInicial= clock();
		 std::cout << " F(" << position << ") = " << S.fibonacci3(position) << "\t";
		 std::cout << "Running time : " << (double)((clock() - tInicial) / CLOCKS_PER_SEC) << "s\t" << (double)((clock() - tInicial) / (CLOCKS_PER_SEC / 1000)) << "ms\n\n";
		 
       }//end_for
    
	 return 0;
}