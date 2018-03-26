//this is 1/0 knapsack implementation.
//Problem link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
// Status : AC
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;  

int main(){
  int n;
  cin>>n;
  while(n--){
    int m;
    cin>>m;
    int a[m+1];
    for(int i = 1; i <= m;i++){
      cin>>a[i];
    }
    a[0]=0;
    int sum = 0;
    for(int i = 1; i <= m;i++){
      sum += a[i];
    }
    int sum1 = sum;
    sum = sum/2;
    bool dp[m+1][sum+1];  //this dp will store for any dp[i][j], the status if the sum -> j can be obtained by using any of the elements till i
    for(int i = 0; i <= m;i++){
      for(int j  = 0; j <= sum;j++){
        dp[i][j] = false;
      }
    }
    for(int i = 0; i <= m;i++){
      dp[i][0] = true;
    }
    for(int i = 1; i <= sum;i++){
      dp[0][i] = false;
    }
    for(int i = 1; i<= m;i++){
      for(int j = 1; j <= sum ;j++){
        dp[i][j] = dp[i-1][j];
        if(j-a[i] >= 0){
          dp[i][j]  = dp[i][j] || dp[i-1][j-a[i]];
        }
      }
    }
  /*  for(int i = 0; i <= m;i++){
      for(int j = 0; j <= sum;j++){
        if(dp[i][j] == true){
          cout<<"1 ";
        }
        else{
          cout<<"0 ";
        }
      }
      cout<<endl;
    }*/
      int sum2 = 0;
      int k  = sum;
      while(dp[m][k] != true){
        k--;
      }
      sum = k;
      //cout<<sum<<endl;
   for(int i = m ; i >= 1 ;i--){
     if(dp[i-1][sum] == false){
       sum2+= a[i];
       sum = sum - a[i];
     }
   }

  cout<<sum1-(2*sum2)<<endl;
}

}
