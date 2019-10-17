/* Given an integer array with all positive numbers and 
no duplicates, find the number of possible combinations 
that add up to a positive integer target.*/


#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

using namespace std;

int main() 
{ 
	int N,i,x;
  	cin>>N;
  	int dp[N+1];
  	int arr[] = {1,2,3};
  	memset(dp,0,sizeof(dp));
  	dp[0] = 1;
  	for(i = 1; i <= N; i++)
  		for(x = 0; x < 3; x++) // usually, x < arr.length but here arr.length is fixed = 3
            if(i - arr[x] >= 0)
                dp[i] += dp[ i - arr[x] ];  
	for(auto i : dp)
		cout << i << " ";
    return 0; 
} 
