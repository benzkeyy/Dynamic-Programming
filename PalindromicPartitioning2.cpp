/* Question - https://www.interviewbit.com/problems/palindrome-partitioning-ii/ 
Done using memoization ( top down approach )..
This will work only when the string length ( here, A ) is less than 1000 otherwise we need bottom up!
*/

int dp[1001][1001];
bool ispalindrome(string s, int i, int j)
{
    if(i == j) return true;
    if(i > j) return false;
    while(i < j)
    {
        if(s[i] != s[j]) return false;
        i++; j--;
    }
    return true;
}
int pal_part(string s, int i, int j)
{
    if(i >= j) return 0;
    if(ispalindrome(s,i,j) == true) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX,temp;
    for(int k = i; k <= j-1; k++)
    {
        int left,right;
        if(dp[i][k] != -1)
            left = dp[i][k];
        else
            left = pal_part(s,i,k);
            
        if(dp[k+1][j] != -1)
            right = dp[k+1][j];
        else
            right = pal_part(s,k+1,j);
            
        temp = 1 + left + right;
            
        if(temp < ans) ans = temp;
    }
    dp[i][j] = ans;
    return ans;
}
int Solution::minCut(string A) 
{
    int n = A.size();
    memset(dp,-1,sizeof(dp));
    return pal_part(A,0,n-1);
}
