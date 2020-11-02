#include<iostream>
#include <iostream>
#include <fstream>
#include <cmath>


#define ERROR 0.000001

using namespace std;
//test
void matVet(double **A, double *b,double *S,int n);
double vecMult(double *v1,double *v2,int n);
void vecAdd(double *v1,double *v2,double *S,int n);

int main(){
  double **A;
  double *b;
  double *x;


  int N;
  fstream fin;
  fin.open("q4data.txt",ios::in);
  fin>>N;

  b=new double[N];
  x=new double[N];
  for(int i=0;i<N;i++){
    b[i]=x[i]=0.0;
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

  /*
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
  */


   int iteration=2;
   int it=0;
   while(it<iteration){
     for(int i=0;i<N;i++){
       double sum=0;
       for(int j=0;j<N;j++){
	 if(j==i)continue;
	 sum+=A[i][j]*x[j]-b[i];
       }
       sum=(-1/A[i][i])*sum;
       x[i]=sum;
     }
     it++;
   }

   ofstream file;
   file.open("q4sol2.txt");
   int i=0;
   while (i<N){
     for(int j=0;j<sqrt(N);j++){
       file<<x[i++]<<" ";
     }
     file<<endl;
   }
     
   file.close();
   return 0;
}
