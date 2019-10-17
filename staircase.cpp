/*
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */

#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long

using namespace std;

int main() 
{ 
	ll n;
	cin>>n;
	int dp[n+2];
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= n; i++)
	{ 
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout << dp[n];
    return 0; 
} 
