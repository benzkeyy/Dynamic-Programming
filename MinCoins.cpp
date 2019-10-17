/* You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.*/

#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

using namespace std;

int main() 
{ 
	int n;
	cin>>n;
	int dp[n+1];
	int arr[] = {1,2,5};
	dp[0] = 0;
	for(int i = 1; i <= n; i++) dp[i] = INT_MAX;
	int i,x;
	for(i = 1; i <= n; i++)
		for(x = 0; x <= 3; x++) // Here, x usually arr.length but here it is fixed = 3
			if(i - arr[x] >= 0)
				dp[i] = min(dp[i],dp[i-arr[x]] + 1);
	for(auto a : dp)
		cout << a << " ";
    return 0; 
} 
