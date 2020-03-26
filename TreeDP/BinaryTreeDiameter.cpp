/*

https://leetcode.com/problems/diameter-of-binary-tree/
Done in O(n)


 int dp(TreeNode* root, int &res)
    {
        
        if(root == NULL)
            return 0;
    
        int l = dp(root->left,res);
        int r = dp(root->right,res);
        
        int temp = 1 + max(l,r);
        int ans = max(temp,1+l+r);
        res = max(res,ans);
        
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL) return 0;
        int res = INT_MIN;
        dp(root,res);
        return res-1;
    }
    
*/
