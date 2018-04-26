//problem link : https://www.hackerearth.com/fr/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/minimizing-path-cost/
//Dijkstra's implementaion
//A easy and direct problem
//Status : Accepted :D

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<map>
#include<cstring>
#include<climits>

using namespace std;

struct node {
  int val;
  int wt;
};
int n,m;
int djk(vector<node> adj[],int src,int dest){
  int dist[n+1];
  for(int i = 1; i <= n;i++){
    dist[i] = 1000000;
  }
  dist[src] = 0;
  priority_queue < pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > pq;
  pq.push(make_pair(0,src));
  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    for(int i = 0; i < adj[u].size();i++){
      int v = adj[u][i].val;
      int weight = adj[u][i].wt;
      //cout<<v<<" "<<weight<<endl;
      if(dist[v] > dist[u]+weight){
        //cout<<"he"<<endl;
        dist[v] = dist[u]+weight;
        pq.push(make_pair(dist[v],v));
      }
    }
  }

  return dist[dest];

}
int main(){
  cin>>n>>m;
  vector<node> adj[n+1];
  map<string,int> mp;
  for(int i = 1;  i <= n;i++){
    string s;
    cin>>s;
    mp.insert(make_pair(s,i));
  }
  for(int i = 1; i <= m;i++){
    string  a,b;
    int w;
    cin>>a>>b>>w;
    int u = mp[a];
    int v = mp[b];
    node n ;
    n.val = v;
    n.wt = w;
    adj[u].push_back(n);
    n.val = u;
    adj[v].push_back(n);
  }
  int q;
  cin>>q;
  while(q--){
    string a,b;
    cin>>a>>b;
    int src = mp[a];
    int dest = mp[b];
    //cout<<src<<" "<<dest<<endl;
    cout<<djk(adj,src,dest)<<endl;
  }
}
