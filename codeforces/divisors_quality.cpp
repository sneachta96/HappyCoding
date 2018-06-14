
//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/max-divisors/description/

#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#define MAX 100000

using namespace std;

struct node {
  int val;
  list<int> to;
};

node *tree;
int N;

pair<int,int> *range;
int cur = 0;
vector<int> seg[5*100000+5];
vector<int> epath;


void dfs(int root, int parent){
  range[root].first = cur++;
  epath.push_back(root);
  list <int> :: iterator  i;
  for(  i = tree[root].to.begin(); i != tree[root].to.end();i++){
    if(*i!=parent){
      dfs(*i,root);
    }
  }
  range[root].second = cur-1;
}

void build_segment_tree(int index, int s, int e){
  if(s==e){
    seg[index].push_back(tree[epath[s]].val);
    //  cout<<"hey"<<endl;
    return ;
  }
  int left = 2*index+1;
  int right = 2*index+2;
  //cout<<left<<" "<<right<<endl;
  int m = s+ (e-s)/2;
//cout<<left<<" "<<m<<" "<<right<<endl;
  build_segment_tree(left,s,m);
  build_segment_tree(right,m+1,e);
 seg[index].resize(seg[left].size()+seg[right].size());
  merge(seg[left].begin(),seg[left].end(),seg[right].begin(), seg[right].end(), seg[index].begin());

}
int query(int index, int s, int e, int b  ,int c,int val){
  if(s > c || e < b ){
    return 0;
  }
  if(b <= s && e <= c ){
    return lower_bound(seg[index].begin(),seg[index].end(),val) - seg[index].begin();
  }
  int left = 2*index+1;
  int right = 2*index+2;
  int m = s + (e-s)/2;
  return query(left,s,m,b,c,val) + query(right,m+1,e,b,c,val);
}

int sieve[100000+1] = {0};
void make(){
  for(int i = 1; i<= MAX;i++){
    for(int j = i ; j <= MAX;j+=i){
      sieve[j]++;
    }
  }
}


int main(){
  cin>>N;
  tree = new node[N+1];
  range = new pair<int,int> [N+1];
  for(int i = 0; i < N;i++){
    cin>>tree[i+1].val;
  }
  for(int i = 1; i  < N;i++){
    int l , r;
    cin>>l>>r;
    tree[l].to.push_back(r);
    tree[r].to.push_back(l);
  }
  //cout<<"hey"<<endl;
  dfs(1,0);
  //cout<<endl;
  build_segment_tree(0,0,cur-1);

  make();
  int ans = -1;
  for(int i = 1; i<=N;i++){
    ans = max(ans,sieve[(query(0,0,cur-1,range[i].first,range[i].second,tree[i].val))]);
  }
  cout<<ans<<endl;
}
