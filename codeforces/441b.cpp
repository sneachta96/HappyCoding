//An interesting extension of the problem would be if we could collect fruits from prevoius T days. In this case,we could 
//simply keep track of prev of each day. While calculating the value of y, we need to keep moving backwards in this array 
//till the value is positive, and also making the prev[i] for each of them 0. Finally , when we are moving to another day,
// we need to update the prev[curr_day].

#include<iostream>
#include<vector>

using namespace std;


int main(){
  int n,v;
  cin>>n>>v;
  int a[n],b[n];
  for(int i  = 0; i < n;i++){
    cin>>a[i]>>b[i];
  }
  int prev = 0;
  int cur = 0;
  int ans = 0;
  for(int i = 1; i<= 3001;i++){
    cur =0;
    for(int j = 0 ; j < n;j++){
      if(a[j] == i){
        cur+= b[j];
      }
    }
    //cout<<" cur is"<<cur<<endl;
    if(cur+prev <= v){
      ans+= (cur+prev);
      prev = 0;
    }
    else{
      ans += v;
      int  y = v - prev;
      if(y < 0){
        y = 0;
      }
        prev = cur - y;
      }
  }
  cout<<ans<<endl;
}
