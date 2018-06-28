//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/techno-tasks/
//Segment Tree
//Status : Accepted XD


#include<bits/stdc++.h>
using namespace std;

struct node{
  int l_bit ;
  int r_bit ;
  int c;
};

const int N = 100009;
int arr[N];
node seg[4*N];

void build(int l ,int r, int index ){
  if(l == r){
  //  cout<<index<<" "<<arr[l]<<endl;
    node n;
    n.l_bit = arr[l];
    n.r_bit = arr[l];
    if(arr[l] == 1){
      n.c = 1;
    }
    else{
      n.c = 0;
    }
    seg[index] = n;
    return ;
  }
  else{
    int left = 2*index;
    int right = 2*index+1;
    int m = (l+r)/2;
    build(l,m,left);
    build(m+1,r,right);
  //  cout<<index<<" "<<seg[index].c<<endl;
  //  cout<<seg[left].r_bit<<" "<<seg[right].l_bit<<endl;
    if(seg[left].r_bit  == 1 && seg[right].l_bit == 1){
      seg[index].c = seg[left].c + seg[right].c -1;
    }
    else{
      seg[index].c = seg[left].c + seg[right].c;
    }

    seg[index].l_bit = seg[left].l_bit;
    seg[index].r_bit  = seg[right].r_bit;
  }
}


void update(int l , int r, int index, int i){
  if( l == r ){
    arr[l] = 1- arr[l];
    seg[index].l_bit = arr[l];
    seg[index].r_bit = arr[l];
    if(arr[l] == 1){
      seg[index].c = 1;
    }
    else{
      seg[index].c = 0;
    }
  }
  else{
    int left = 2*index;
    int right = 2*index +1;
    int m = (l+r)/2;
    if(i <= m){
      update(l,m,left,i);
    }
    else{
      update(m+1,r,right,i);
    }
    if(seg[left].r_bit  == 1 && seg[right].l_bit == 1){
      seg[index].c = seg[left].c + seg[right].c -1;
    }
    else{
      seg[index].c = seg[left].c + seg[right].c;
    }
    seg[index].l_bit = seg[left].l_bit;
    seg[index].r_bit  = seg[right].r_bit;
  }
}

int query(int l, int r, int index, int a, int b){
  if( a <= l && b >= r){
    //cout<<"hey "<<index<<seg[index].c<<endl;
    return seg[index].c;
  }
  if( a > r || b < l){

    return 0;
  }
  else{
    int left = 2*index;
    int right = 2*index+1;
    int m= (l+r)/2;
    int p1 = query(l,m,left,a,b);
    int p2 = query(m+1,r,right,a,b);
    //cout<<"at index "<<index<<" "<<seg[left].r_bit<<" "<<seg[right].l_bit<<" "<<p1<<" "<<p2<<endl;
    if(seg[left].r_bit == 1 && seg[right].l_bit == 1 && p1 != 0 && p2 != 0){
      return p1+p2-1;
    }
    else{
      return p1+p2;
    }
  }
}
int main(){
  int n;
  cin>>n;
  int q;
  cin>>q;
  for(int i = 1; i <= n;i++){
    cin>>arr[i];
  }
  build(1,n,1);
  while( q--){
    int x;
    cin>>x;
    if(x == 1){
      int i;
      cin>>i;
      update(1,n,1,i);
    }
    else{
      int a,b;
      cin>>a>>b;
      cout<<query(1,n,1,a,b)<<endl;
    }
  }
}
