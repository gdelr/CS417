#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc,char* argv[]){
  int n=stoi(argv[1]);
  srand(time(NULL));
  double *b=new double[n];
  double *x=new double[n];
  double **A;

  for(int i=0;i<n;i++){
    b[i]=0.0;
    x[i]=0.0;
  }
  A=new double *[n];
  for(int i=0;i<n;i++){
    A[i]=new double [n];
  }
  //generating solution 
  for(int i=0;i<n;i++){
    x[i]=rand()%10;
  }
  //generating A
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      A[i][j]=rand()%10;
    }
  }
  //generating b
  for(int row=0;row<n;row++){
    double sum=0.0;
    for(int col=0;col<n;col++){
      sum+=A[row][col]*x[col];
    }
    b[row]=sum;
  }
  ofstream fout;
  fout.open("matrix.txt");
  fout<<n<<endl;

  for(int row=0;row<n;row++){
    for(int col=0;col<n;col++){
      fout<<A[row][col]<<" ";
    }
    fout<<endl;
  }

  for(int i=0;i<n;i++){
    fout<<b[i]<<" ";
  }
  cout<<"x:"<<endl;
  for(int i=0;i<n;i++){
    cout<<x[i]<<" ";
  }
  cout<<endl;
  fout.close();
  return 0;
  
}
