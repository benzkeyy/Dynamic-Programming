//Longest Common Subsequence using dynamic programming.
//Question - https://leetcode.com/problems/longest-common-subsequence

 int longestCommonSubsequence(string text1, string text2) 
    {
        int n1 = text1.length(),n2=text2.length();
        if(n1 == 0 || n2 == 0) return 0;
        
        int dp[n1+1][n2+1];
        
        for(int i = 0; i <= n1; i++)
        {
            for(int j = 0; j <= n2; j++)
            {
                if(i == 0 || j == 0) dp[i][j] = 0;
                
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n1][n2];
    }
-----------------------------------------------------------
 // Count all the common subsequences!
 int CountCommonSubsequence(string text1, string text2) 
    {
        int n1 = text1.length(),n2=text2.length();
        if(n1 == 0 || n2 == 0) return 0;
        
        int dp[n1+1][n2+1];
        
        for(int i = 0; i <= n1; i++)
        {
            for(int j = 0; j <= n2; j++)
            {
                if(i == 0 || j == 0) dp[i][j] = 0;
                
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j] + dp[i][j-1];
                
                else
                    dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
            }
        }
        return dp[n1][n2];
    }
-----------------------------------------------------------
 // Printing LCS!
 -- Write LCS Code..
 void PrintlongestCommonSubsequence(string text1, string text2) 
 {
        int n1 = text1.length(),n2=text2.length();
        if(n1 == 0 || n2 == 0) return 0;
        int dp[n1+1][n2+1];
        for(int i = 0; i <= n1; i++)
        {
            for(int j = 0; j <= n2; j++)
            {
                if(i == 0 || j == 0) dp[i][j] = 0;
                
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        int i = m; int j = n; string s;
        while(i > 0 && j > 0)
        {
           if(text1[i-1] == text2[j-1])
           {
              s.push_back(text1[i-1]);
              i--; j--;
           }
           else
           {
              if(t[i][j-1] > t[i-1][j])
              {
                j--;
              }
              else
              {
                i--;
              }
           }
        }
        reverse(s.begin(),s.end());
       cout << s; // Answer!
}
 
 -----------------------------------------------------------
 // For substring, we do little modification!
  int longestcommonsubstring(string text1, string text2) 
    {
        int n1 = text1.length(),n2=text2.length();
        if(n1 == 0 || n2 == 0) return 0;
        
        int dp[n1+1][n2+1];
        int maxi = INT_MIN;
        for(int i = 0; i <= n1; i++)
        {
            for(int j = 0; j <= n2; j++)
            {
                if(i == 0 || j == 0) dp[i][j] = 0;
                
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                    dp[i][j] = 0;
                    
                maxi = max(maxi,dp[i][j]);
                    // Only this is modified.. because we are finding a substring
            }
        }
        return maxi;
    }
