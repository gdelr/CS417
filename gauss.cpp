#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
  double *b;
  double *x;
  double **A;
  int N;
  fstream fin;
  fin.open("q4data.txt",ios::in);
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
    cout<<b[row]<<endl;
   }

   //=====================gauss algorithm===============================
   for (int i=0;i<N;i++){
     //search for max in current column
     double max = abs(A[i][i]);
     int maxRow = i;
     for (int k=i+1;k<N;k++){
       if(abs(A[k][i]) > max){
	 max = abs(A[k][i]);
	 maxRow = k;
	 
       }
     }

     //swap max row with curretn row
     for (int k=i;k<N+1;k++){
       double temp = A[maxRow][k];
       A[maxRow][k] = A[i][k];
       A[i][k]=temp;
     }
     
     double tempB = b[maxRow];
     b[maxRow]=b[i];
     b[i]=tempB;
    
     //Make all rows below this one 0 in current colum
     for(int k=i+1;k<N;k++){
       double c = -A[k][i]/A[i][i];
       b[k]+=c * b[i];
       for (int j=i;j<N+1;j++){
	 if (i==j){
	   A[k][j]=0;
	 }else{
	   A[k][j] += c * A[i][j];
	   
	 }
       }
     }
   }
   //backwards solve
   for(int i=N-1;i>=0;i--){
     x[i]=b[i]/A[i][i];
     for(int k=i-1;k>=0;k--){
       b[k]-=A[k][i]*x[i];
     }
   }

   cout<<"After swap"<<endl;
   cout<<"Matrix A = "<<endl;
   for(int row=0;row<N;row++){
    for(int col=0;col<N;col++){
      cout<<A[row][col]<<" ";
    }
    cout<<b[row]<<endl;
   }
   
   cout<<"The solution:"<<endl;
   for(int i=0;i<N;i++){
     if(abs(x[i])<1e-10) x[i]=0.0;
     cout<<x[i]<<" ";
   }
   cout<<endl;
   
   return 0;

}
