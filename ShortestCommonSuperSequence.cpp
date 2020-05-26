// Leetcode - https://leetcode.com/problems/shortest-common-supersequence

 string shortestCommonSupersequence(string text1, string text2) 
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
        // If it is asking for only length, then return dp[n1][n2]; and for ans - > n1 + n2 - dp[n1][n2] !!
  
        int i = text1.length(); int j = text2.length(); string s;
        int index=dp[n1][n2];
        while(i > 0 && j > 0)
        {
            if(text1[i-1] == text2[j-1])
            {
                s.push_back(text1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i][j-1] > dp[i-1][j])
                {
                    s.push_back(text2[j-1]);
                    j--;
                }
                else
                {
                    s.push_back(text1[i-1]);
                    i--;
                }
            }
        }
        while(i > 0)
        {
            s.push_back(text1[i-1]);
            i--;
        }
        while(j > 0) 
        {
            s.push_back(text2[j-1]);
            j--;
        }
        reverse(s.begin(),s.end());
        return s;
    }
