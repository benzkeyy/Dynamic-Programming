// Leetcode - https://leetcode.com/problems/partition-equal-subset-sum/

 bool subset_sum(vector<int>&nums,int n, int sum)
    {
        int dp[n+1][sum+1];
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;
        for(int i = 1; i <= sum; i++)
            dp[0][i] = false;
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size(),sum=0; for(int i = 0; i < n; i++) sum += nums[i];
        if(sum % 2 != 0) return false;
        else sum /= 2;
        
        bool t = subset_sum(nums,n,sum);
        return t;
    }
