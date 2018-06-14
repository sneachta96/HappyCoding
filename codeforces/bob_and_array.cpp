//https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/shivam-and-expensive-birthday-gift-da58b2f0/description/



#include<bits/stdc++.h>

using namespace std;
const int N = 500003;
 int arr[N] = {0};
int seg[4*N] = {0};
//long long int  N;


void update1(int s, int e, int index, int x){
  if(s == e){
    arr[x]++;
    seg[index]++;
  }
  else{

    int left = 2*index;
    int right = 2*index+1;
    int m = (s+e)/2;
    if(s <= x && m >= x){
      update1(s,m,left,x);
    }
    else{
      update1(m+1,e,right,x);
    }
    seg[index] = seg[left]+seg[right];
  }
}

void update2(int s, int e, int index,int x){
  if(s == e){
    if(arr[x] == 0){
      return ;
    }
    else{
      arr[x]--;
      seg[index]--;
    }
  }
  else{
    int left = 2*index;
    int right = 2*index+1;
    int m = (s+e)/2;
    if(s <= x && x <= m){
      update2(s,m,left,x);
    }
    else{
      update2(m+1,e,right,x);
    }
    seg[index] = seg[left]+seg[right];
  }
}

int query(int index , int st ,int en, int l , int r){
  if(st > r || en < l){
    return 0;
  }
  if( l <= st && en <= r){
    return seg[index];
  }
  int left = 2*index;
  int right = 2*index+1;
  int m= (st+en)/2;
  int p1 = query(left,st,m,l,r);
  int p2 = query(right,m+1,en,l,r);
  return (p1+p2);
}

int main(){
  int n,q;
 scanf("%d%d",&n,&q);
  while(q--){
    int x;
    scanf("%d",&x);
    if(x == 1){
      int a;
      scanf("%d",&a);
      update1(1,n,1,a);

    }
    else if(x == 2){
      int a;
      scanf("%d",&a);
      update2(1,n,1,a);

    }
    else{
      int a,b;
    scanf("%d%d",&a,&b);
      cout<<query(1,1,n,a,b)<<endl;
    }
  }
}
