class Solution {
public:
    int sum =0;

    void sumLeft(TreeNode* root, bool check)
    {
        if(check && !root->left && !root->right)
        {
            sum += root->val;
            return;
        }

        if(root->left)
            sumLeft(root->left, true);
        if(root->right)
            sumLeft(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        sumLeft(root, false);
        return sum;
    }
};
