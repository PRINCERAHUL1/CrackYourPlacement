class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        
        q.push(root);

        if(root==NULL)
            return res;

        while(!q.empty())
        {
            int n=q.size();
            vector<int> v;

            while(n--)
            {
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left != NULL)
                    q.push(temp->left);
                
                if(temp->right != NULL)
                    q.push(temp->right);
                
                v.push_back(temp->val);
            }

            res.push_back(v);
        }

        return res;
    }
};
