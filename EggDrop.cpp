/*
Egg Dropping problem is a classical DP problem!
Leetcode - https://leetcode.com/problems/super-egg-drop/
*/
------------------------------------------------------------------------------
// This doesn't works on leetcode due to constraints!
// This is topdown memoization..

int dp[105][100005];
    
    int egg_drop_dp(int K, int N)
    {
        if(K == 1) return N;
        if(N == 0 || N == 1) return N;
        
        if(dp[K][N] != -1)
            return dp[K][N];
        
        
        int ans = INT_MAX;
        
        for(int i = 1; i <= N; i++)
        {
            int a1,a2;
            
            if(dp[K-1][i-1] != -1)
                a1 = dp[K-1][i-1];
            else
                a1 = egg_drop_dp(K-1,i-1);
            
            if(dp[K][N-i] != -1)
                a2 = dp[K][N-i];
            else
                a2 = egg_drop_dp(K,N-i);
                
            int temp = 1 + max(a1,a2);
            ans = min(ans,temp);
        }
        dp[K][N] = ans;
        return ans;
    }
    int superEggDrop(int K, int N) 
    {
        memset(dp,-1,sizeof(dp));
        return egg_drop_dp(K,N);
    }
  -------------------------------------------------------------------------------------------------------
  // This is a bottom-up 1D dp
   int dp[1005][10005]; // Decided by the constraints!!
   int superEggDrop(int K, int N) 
   {
        memset(dp,0,sizeof(dp));
        int m = 0;
        while (dp[m][K] < N) {
            m++;
            for (int k = 1; k <= K; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
    }
