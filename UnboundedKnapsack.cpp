/* This is different from classical Knapsack problem, here we are allowed to use unlimited number of instances of an item. */
//Function which takes wt array, value array, the size(n) and the max. size of knapsack/bag - W..

int knapsack(int W, int wt[], int val[], int n) 
{ 
    	int dp[n+1][W+1];
	for(int i = 0 ; i <= n; i++)
    	{
		for(int j = 0; j <= W; j++)
      		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if(wt[i-1] <= j)
			{
				dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j])
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			} 
		}
	}
	return dp[n][W];	     
} 
-------------------------------------------------------------------------------
// Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
// n - length of rod!..
// Length array is basically 1,2,3,4,5.. upto n ( NOT ALWAYS NECESSARY! )
// Prices array basically gives the price of each piece/length of rod.
// size of length array/price array..
// Mostly n = size of array or n = size..
int rod_cut(int n,int prices[],int length[], int size)
{
	int dp[size+1][n+1]; // n is length of rod.. size of length of array..
	for(int i = 0 ; i <= size; i++)
    	{
		for(int j = 0; j <= n; j++)
      		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if(length[i-1] <= j)
			{
				dp[i][j] = max(prices[i-1] + dp[i][j-length[i-1]], dp[i-1][j])
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			} 
		}
	}
	return dp[size][n];
}
	
