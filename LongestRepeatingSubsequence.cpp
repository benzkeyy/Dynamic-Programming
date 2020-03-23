/* Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string. */
// Just pass text1,text1 in LCS and make a minor change! ( i != j )

int LongestRepeatingSubsequence(string text1, string text1) 
    {
        int n1 = text1.length(),n2=text1.length();
        if(n1 == 0 || n2 == 0) return 0;
        
        int dp[n1+1][n2+1];
        
        for(int i = 0; i <= n1; i++)
        {
            for(int j = 0; j <= n2; j++)
            {
                if(i == 0 || j == 0) dp[i][j] = 0;
                
                else if(text1[i-1] == text1[j-1] && i != j) // Only minor change here!
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n1][n2];
    }
    ------------------------------------------------------------------------------------------------------------
    For printing -
    
    string res = ""; 
  
    // Traverse dp[][] from bottom right 
    int i = n, j = n; 
    while (i > 0 && j > 0) 
    { 
        // If this cell is same as diagonally 
        // adjacent cell just above it, then  
        // same characters are present at  
        // str[i-1] and str[j-1]. Append any  
        // of them to result. 
        if (dp[i][j] == dp[i-1][j-1] + 1) 
        { 
           res += str[i-1]; 
           i--; 
           j--; 
        } 
  
        // Otherwise we move to the side 
        // that that gave us maximum result 
        else if (dp[i][j] == dp[i-1][j]) 
            i--; 
        else
            j--; 
    } 
    reverse(res.begin(), res.end()); 
    
    
    // Now return..
