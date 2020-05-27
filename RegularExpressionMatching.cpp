/*
Very good question!
https://leetcode.com/problems/regular-expression-matching/

Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

*/


 bool isMatch(string s, string p) 
    {
        int n = s.size();
        int m = p.size();
        bool dp[n+1][m+1];
        dp[0][0] = true;
        for(int i = 1; i <= n; i++) dp[i][0] = false;
        for(int i = 1; i <= m; i++)
        {
            dp[0][i] = i > 1 && p[i-1] == '*' && dp[0][i-2];
            // form is *, a* or a*b* -> can be empty!
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(p[j-1] == '*')
                {
                    dp[i][j] = (dp[i][j-2]) || (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]; 
                    //          zero occurences .. This checks for one or more occurences..
                    // dp[i-1][j] is because we check if string s with one char removed can be a part of
                    // string p or not.
                }
                else
                {
                    dp[i][j] =  dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        return dp[n][m];
    }
