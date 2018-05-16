#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef unsigned long long int ull;

int main(){
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int test;
  cin>>test;
  while(test--){
    ull p,q,b;
    cin>>p>>q>>b;
    ull y = __gcd(p,q);
    p/=y;
    q/=y;
    b = __gcd(q,b);
    while(b!= 1){
      while(q%b==0){
        q/=b;
      }
      b = __gcd(q,b);
    }
    if(q==1){
      cout<<"Finite"<<endl;
    }
    else{
      cout<<"Infinite"<<endl;
    }
  }
}
