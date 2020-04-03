/*
Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum. 
*/

// We use Kadane's Algorithm here! ( Dynamic Programming approach )
// max_so_far is the final answer that we will return to main function..
// max_ending_here basically checks for largest sum

int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_ending_here < 0) 
            max_ending_here = 0; 
            
       else if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
    } 
    return max_so_far; 
} 
-----------------------------------------------------------------------------
// It does not handles cases when all elements are negative, for that, the approach is ->

int maxSubArraySum(int a[], int size) 
{ 
    int ans = a[0], sum = a[0]; 
  
    for (int i = 1; i < size; i++) 
    { 
        sum = max(a[i],sum+a[i]);
        ans = max(ans,sum);
    } 
    return ans;
} 
