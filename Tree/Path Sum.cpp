class Solution {
public:

    bool dfs(TreeNode* root, int targetSum, int s)
    {
        if(root == NULL)
            return false;
        
        s += root->val;

        if(s == targetSum && root->left == NULL && root->right == NULL)
            return true;
        
        return  dfs(root->left, targetSum, s) || dfs(root->right, targetSum, s); 
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;

        return dfs(root, targetSum, sum);
    }
};
