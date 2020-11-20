#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main (){
  double *b;
  double *x;
  double **A;
  int N;
  fstream fin;
  
  fin.open("SOR.txt",ios::in);
  fin>>N;

  A=new double*[N];
  b=new double [N];
  x=new double [N];
  for(int i=0;i<N;i++){
    b[i]=x[i]=0.0;
    A[i]=new double[N];
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

   //sor
   double w=1.25;
   double *xNew;
   xNew=new double[N];
   int interNum=4;
   while (interNum>0){
     for(int i=0;i<N;i++){
       xNew[i]=0.0;
     }
     for(int i=0;i<N;i++){
       xNew[i]=b[i];
       for(int j=0;j<i;j++){
	 xNew[i]=xNew[i]-A[i][j] * xNew[j];
       }
       for(int j=i+1;j<N;j++){
       xNew[i]=xNew[i]-A[i][j]*x[j];
       }
       xNew[i]=xNew[i]/A[i][i];
     }
     for(int i=0;i<N;i++){
       xNew[i]=(1.0-w)*x[i]+w*xNew[i];
     }
     interNum--;
   }

   cout<<"Vector x:"<<endl;
   for(int i=0;i<N;i++){
     cout<<xNew[i]<<" "<<endl;
   }
   return 0;
}
