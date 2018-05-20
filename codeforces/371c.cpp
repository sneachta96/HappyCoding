//Infinite loop when mid becomes equal to low and that is a valid situation. Correction : Changing (high+low)/2 to (high+low+1)/2
//Handling the case when binary search doesnot give a valid solution. It would stop at low = 1. So, when we come out of the loop
//its important to check that valid(low) is still true.



#include<iostream>
#include<vector>

using namespace std;

long long int max(long long int a, long long int b){
  if(a >= b){
    return a;
  }
  else{
    return b;
  }
}
int pa,pb,pc;
int b,s,c;
long long int r;
int aa,bb,cc;
bool valid(long long int m){
   long long int b_required = max(0,(m*b - aa));
   long long int s_required = max(0,(m*s - bb));
   long long int c_required  = max(0,(m*c - cc));
  long long int cost  = (b_required*pa)+(s_required*pb)+ (c_required*pc);
  if(cost <= r){
    return true;
  }
  else{
    return false;
  }


}

int main(){
  string str;
  cin>>str;
  b = 0;
  c = 0;
  s = 0;
  for(int i = 0;i  <str.length();i++){
    if(str[i] == 'B'){
      b++;
    }
    else if(str[i] == 'S'){
      s++;
    }
    else{
      c++;
    }
  }
 //cout<<b<<" "<<s<<" "<<c<<endl;
    long long int ans = 0;
      cin>>aa>>bb>>cc;
  while( aa >= b && bb >= s && cc >= c ){
    aa = aa-b;
    bb = bb-s;
    cc = cc-c;
    ans++;
  }
 //cout<<ans<<endl;
  cin>>pa>>pb>>pc;

  cin>>r;
  long long int low = 1;
  long long int high = 1000000000000;
  while(low < high){
   //cout<<low<<" "<<high<<endl;
    long long int mid = (low+high+1)/2;
  //  cout<<mid<<endl;
    if(valid(mid)){
      low = mid;
    }
    else{
      high = mid-1;
    }
  }
  if(valid(low)){
      ans = ans + low;
  }

  cout<<ans<<endl;
}
