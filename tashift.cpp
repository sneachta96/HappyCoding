#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	string a ,b;
	cin>>a>>b;
	a = "#"+a;
	b = "#"+ b+b;
//	int next[100];
//	memset(next,0,sizeof(next));
	int lps[1000009];
	int len = 1;
	lps[0] = 0;
	lps[1] = 1;
	int i = 2;
	
	while(i <= n){
	   if(a[i] == a[len]){
	   	  len++;
	   	  lps[i] = len;
	   	  i++;
	   }	
	   else{
	   	if(len != 1){
	   		len = lps[len-1];
		   }
	   else{
	   	lps[i] = 1;
	   	i++;
	   }
      }
	}

	 i = 1;
	int j = 1;
	int res= 0;
	int pre = 0;
	while(i < b.length()){
		if(a[j] == b[i]){
			i++;
			j++;
		}
		else{
			if(j != 1){
				if(res < j){
					res = j;
					pre = i-j;
				}
				j = lps[j-1];
			}
			else{
				i = i + 1;
				
			}
		}
	}
	cout<<pre<<endl;
	//cout<<res<<endl;
}
