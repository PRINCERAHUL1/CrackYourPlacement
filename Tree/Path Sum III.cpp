class Solution {
public:
    int helper(TreeNode* root, long s)
    {
        if(root == NULL)
            return 0;
        
        int res=0;

        if(root->val == s)
            res++;
        
        res+= helper(root->left, s-root->val);
        res+= helper(root->right, s-root->val);

        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return 0;
        
        return pathSum(root->left, targetSum) + helper(root, targetSum) + pathSum(root->right, targetSum);
    }
};
