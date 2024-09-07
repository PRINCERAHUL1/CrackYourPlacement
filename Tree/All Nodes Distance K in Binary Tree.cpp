class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> parent;

    void preorder(TreeNode* cur, TreeNode* par)
    {
        if(cur == NULL)
            return;
        
        parent[cur]=par;
        preorder(cur->left, cur);
        preorder(cur->right, cur);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        preorder(root, NULL);

        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;

        while(!q.empty() && k)
        {
            k-=1;
            int n = q.size();

            for(int i=0; i<n; i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                visited.insert(cur);

                if(!visited.count(cur->left) && cur->left)
                    q.push(cur->left);

                if(!visited.count(cur->right) && cur->right)
                    q.push(cur->right);

                if(!visited.count(parent[cur]) && parent[cur])
                    q.push(parent[cur]);
            }
        }

        vector<int> res;

        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            res.push_back(temp->val);
        }

        return res;
    }
};
