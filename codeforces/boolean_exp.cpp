//https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/boolean-expressions-2/description/


#include<iostream>
#include<vector>
#include<cstring>
 
using namespace std;
typedef long long int ll;
const ll MOD = 1000000009;
int main(){
  int op[3] = {0};
  string s;
  cin>>s;
  string o;
  cin>>o;
  ll dp[310][310][2];
  memset(dp,0,sizeof(dp));
 
  for(int i = 0; i < s.length();i++){
    if(s[i] == '1'){
      dp[i+1][i+1][1] = 1;
    }
    else {
      dp[i+1][i+1][0] = 1;
    }
  }
  int n =s.length();
  for(int l = 2; l<= n;l++){
    for(int i = 1;i <= n-l+1;i++){
      int j = i+l-1;
      for(int k  = i ; k < j;k++){
         if(o[k-1] == 'a'){
           dp[i][j][0] = (dp[i][j][0] + (((dp[i][k][0]*dp[k+1][j][1])%MOD + (dp[i][k][1]*dp[k+1][j][0])%MOD)%MOD + (dp[i][k][0]*dp[k+1][j][0])%MOD)%MOD)%MOD;
           dp[i][j][1] = (dp[i][j][1] + (dp[i][k][1]*dp[k+1][j][1])%MOD)%MOD;
         }
         else if(o[k-1] == 'o'){
           dp[i][j][1] = (dp[i][j][1] + (((dp[i][k][0]*dp[k+1][j][1])%MOD + (dp[i][k][1]*dp[k+1][j][0])%MOD)%MOD + (dp[i][k][1]*dp[k+1][j][1])%MOD)%MOD)%MOD;
           dp[i][j][0] = (dp[i][j][0] + (dp[i][k][0]*dp[k+1][j][0])%MOD)%MOD;
         }
         else{
           dp[i][j][0] = (dp[i][j][0] + ((dp[i][k][1]*dp[k+1][j][1])%MOD + (dp[i][k][0]*dp[k+1][j][0])%MOD)%MOD)%MOD;
           dp[i][j][1] = (dp[i][j][1] + ((dp[i][k][1]*dp[k+1][j][0])%MOD + (dp[i][k][0]*dp[k+1][j][1])%MOD)%MOD)%MOD;
         }
 
    }
    }
  }
 
 int q;
 cin>>q;
 while(q--){
   int l ,r;
   cin>>l>>r;
  string s;
  cin>>s;
  if(s == "false"){
    cout<<dp[l][r][0]<<endl;
  }
  else{
    cout<<dp[l][r][1]<<endl;
  }
 }
}
