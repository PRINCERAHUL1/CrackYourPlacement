class Solution {
public:

    int diameter(TreeNode* root, int &h)
    {
        if(root == NULL)
	{
		h = 0;
		return 0;
	}
	
	int lh=0, rh=0;
	int lDiameter = diameter(root->left, lh);
	int rDiameter = diameter(root->right, rh);
	
	int currDiameter = lh + rh;
	h= max(lh, rh) + 1;
	
	return max(currDiameter, max(lDiameter, rDiameter));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL)
            return 0;
        
        int height = 0;

        return diameter(root, height);
    }
};
