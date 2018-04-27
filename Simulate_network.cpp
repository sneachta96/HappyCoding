//Problem Statement : https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/efficient-network/
//Kruskal's ALgorithm 
//Status : Accepted :D

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#define MAX 100001
using namespace std;
int n,m;
int parent[MAX];
int arr[MAX];   //stores the size of the disjoint set
int find_parent(int i){
  if(parent[i] == i){
    return i;
  }
  else{
    int j = find_parent(parent[i]);
    parent[i] = j;  // Path compression 
    return j;
  }
}

int join(int i, int j){
  int a = find_parent(i);
  int b = find_parent(j);
  if(arr[a] == arr[b]){
    parent[b] = a;
    arr[a] += arr[b];
  }
  else if(arr[a] > arr[b]){
    parent[a] = b;
    arr[b] += arr[a];
  }
  else{
    parent[b] = a;
    arr[a] += arr[b];
  }
}

unsigned long long int  kruskal_s (priority_queue < pair <int, pair<int,int>  >, vector < pair <int, pair<int,int> > >  , greater < pair < int, pair<int,int> > > > pq ,  vector <int> c ){
  unsigned long long int mm = 0;
  priority_queue < pair <int, pair<int,int>  >, vector < pair <int, pair<int,int> > >  , greater < pair < int, pair<int,int> > > > qq;
  int k = 0;
  for(int i = 1; i <= MAX;i++){
    parent[i] = i;
    arr[i] = 1;
  }
  while(!pq.empty()){
    pair <int, pair<int,int> > p = pq.top();
    pq.pop();
    int u = p.second.first;
    int v = p.second.second;

    int up = find_parent(u);
    int vp = find_parent(v);
    if(up != vp){
      //cout<<u<<" "<<v<<" "<<p.first<<endl;
      join(u,v);
      qq.push(make_pair(-p.first,make_pair(u,v)));
    }
  }
  while(!qq.empty()){
    pair<int, pair<int,int> > p = qq.top();
    qq.pop();
    
    if( c.size() > 0 && c[k] < -p.first){   // Not checking if C is empty can give Segmentation Fault ; Q can be zero as well
      mm = mm + c[k];
      k = k +1;
    }
    else{
      mm = mm - p.first;
    }
  }
  return mm;
}

int main(){

  cin>>n>>m;
  priority_queue < pair <int, pair<int,int> >  , vector < pair <int, pair<int,int> > >  , greater < pair < int, pair<int,int> > > > pq;
  for(int i = 0; i < m;i++){
    int u,v,d;
    cin>>u>>v>>d;
    pq.push(make_pair(d,make_pair(u,v)));
  }
  int q;
  cin>>q;
  vector <int> c;
  for(int i = 0;i < q;i++){
    int x;
    cin>>x;
    c.push_back(x);
  }
  sort(c.begin(),c.end());
  cout<<kruskal_s(pq,c)<<endl;
  //cout<<"yes"<<endl;
}
