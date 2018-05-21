//Problem link : https://www.codechef.com/problems/CHEFTRVL
//A simple problem on dfs


#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;
int arr[100009];
vector < int > adj[100009];
void dfs(int a, int p , int d){
   for(int i = 0; i < adj[a].size();i++){
     if(adj[a][i] != p){
       arr[adj[a][i]]^=(1-d);
       dfs(adj[a][i],a,1-d);
     }
   }
}


int main(){
  int test;
  cin>>test;
  while(test--){
    int n;
    cin>>n;
    for(int i = 0; i <= 100000;i++){
      adj[i].clear();
    }
    for(int i = 0; i < n-1;i++){
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    for(int i = 1; i <= n;i++){
      cin>>arr[i];
      arr[i]<<=1;
    }

    dfs(1,-1,0);
    long long int a = 0, b = 0;
    for(int i = 1; i<= n;i++){
      if(__builtin_popcount(arr[i])%2){
        a++;
      }
      else{
        b++;
      }
    }
    cout<<a*b<<endl;



  }
}
