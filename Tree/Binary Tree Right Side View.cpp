class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;

        if(root == NULL)
            return res;
        
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> helper;
            int n=q.size();

            for(int i=0; i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                helper.push_back(temp->val);

                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }

            res.push_back(helper[n-1]);
        }

        return res;
    }
};
