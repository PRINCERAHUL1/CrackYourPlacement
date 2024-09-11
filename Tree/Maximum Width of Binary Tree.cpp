class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long ans=0;

        while(!q.empty())
        {
            int n=q.size();
            long start=q.front().second;
            long end=q.back().second;
            ans= max(ans, end-start+1);

            for(int i=0;i<n;i++)
            {
                pair<TreeNode*, int> p=q.front();
                TreeNode* temp=p.first;
                long ind=p.second;
                q.pop();

                if(temp->left)
                    q.push({temp->left, 2*ind+1});
                
                if(temp->right)
                    q.push({temp->right, 2*ind+2});
            }
        }

        return ans;
    }
};
