/*
Leetcode - https://leetcode.com/problems/binary-tree-maximum-path-sum/
Done using dp on trees

*/


    int dp(int &res, TreeNode* root)
    {
        if(root == NULL) return 0;
        
        int lv = dp(res,root->left);
        int rv = dp(res,root->right);
        
        int temp = root->val + max(0,max(lv,rv));
        int ans = max(root->val+lv+rv,temp);
        res = max(res,ans);
        
        return temp;
    }
    int maxPathSum(TreeNode* root) 
    {
        int res = INT_MIN;
        dp(res,root);
        return res;
    }
