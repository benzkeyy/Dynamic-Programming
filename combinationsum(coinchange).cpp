/* Given an integer array with all positive numbers and 
no duplicates, find the number of possible combinations 
that add up to a positive integer target.

Leetcode ( in coin change ) - https://leetcode.com/problems/coin-change
We can also consider it a general problem if we ignore coins!

*/

 int change(int amount, vector<int>& coins) 
 {
	int n = coins.size();
	int dp[n+1][amount+1];
	 
	for(int i = 0; i <= n; i++) dp[i][0] = 1;
	for(int i = 1; i <= amount; i++) dp[0][i] = 0; 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= amount; j++)
		{
			if(j >= coins[i-1])
			{
				dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][amount];		
 }
