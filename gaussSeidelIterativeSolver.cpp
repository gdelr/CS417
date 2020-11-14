#include  <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

int main(){
  double *b;
  double *x;
  double *xOLD;
  double **A;
  int N,flag=0;
  double tol=0.001;
  double y;
  fstream fin;
  fin.open("LU.txt",ios::in);
  fin>>N;

  A=new double*[N];
  b=new double[N];
  x=new double[N];
  xOLD=new double[N];
  for(int i=0;i<N;i++){
    b[i]=x[i]=xOLD[i]=0.0;
    x[i]=0.0;
    A[i]=new double [N];
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      fin>>A[i][j];
    }
  }
  for(int i=0;i<N;i++){
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
   cout<<"Vector b:"<<endl;
   for(int i=0;i<N;i++){
     cout<<b[i]<<" "<<endl;
   }

   //makes diagonally dominant
   for(int i=0;i<N;i++){
     for(int k=i+1;k<N;k++){
       if(abs(A[i][i])<abs(A[k][i])){
	 double temp = b[i];
	 b[i]=b[k];
	 b[k]=temp;
	 for(int j=0;j<=N;j++){
	   temp=A[i][j];
	   A[i][j]=A[k][j];
	   A[k][j]=temp;
	 }
       }
     }
   }

   //gauss Seidel Solver
   do{
     for(int i=0;i<N;i++){
       y=x[i];
       x[i]=(b[i]/A[i][i]);
       for(int j=0;j<N;j++){
	 if(j==i)continue;
	 x[i]=x[i]-((A[i][j]/A[i][i])*xOLD[j]);
	 xOLD[i]=x[i];
       }
       if(abs(x[i]-y)<=tol)flag++;
     }
     }while(flag<N);
   cout<<endl<<"Vector x:"<<endl;
   for(int i=0;i<N;i++){
     cout<<x[i]<<" "<<endl;
   }

  return 0;
}
