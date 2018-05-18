//this is a very nice stack implementation problem
//problem name : Bus of Characters
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector < pair<int,int> > v;
  for(int i = 1; i <= n;i++){
    int x;
    cin>>x;
    v.push_back(make_pair(x,i));
  }
  sort(v.begin(),v.end());
  int count[n+1] = {0};
  string s;
  cin>>s;
  int currentI = 0;
  int currentE = 0;
  int arr[2*n] ;
  stack <int> st;
  int k = 0;
  for(int i = 0; i < 2*n;i++){
    if(s[i] == '0'){
      st.push(v[k].second);
      arr[i] = v[k].second;
      k+=1;

    }
    else{
      int y = st.top();
      st.pop();

      arr[i] = y;
    }
  }
  for(int i = 0; i< 2*n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

