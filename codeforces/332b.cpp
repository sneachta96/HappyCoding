/*

So your task is to find  non-intersecting segments with length k and maximum possible sum.
First think we can notice is, that seqments are always exactly of length k.
So you can precompute sum of sequence [a, a + k - 1] for each a.
This can be easily done with one traverse of array. 
When we knew sum for sequence [a, a + k - 1] just add element xa + k and subtract element xa and
you obtain sum for sequence [a + 1, a + k].
Now we can fix some b. We know sum for [b, b + k - 1], but what about first sequence.
Where is best possible a. Well, simply is the sequence [a, a + k - 1] with biggest sum and a + k - 1 < b. 
But we cannot process all such a, because we will get solution with time complexity O(n2).
But we can also precompute the best a for interval [0, i] for every i using dp. 
Again, if some Si is the biggest sum of some sequence of length k in interval [0, i],
than max(Si, sum([i - k + 2, i + 1])) is answer for interval [0, i + 1]. 
And we already compute value of sum([i - k + 2, i + 1]) in first transition.
With all of this we just go through all possible b and pick Sb - 1 as the best position for a.

*/
#include<iostream>
#include<vector>

using namespace std;

 int main(){
  long long int n,k;
  cin>>n>>k;
  long long int arr[n+1];
  for(long long int i = 1;i <= n;i++){
    cin>>arr[i];
  }
  long long int sum1[n+1];
  for(long long int i = 1; i <= k-1;i++){
    sum1[i] = 0;
  }
  long long int sum = 0;
  for(long long int i = 1; i <= k;i++){
    sum = sum + arr[i];
  }
  sum1[k] = sum;
  for(long long int i = k+1;i <= n;i++){
    sum1[i] = sum1[i-1]+arr[i]-arr[i-k];
  }
  long long int max1[n+1];
  for(long long int i = 1;i <= k-1;i++){
    max1[i] = 0;
  }
  max1[k] = sum1[k];
  long long int index[n+1];
  index[k] = 1;
  for(long long int i = k+1;i <= n;i++){
    max1[i] = max(sum1[i],max1[i-1]);
    if(sum1[i] > max1[i-1]){
      index[i] = i-k+1;
    }
    else{
      index[i] = index[i-1];
    }
  }

  long long int maxA = 0;
  long long int a,b;
  for(long long int i = k+1; i <= n-k+1;i++){
    long long int val = max1[i-1] + sum1[i+k-1];
    if(val > maxA){
     //cout<<i<<" "<<val<<endl;
      maxA = val;

      a = index[i-1];
      b = i ;
    }

  }
  cout<<a<<" "<<b<<endl;
  //cout<<maxA<<endl;
}
