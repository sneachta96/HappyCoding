//do again // Route planning shortest path // hackerearth

#include<bits/stdc++.h>


using namespace std;
#define INF 1000000005
int n,m,x,y,q,t,v[100005],ans[100005];
vector<int> p[100005];
vector< pair<int,int> > g[100005];
set <pair<int,int> > s;

void find(int node, int dist){
  ans[node] = dist;
  v[node] = 1;
  for( int j = 0; j < g[node].size();j++){
    pair<int,int> i = g[node][j];
    int next = p[i.first][(i.second+1)%(p[i.first].size())];
    if(v[next]){
      continue;
    }
    int ndist = ((dist-i.second+p[i.first].size()-1)/(p[i.first].size())) *(p[i.first].size()) + i.second+1;
    if(ndist < ans[next]){
      s.erase(make_pair(ans[next],next));
      ans[next] = ndist;
      s.insert(make_pair(ndist,next));
    }
  }
  if(s.size()){
    pair<int,int> next = *(s.begin());
    s.erase(s.begin());
    find(next.second,next.first);
  }
}

int main(){
  cin>>n>>m;
  for(int i = 1; i <= m;i++){
    cin>>t;
    for(int j = 0; j < t;j++){
      cin>>x;
      p[i].push_back(x);
      g[x].push_back(make_pair(i,j));
    }
  }
  for(int i = 1; i <= n;i++){
    ans[i] = INF;
    s.insert(make_pair(ans[i],i));
  }
  for(int i = 2; i <= n;i++){
    ans[i] = INF;
    s.insert(make_pair(INF,i));
  }
  find(1,0);
  for(int i = 2; i <= n;i++){
    if(ans[i] ==INF){
      cout<<"-1 ";
    }
    else{
      cout<<ans[i]<<" ";
    }
  }
}
