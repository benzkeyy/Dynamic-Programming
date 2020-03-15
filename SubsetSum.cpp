// P-S -> Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
// Done using dynamic programming.
bool isSubsetSum(int set[], int n, int sum) 
{ 
    bool dp[n+1][sum+1];
    
    for (int i = 0; i <= n; i++) 
      dp[i][0] = true; 
    for (int i = 1; i <= sum; i++) 
      dp[0][i] = false; 
   
    for(int i = 1; i <= n; i++)
    {
    	for(int j = 1; j <= sum; j++)
    	{
    		if(set[i-1] <= j)
    		{
    			dp[i][j] = dp[i-1][j-set[i-1]] || dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

/* ---------- For getting the count of subsets whose SUM to equal to value - 'sum' we only need to do the following modifications->
// Done using Dynamic Programming, returns the count of subsets whose sum to equal to - 'sum' value given in the problem. */

int isSubsetSum(int set[], int n, int sum) 
{ 
    int dp[n+1][sum+1]; // Make this integer array!
    
    for (int i = 0; i <= n; i++) 
      dp[i][0] = 1; 
    for (int i = 1; i <= sum; i++) 
      dp[0][i] = 0; 
   
    for(int i = 1; i <= n; i++)
    {
    	for(int j = 1; j <= sum; j++)
    	{
    		if(set[i-1] <= j)
    		{
    			dp[i][j] = dp[i-1][j-set[i-1]] + dp[i-1][j]; // Replace || to + !!
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum]; // Returns the no of subsets whose SUM is equal to 'sum' !
			   // given n is the no of array elements..
}
