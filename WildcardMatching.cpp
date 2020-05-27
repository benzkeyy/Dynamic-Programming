/*
  Wildcard Matching.
  
  It differs from regular pattern matching for the fact that * can match anything!
  in regular we needed some char for * to expand ( like a* -> a,aa,aaa... ) but here * can be anything a,aa,ab,bbb
  
  https://leetcode.com/problems/wildcard-matching
  
  Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

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
            dp[0][i] = p[i-1] == '*' && dp[0][i-1];
            // if we find * and before it we had true, then it will be true.
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                    // first is for zero occurence.
                    // for second, like regular matching, we remove one char from s, then check
                    // if s can be a part of t(basically meaning for 1 
                    //or more occurences of any char)
                }
                else
                {
                    dp[i][j] =  dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
            }
        }
        return dp[n][m];    
    }
