//Problem link : https://www.codechef.com/problems/DISHOWN
//Disjoint Set union
//Status : Accepted :D



#include <iostream>
using namespace std;
int parent[10009];
int arr[10009];
int find_parent(int i){
    if(parent[i] == i){
        return i;
    }
    else{
        int j = find_parent(parent[i]);
        parent[i] = j;
        return j;
    }
}
int join(int i , int j){
    int a = find_parent(i);
    int b = find_parent(j);
    if(arr[a] > arr[b]){
        parent[b] = a;
    }
    else if(arr[b] > arr[a]){
        parent[a] = b;
    }
}
 
int main() {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    for(int i = 1; i <= n;i++){
	        cin>>arr[i];
	        parent[i] = i;
	    }
	    int q;
	    cin>>q ;
	    while(q--){
	        int i;
	        cin>>i;
	        if(i == 0){
	            int x,y;
	            cin>>x>>y;
	            int px = find_parent(x);
	            int py = find_parent(y);
	           // cout<<px<<" "<<py<<endl;
	            if(px == py){
	                cout<<"Invalid query!"<<endl;
	            }
	            else{
	                join(x,y);
	            }
	        }
	        else{
	            int x;
	            cin>>x;
	            cout<<find_parent(x)<<endl;
	        }
	    }
	    
	    
	}
	return 0;
}
 
