//Gabriel Del Razo

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

#define ERROR 0.0000001

int main(){
  double **A;
  double *x;
  double *xN;
  double lambdaO=1;
  double lambdaN=0;
  double temp;
  int N;
  fstream fin;
  int iteration=1;
  fin.open("power_matrix_test.txt",ios::in);
  fin>>N;


  A = new double *[N];
  //x = new long long [N];
  x = new double [N];
  xN = new double [N];
  for(int i=0;i<N;i++){
    x[i]=1;
    xN[i]=0;
  }
  for (int i=0;i<N;i++){
    A[i]=new double [N];
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

   cout<<"Initial Guess Vector"<<endl;
   for(int i=0;i<N;i++){
     cout<<x[i]<<endl;
   }

   do{
     lambdaO=lambdaN;
     cout<<"Iteration number: "<<iteration<<endl;
     for(int i=0;i<N;i++){
       temp=0.0;
       for(int j=0;j<N;j++){
	 temp=temp+A[i][j]*x[j];
       }
       xN[i]=temp;
     }
     for(int i=0;i<N;i++){
       x[i]=xN[i];
     }
     lambdaN=abs(x[0]);
     for(int i=1;i<N;i++){
       if(abs(x[i])>lambdaN)lambdaN=abs(x[i]);
     }
     for(int i=0;i<N;i++){
       x[i]=x[i]/lambdaN;
     }
     iteration++;
     cout<<"Eigen Value = "<<lambdaN<<endl;
     cout<<"Eigen Vector :"<<endl<<"[";
     for(int i=0;i<N;i++){
       cout<<x[i]<<" ";
     }
   cout<<"]"<<endl;
   }
   while(abs(lambdaN-lambdaO)>ERROR);

   cout<<endl<<"After "<<iteration<<" iterations"<<endl<<"The dominant Eigen Value = "<<lambdaN<<endl;
   cout<<"Eigen Vector :"<<endl<<"[";
   for(int i=0;i<N;i++){
     cout<<x[i];
     if(i!=N-1)cout<<"  ";
   }
   cout<<"]"<<endl;

   
   
   return 0;
}
