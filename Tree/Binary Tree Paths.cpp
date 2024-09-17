class Solution {
public:

    void preorder(TreeNode* root, vector<string> &v, string s)
    {
        if(root == NULL)
            return;
        
        s+= to_string(root->val);
        s+= "->";

        if(root->left == NULL && root->right == NULL)
        {
            s.pop_back();
            s.pop_back();
            v.push_back(s);
        }

        preorder(root->left, v, s);
        preorder(root->right, v, s);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s="";
        preorder(root, v, s);
        
        return v;
    }
};
