#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;


int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i = 0; i < n;i++){
    cin>>arr[i];
  }
  int dp[n+1][n+1];
  for(int i = 0; i <= n;i++){
    for(int j= 0; j <= n;j++){
      dp[i][j]  = 0;
    }
  }
 for(int i  = 0; i < n;i++){
    dp[0][i] = arr[i];
  }
 for(int i  = 1; i < n;i++ ){
    for(int j = 0; j <= n-i;j++){
      dp[i][j] = dp[i-1][j]^dp[i-1][j+1];
    }
  }
  for(int i = 1; i < n;i++){
    for(int j = 0; j <= n-i;j++){
      dp[i][j] = max(dp[i][j],max(dp[i-1][j],dp[i-1][j+1]));
    }
  }
  int q;
  cin>>q;
  int l,r;
  while(q--){
    cin>>l>>r;
    l = l - 1;
    int len = r-l-1;
    cout<<dp[len][l]<<endl;
  }
}
