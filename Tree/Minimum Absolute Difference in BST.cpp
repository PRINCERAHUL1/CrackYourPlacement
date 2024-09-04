class Solution {
public:

    int minDiff = INT_MAX;
    int pre = -1;

    int getMinimumDifference(TreeNode* root) {
        if(root == NULL)
            return minDiff;
        
        getMinimumDifference(root->left);

        if(pre != -1)
            minDiff = min(minDiff, root->val-pre);
        
        if(root != NULL)
            pre = root->val;
        
        getMinimumDifference(root->right);

        return minDiff;
    }
};
