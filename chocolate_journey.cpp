//https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/successful-marathon-0691ec04/description/
//status : Accepted

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;

struct node{
  int val;
  int wt;
};
vector <node> adj[100009];

int dist_from_a[100009];
int dist_from_b[100009];

void sp(int src,int f){
  if(f){
    dist_from_a[src] = 0;
    priority_queue < pair< int,int> , vector < pair<int,int>  >, greater < pair<int,int> > > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
      pair<int,int> p = pq.top();
      pq.pop();
      int u = p.second;
      for(int i = 0; i< adj[u].size();i++){
        int v = adj[u][i].val;
        int w = adj[u][i].wt;
        if(dist_from_a[v] > dist_from_a[u] + w){
          //cout<<dist_from_a[v]<<endl;
          dist_from_a[v] = dist_from_a[u]+w;
          pq.push(make_pair(dist_from_a[v],v));
        }
      }
    }
  }
  else{
    dist_from_b[src] = 0;
    priority_queue < pair< int,int> , vector < pair<int,int>  >, greater < pair<int,int> > > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
      pair<int,int> p = pq.top();
      pq.pop();
      int u = p.second;
      for(int i = 0; i< adj[u].size();i++){
        int v = adj[u][i].val;
        int w = adj[u][i].wt;
        if(dist_from_b[v] > dist_from_b[u] + w){
          dist_from_b[v] = dist_from_b[u]+w;
          pq.push(make_pair(dist_from_b[v],v));
        }
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,k,x;
  cin>>n>>m>>k>>x;
  bool avail[n+1];
 for(int i = 0;i <= 100000;i++){
   dist_from_a[i] = 50000001;
   dist_from_b[i] = 50000001;
 }
//  cout<<endl;
  for(int i = 0;i<= n;i++){
    avail[i] = false;
  }
  for(int i = 0; i < k;i++){
    int y;
    cin>>y;
    avail[y] = true;
  }
  for(int i = 1; i<= m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    node n;
    n.val = v;
    n.wt = w;
    adj[u].push_back(n);
    n.val = u;
    adj[v].push_back(n);
  }
  int a,b;
  cin>>a>>b;
  sp(a,1);
  sp(b,0);
  int ans =50000001;
  vector < pair<int,int> > v1;
  vector < pair<int,int> > v2;

  for(int i = 1; i <= n;i++){
    v1.push_back(make_pair(dist_from_a[i],i));
    v2.push_back(make_pair(dist_from_b[i],i));
  }
  sort(v1.begin(),v1.end());
  sort(v2.begin(),v2.end());
  for(int i = 0; i< n;i++){
    pair<int,int> p;
    p  = v2[i];
    if(avail[p.second] && dist_from_b[p.second] <= x  && dist_from_a[p.second] != 50000001  && dist_from_b[p.second] != 50000001 &&  dist_from_a[p.second] + p.first < ans){
      ans = dist_from_a[p.second] + p.first ;
    }
  }
  if(ans !=50000001){
  cout<<ans<<endl;
}
else{
  cout<<"-1"<<endl;
}
}
