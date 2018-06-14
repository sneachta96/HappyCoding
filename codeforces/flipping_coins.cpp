//https://www.codechef.com/problems/FLIPCOIN
//Segment Tree with Lazy Propagation

#include<iostream>
#include<vector>

using namespace std;

vector <int> lazy(4*100001,0);
vector<int> tree(4*100001,0);
void updatelazy(int b ,int c,int l ,int r, int node){
  if(lazy[node] != 0){
    if(lazy[node]%2!= 0){
      tree[node] = (r-l+1-tree[node]);
    }
      if(l != r){
        lazy[2*node+1]+=lazy[node];
        lazy[2*node+2]+=lazy[node];
      }
      lazy[node]=0;
  }
  if(b > r || c< l){
    return ;
  }
  if(l >= b && r <= c){
    tree[node] = (r-l+1-tree[node]);
    if(l!=r){
      lazy[2*node+1]++;
      lazy[2*node+2]++;
    }
  }
  else{
    int mid = (l+r)/2;
    updatelazy(b,c,l,mid,2*node+1);
    updatelazy(b,c,mid+1,r,2*node+2);
    tree[node] = tree[2*node+1]+tree[2*node+2];
  }

}



int querylazy(int b,int c, int l, int r, int node){
  if(lazy[node]!=0){
    if(lazy[node]%2!=0){
      tree[node] = (r-l+1)-tree[node];
    }
    if(l!=r){
      lazy[2*node+1]+=lazy[node];
      lazy[2*node+2]+=lazy[node];
    }
    lazy[node]=0;
  }
  if(b>r ||  c <l){
    return 0;
  }
  if(b <= l && c >= r){
    return tree[node];
  }
  else{
    int mid = (l+r)/2;
    int p1 = querylazy(b,c,l,mid,2*node+1);
    int p2 = querylazy(b,c,mid+1,r,2*node+2);
    return (p1+p2);
  }
}

int main(){
  int n,q;
  cin>>n>>q;
  while(q--){
    int a,b,c;
    cin>>a>>b>>c;
    if(a == 0){
      updatelazy(b,c,0,n-1,0);
    }
    else{
      int k = querylazy(b,c,0,n-1,0);
      cout<<k<<endl;
    }
  }
}
