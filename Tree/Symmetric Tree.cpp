class Solution {
public:

    bool mirror(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;
        
        if(left == NULL || right == NULL)
            return false;
        
        return (left->val == right->val) && mirror(left->left, right->right) && mirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        return mirror(root->left, root->right);
    }
};
