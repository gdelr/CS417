#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double matrixMultiplication(double **A,double *b,int N);

int main(){
  double *b;
  double *x;
  double **A;
  int N;
  fstream fin;
  fin.open("power_matrix_test.txt",ios::in);
  fin>>N;

  b = new double [N];
  x = new double [N];
  for(int i=0;i<N;i++){
    b[i]=0.0;
    x[i]=0.0;
  }
  A = new double*[N];
  for (int i=0;i<N;i++){
    A[i]=new double [N];
  }
  for(int row=0;row<N;row++){
    for(int col=0;col<N;col++){
      fin>>A[row][col];
    }
  }
  for (int i=0;i<N;i++){
    fin>>b[i];
  }
  fin.close();

  cout<<"Problem size N= "<<N<<endl;
  cout<<"Matrix A = "<<endl;
   for(int row=0;row<N;row++){
    for(int col=0;col<N;col++){
      cout<<A[row][col]<<" ";
    }
    cout<<endl;
   }
   cout<<"Forcing vector b"<<endl;
   for(int i=0;i<N;i++){
     cout<<b[i]<<endl;
   }

   matrixMultiplication(A,b,N);
   
   return 0;
}

double matrixMultiplication(double **A, double *b,int N){
  cout<<"Problem size N= "<<N<<endl;
  cout<<"Matrix A = "<<endl;
   for(int row=0;row<N;row++){
    for(int col=0;col<N;col++){
      cout<<A[row][col]<<" ";
    }
    cout<<endl;
   }
   return 1.0;
}
