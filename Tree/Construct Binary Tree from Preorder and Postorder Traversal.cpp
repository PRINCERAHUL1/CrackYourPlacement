class Solution {
public:

    TreeNode* dfs(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd) {
        if (preStart > preEnd)
            return NULL;

        TreeNode* root = new TreeNode(pre[preStart]);

        if (preStart == preEnd)
            return root;

        int postIndex = postStart;
        while (post[postIndex] != pre[preStart + 1])
            postIndex++;

        int len = postIndex - postStart + 1;

        root->left = dfs(pre, preStart + 1, preStart + len, post, postStart, postIndex);
        root->right = dfs(pre, preStart + len + 1, preEnd, post, postIndex + 1, postEnd - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return dfs(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
