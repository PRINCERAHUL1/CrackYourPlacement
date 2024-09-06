class BSTIterator {
public:

    stack<TreeNode*> st;

    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        st.push(root);

        while(root->left)
        {
            st.push(root->left);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        inorder(root);

    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();

        if(temp->right)
            inorder(temp->right);
        
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
