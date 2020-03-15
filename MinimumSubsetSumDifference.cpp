/* Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum. */
// Given an array with n elements!

int min_subsetsum_diff(int arr[], int n) 
{ 
    // Calculate sum of all elements 
    int sum = 0;  
    for (int i = 0; i < n; i++) sum += arr[i]; 
    
    // Do the subset problem dp!
    bool dp[n+1][sum+1]; 
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false; 
    for (int i=1; i<=n; i++) 
    { 
        for (int j=1; j<=sum; j++) 
        { 
            dp[i][j] = dp[i-1][j]; 
            if (arr[i-1] <= j) dp[i][j] |= dp[i-1][j-arr[i-1]]; 
        } 
    } 
    // Now every cell of last row of DP, if it is true tells us that subset whose sum is equal to that column no. is possible!
    // We loop from sum/2 to 0 and find the largest 'j' value so that diff is minimum!
    
    int diff = INT_MAX;    
    // Find the largest j such that dp[n][j] 
    // is true where j loops from sum/2 t0 0 
    for (int j=sum/2; j>=0; j--) 
    { 
        // Find the  
        if (dp[n][j] == true) 
        { 
            diff = sum-2*j; 
            break; 
        } 
    } 
    return diff; 
} 
