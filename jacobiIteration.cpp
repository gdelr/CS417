#include<iostream>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
//test
void matVet(double **A, double *b,double *S,int n);
double vecMult(double *v1,double *v2,int n);
void vecAdd(double *v1,double *v2,double *S,int n);

int main(){
  double **A;
  double *b;
  double *xO;
  double *xN;
  double **L;
  double **U;
  double **C;

  int N;
  fstream fin;
  fin.open("jacobiMAT.txt",ios::in);
  fin>>N;

  b=new double[N];
  xO=new double[N];
  xN=new double[N];
  for(int i=0;i<N;i++){
    b[i]=xO[i]=xN[i]=0.0;
  }
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
   //factoring into L and U
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

void matVet(double **A, double *b,double *S,int n){
  for(int row=0;row<n;row++){
    double sum=0.0;
    for(int col=0;col<n;col++){
      sum+=A[row][col]*b[col];
    }
    S[row]=sum;
  }
}
double vecMult(double *v1,double *v2,int n){
  double sum=0.0;
  for(int i=0;i<n;i++){
    sum=sum+v1[i]*v2[i];
  }
  return sum;
}
void vecAdd(double *v1,double *v2,double *S,int n){
  for(int i=0;i<n;i++){
    S[i]=v1[i]+v2[i];
  }
}
