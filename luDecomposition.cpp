#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
  double **A;
  double **L;
  double **U;
  int N;
  fstream fin;
  fin.open("LU.txt",ios::in);
  fin>>N;

  A = new double*[N];
  L = new double*[N];
  U = new double*[N];
  
  for (int i=0;i<N;i++){
    A[i]=new double [N];
    L[i]=new double [N];
    U[i]=new double [N];
    
  }
  for(int row=0;row<N;row++){
    for(int col=0;col<N;col++){
      fin>>A[row][col];
    }
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

   // LU////////////////////////////////////
   // Decomposing matrix into upper and lower triangular matrix
   
   for(int i=0;i<N;i++){
     //upper triangular
     for(int k=i;k<N;k++){
       //summation of L(i,j)* U(j,k)
       int sum=0;
       for(int j=0;j<i;j++){
	 sum+=(L[i][j] * U [j][k]);
       }
       //evaluating U(i,k)
       U[i][k]=A[i][k]-sum;
     }

     //lower triangular
     for(int k=i;k<N;k++){
       if(i==k)
	 L[i][i]=1;
       else{
	 //summation of L(k,j)*U(j,i)
	 int sum =0;
	 for(int j=0;j<i;j++){
	   sum+=(L[k][j]*U[j][i]);
	 }
	 //Evaluating L(k,i)
	 L[k][i]=(A[k][i]-sum)/U[i][i];
       }
     }
   }
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
   return 0;
}
