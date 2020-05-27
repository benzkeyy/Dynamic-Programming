/*
Given a string s and a string t, count the number of distinct subsequences of s which equals t.
dp[i][j] gives the count of unique subsequences of t[0..j] in s[0..i].
if(both char equal or s[i-1] == t[i-1] )
then we may consider the char in t or we may not that is why ->
dp[i][j] = dp[i-1][j] ( we ignore the char in t ) + dp[i-1][j-1] ( we consider it )
otherwise
dp[i][j] = dp[i-1][j]
i-1 -> because w/e be the case, we then try to find t in smaller version of s of s[0..i-1].
*/


 int numDistinct(string s, string t) 
    {
        int n = s.size();
        int m = t.size();
        long long int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i <= n; i++) dp[i][0] = 1; // if t is empty, then in s[0..i] we have 1 subsequence of t ( empty ).
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
