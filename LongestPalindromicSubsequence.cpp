/*
  Question - https://leetcode.com/problems/longest-palindromic-subsequence
  Level - Medium
  Uses O(n^2) space!
*/
// Code only contains the function which accepts the string **'s'** and returns the -LENGTH- of the longest palindromic sub**sequence**!

 int longestPalindromeSubseq(string s) 
    {
        int i,j,l,n=s.size();
        int dp[n][n];
        for(i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        
        for(l=2; l <= n; l++)
        {
            for(i = 0; i < n-l+1; i++)
            {
                j = i+l-1;
                if(s[i] == s[j] && l == 2)
                {
                    dp[i][j] = 2;
                }
                else if(s[i] == s[j])
                {
                    dp[i][j] = 2 + dp[i+1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
