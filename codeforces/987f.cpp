//The graph generated has an edge between any two vertices x and y if (x bitwise AND y ) = 0;
#include<iostream>
#include<vector>

using namespace std;

const int N = (1<<22)+5;
const int S = 2*N;
bool input[N];
bool used[S];
int ans ;
int q[S];
int top ;
int n;
void solve(int x){
  top = 0;
  q[top++] = x;
  used[x] = 1;
  for(int i = 0; i < top;i++){
    x = q[i];
    if(x < ( 1<<n )){
      if(!used[x+(1<<n)]){
        //cout<<x+(1<<n)<<" is here "<<endl;
        used[x + (1<<n)] = 1;
        q[top++] = x + (1<<n);
      }
    }
    else{
      int y = (1 << (n+1)) - 1 -x;
      //cout<<"hey"<<y<<endl;
      if(!used[y] && input[y]){
        used[y] = 1;
        q[top++] = y;
      }
      for(int i = 0; i < n;i++){
        y = x|(1<<i);
        if(!used[y]){
          used[y] = 1;
          q[top++] = y;
        }
      }
    }
  }
}


int main(){
  int m;
  cin>>n>>m;
  for(int i = 0; i < m;i++){
    int x;
    cin>>x;
    input[x] = 1;
  }
  for(int i = 0; i < (1<<n);i++){
    if(input[i] && !used[i]){
    //  cout<<i<<endl;
      solve(i);
      ans++;
    }
  }
  cout<<ans<<endl;
}
