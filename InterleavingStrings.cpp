/*
https://leetcode.com/problems/interleaving-string/
~ Hard!
Given A, B, C, find whether C is formed by the interleaving of A and B.
*/


bool isInterleave(string A, string B, string C) 
    {
        int n = A.size(); int m = B.size();
        if(C.length() != A.length() + B.length()) return false;
        
        int dp[n+1][m+1];
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = (dp[i-1][0] && A[i-1] == C[i-1]);
        }
        for(int j = 1; j <= m; j++)
        {
            dp[0][j] = (dp[0][j-1] && B[j-1] == C[j-1]);
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                bool v1 = (dp[i-1][j] && A[i-1] == C[i+j-1]);
                bool v2 = (dp[i][j-1] && B[j-1] == C[i+j-1]);
                dp[i][j] = v1 || v2;
            }
        }
        return dp[n][m];    
    }
