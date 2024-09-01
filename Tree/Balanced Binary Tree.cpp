class Solution {
public:

    int bst(TreeNode* root, int &h)
    {
        if(root == NULL)
            return 0;
        
        int l = bst(root->left, h) +1;
        int r = bst(root->right, h) +1;

        if(abs(r-l) >1)
            h=0;
        
        return max(r,l);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        int height = 1;
        bst(root, height);

        if(height)
            return true;
        else
            return false;
    }
};
