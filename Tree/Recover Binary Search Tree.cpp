class Solution {
public:

    void markTree(TreeNode* root, TreeNode* &pre, TreeNode* &first, TreeNode* &end)
    {
        if(root == NULL)
            return;
        
        markTree(root->left, pre, first, end);
        if(pre != NULL)
        {
            if(root->val < pre->val)
            {
                if(!first)
                    first = pre;
                
                end = root;
            }
        }

        pre = root;
        markTree(root->right, pre, first, end);

    }

    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL;
        TreeNode* first = NULL;
        TreeNode* end = NULL;

        markTree(root, pre, first, end);
        swap(first->val, end->val);

    }
};
