#include <iostream>
#include <cmath>
using namespace std;

double f(double x);
double df(double x);

int main(){
  double xO;
  double x=0.5;
  double precision=0.001;
  xO=x;
  int i=1;
  while(abs(f(x))>precision){
    cout<<"Iteration # "<<i<<endl;
    cout<<"X: "<<x<<endl;
    cout<<"f(x): "<<f(x)<<endl;
    x=xO-(f(xO)/df(xO));
    xO=x;
    i++;
  }
  cout<<"Iteration # "<<i<<endl;
  cout<<"X: "<<x<<endl;
  cout<<"f(x): "<<f(x)<<endl;
 
  return 0;
}

double f(double x){
  return 3*pow(x,3)-15*cos(x)+3*log(x)+2*sin(x);
}

double df(double x){
  return 15*sin(x)+2*cos(x)+9*pow(x,2)+(3/x);
}
