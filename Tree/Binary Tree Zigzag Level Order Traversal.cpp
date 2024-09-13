class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;

        if (root == NULL)
            return res;
        
        q.push(root);
        int level=0;

        while(!q.empty())
        {
            int n=q.size();
            vector<int> cur(n);

            for(int i=0; i<n; i++)
            {
                TreeNode* temp=q.front();
                q.pop();

                if(level==0)
                    cur[i]=temp->val;
                else
                    cur[n-i-1]=temp->val;
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }

            res.push_back(cur);
            level = !level;
        }

        return res;
    }
};
