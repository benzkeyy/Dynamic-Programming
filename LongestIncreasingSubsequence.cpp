// Longest increasing subsequence using dynamic programming
// Question - https://leetcode.com/problems/longest-increasing-subsequence

 int lengthOfLIS(vector<int>& nums) 
    {
        int n= nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        int dp[n];
        for(int i = 0; i < n; i++)
            dp[i] = 1;
        
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j] && dp[j]+1 > dp[i])
                {
                    dp[i] = 1 + dp[j];
                }
            }
        }
        return *max_element(dp,dp+n);
    }
---------------------------------------------------------------------------------------------------------------------
// ANOTHER GOOD APPROACH USING LCS!
// Just use LCS, pass one parameter as the array itself, and the second paramater as the sorted array!...
// Make sure sorted array does not have duplicates ( strictly increasing subsequence!)
