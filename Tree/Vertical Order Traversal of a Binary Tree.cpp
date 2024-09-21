class Solution {
public:

    void preorder(TreeNode* root, map<int, vector<pair<int, int>>> &mp, int row, int col)
    {
        if(root == NULL)
            return;
        
        mp[col].push_back({row, root->val});

        preorder(root->left, mp, row+1, col-1);
        preorder(root->right, mp, row+1, col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map <int, vector<pair<int, int>>> mp;
        preorder(root, mp,0,0);
        vector<vector<int>> res;
        for(auto m: mp)
        {
            sort(m.second.begin(), m.second.end());
            vector<int> temp;
            for(auto p: m.second)
            {
                temp.push_back(p.second);
            }

            res.push_back(temp);
        }

        return res;
    }
};
