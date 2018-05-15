#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;
const double val  = 1e-6;
int main(){
  int test;
  cin>>test;
  while(test--){
    int n,s,y;
    cin>>n>>s>>y;
    int v[n];
    int d[n];
     int p[n];
    for(int i =0; i < n;i++){
      cin>>v[i];
    }
    for(int i = 0; i < n;i++){
      cin>>d[i];
    }
    for(int i = 0; i < n;i++){
      cin>>p[i];
    }
    int c[n];
    for(int i = 0; i < n;i++){
      cin>>c[i];
    }
    double t = (1.0*y)/(1.0*s);
    double now = 0;
    for(int i = 0;i < n;i++){
      if(d[i] == 0)   //moving in the negavtive direction
      {
        double a = (p[i]+c[i]) - (now*v[i]);
        double b = (p[i]+c[i]) - ((now+t)*v[i]);
        if(a >= val && b - c[i] - val <= 0){
          now += abs(a)/v[i];
        }
      }
      else{
        double a = (p[i]-c[i]) + now * v[i];
        double b = (p[i]-c[i]) + (now+t)*v[i];
        if(a <= -val && b + c[i] + val >= 0){
          now += abs(a)/v[i];
        }
      }
      now += t;
    }
    cout.precision(2);
    cout<<fixed<<now<<endl;
  }
}
