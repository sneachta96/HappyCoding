#include<iostream>
#include<vector>


using namespace std;


long long function(int n,int r){

long long int result=1;

if(r>n-r) r=n-r;

for(int i=0;i<r;i++){ result*=n-i; result/=i+1;}

return result;

}


int main(){
  int test;
  cin>>test;
  while(test--){
    int n,k;
    cin>>n>>k;
    if(n == k){
      cout<<"1"<<endl;
    }
    else{
      long long int ans = function(n-1,n-k);
      cout<<ans<<endl;
    }
  }
}
