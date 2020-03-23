/* Matrix Chain Multiplication
Description - Given a sequence of matrices, find the most efficient way to multiply these matrices together. The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications. 
Source - geeksforgeeks!
*/
// Given an array p[] ( of size n ) which represents the chain of matrices such that the ith matrix Ai is of dimension p[i-1] x p[i].
// We need to write a function MatrixChainOrder() that should return the minimum number of multiplications needed to multiply the chain.
// i is the left end, j is the right end!
// Pass i as " 1 " and j as " n-1 " !! ( They are basically indexes )
// RECURSIVE
int MatrixChainOrder(int p[], int n, int i, int j)
{
    if(i >= j)
        return 0;
        
    int ans = INT_MAX;
    for(int k = i; k < j; k++)
    {
        int a1 = MatrixChainOrder(p,n,i,k) + MatrixChainOrder(p,n,k+1,j) + p[i-1] * p[k] * p[j];
        if(a1 < ans)
            ans = a1;
    }
    return ans;
}

----------------------------------------------------------------------------------------------------------------------------------
// TOP DOWN
// Due to recursive calls, take a global DP array

int static dp[1001][1001]; // We assume that at max size of array is 1000.
/* IN MAIN FUNCTION - memset(dp,-1,sizeof(dp)) important.. */
int MatrixChainOrder(int p[], int n, int i, int j)
{
    if(i >= j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    int ans = INT_MAX;
    for(int k = i; k < j; k++)
    {
        int a1 = MatrixChainOrder(p,n,i,k) + MatrixChainOrder(p,n,k+1,j) + p[i-1] * p[k] * p[j];
        if(a1 < ans)
            ans = a1;
    }
    dp[i][j] = ans;
    return ans;
}
