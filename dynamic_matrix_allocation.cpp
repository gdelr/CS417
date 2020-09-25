#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
  double *b;
  double *x;
  double **A;
  double TwoNorm, InfNorm, L1Norm, MatInfNorm, sum = 0.0;
  int N;
  fstream fin;
  fin.open("sample_mat_format.txt",ios::in);
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

   cout<<"Norm values for this problem"<<endl;
   //two norm
   for(int i=0;i<N;i++){
     TwoNorm = TwoNorm + pow(b[i],2.0);
   }
   TwoNorm = sqrt(TwoNorm);
   cout<<"\tTwo Norm of b[] = "<<TwoNorm<<endl;

   //Infinity norm
   for(int i=0;i<N;i++){
     if(fabs(b[i]>InfNorm))
       InfNorm = fabs (b[i]);
   }
   cout<<"\tInfinity Norm of b[] = "<<InfNorm<<endl;

   //one norm
   for(int i=0;i<N;i++){
     L1Norm =L1Norm + fabs(b[i]);
   }
   cout<<"\tthe L1 Norm of b[] =" << L1Norm<<endl;
   cout<<endl;

   //infinity norm of matrix A
   cout<<"the infinity norm of marix A" <<endl;
   for(int row=0;row<N;row++){
     for(int col=0;col<N;col++){
       sum=sum +fabs(A[row][col]);
     }
     if(sum>MatInfNorm){
       MatInfNorm=sum;
     }
     sum=0.0;
   }
   cout<<"\tMatrix L1 norm = "<<MatInfNorm<<endl;

   return 0;
   
   
}
