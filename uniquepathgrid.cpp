/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below). */
// Basically dp the number of unique paths from top left to bottom right..
// We can also use the forumula -  (M+N-2) and get the answer directly!
//								   ( N-1 ) 
#include <bits/stdc++.h>
#define fast std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long


using namespace std;

int main() 
{ 
    ll m,n;
	cin>>m>>n;
	int dp[m][n];
	 
	for (int i = 0; i < m; i++) 
        dp[i][0] = 1; 
        
    for (int j = 0; j < n; j++) 
        dp[0][j] = 1; 
        
    for (int i = 1; i < m; i++) 
        for (int j = 1; j < n; j++) 
  			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
  
    cout << dp[m - 1][n - 1];  
    return 0; 
} 
