#include <iostream>
#include <fstream>
#include <fstream>
#include <cmath>
using namespace std;



int main(){
  double **A;
  double **L;
  double **U;
  double  *Y;
  double  *X;
  double  *B;
  int N;
  fstream fin;
  fin.open("q3data.txt",ios::in);
  fin>>N;

  A = new double*[N];
  L = new double*[N];
  U = new double*[N];
  Y = new double [N];
  X = new double [N];
  B = new double [N];
  
  for (int i=0;i<N;i++){
    A[i]=new double [N];
    L[i]=new double [N];
    U[i]=new double [N];
  }

  for(int i=0;i<N;i++){
    B[i]=0.0;
    X[i]=0.0;
    Y[i]=0.0;
  }
  for(int row=0;row<N;row++){
    for(int col=0;col<N;col++){
      fin>>A[row][col];
      L[row][col]=0.0;
      U[row][col]=0.0;
    }
  }
  for(int i=0;i<N;i++){
    fin>>B[i];
  }
  fin.close();
  //output of original problem
  /*
  cout<<"Problem size N= "<<N<<endl;
  cout<<"Matrix A = "<<endl;
   for(int row=0;row<N;row++){
    for(int col=0;col<N;col++){
      cout<<A[row][col]<<" ";
    }
    cout<<endl;
   }
   cout<<endl<<"B"<<endl;
   for(int i=0;i<N;i++){
     cout<<B[i]<<endl;
   }
  */

   // LU////////////////////////////////////
   // Decomposing matrix into upper and lower triangular matrix
   double sum=0;
   for(int k=0;k<N;k++){
     U[k][k]=1;
     for(int i=k;i<N;i++){
       sum=0;
       for(int p=0;p<=k-1;p++){
	 sum+=L[i][p]*U[p][k];
       }
       L[i][k]=A[i][k]-sum;
     }
     for(int j=k+1;j<N;j++){
       sum=0;
       for(int p=0;p<=k-1;p++){
	 sum+=L[k][p]*U[p][j];
       }
       U[k][j]=(A[k][j]-sum)/L[k][k];
     }
   }
   /*
   //output of LU
   cout<<"Matrix L = "<<endl;
   for(int row=0;row<N;row++){
    for(int col=0;col<N;col++){
      cout<<L[row][col]<<" ";
    }
    cout<<endl;
   }
   cout<<"Matrix U = "<<endl;
   for(int row=0;row<N;row++){
    for(int col=0;col<N;col++){
      cout<<U[row][col]<<" ";
    }
    cout<<endl;
   }
   */
   //finding Y
   Y[0]=B[0]/L[0][0];
   for(int m=1;m<N;m++){
     sum=0;
     for(int i=0;i<m;i++){
       sum+=L[m][i]*Y[i];
     }
     Y[m]=(B[m]-sum)/L[m][m];
   }
   //finding x
   X[N-1]=Y[N-1];
   for(int k=N-2;k>=0;k--){
     sum=0;
     for(int c=k+1;c<N;c++){
       sum+=U[k][c]*X[c];
     }
     X[k]=Y[k]-sum;
   }
   
  ofstream file;
  file.open("q3sol.txt");

  int i=0;
  while (i<N){
    for(int j=0;j<sqrt(N);j++){
      file<<X[i++]<<" ";
    }
    file<<endl;
  }
  
   file.close();
   return 0;
}

