class Solution {
public:

    TreeNode* bst(vector<int> nums, int left, int right)
    {
        if(left>right)
            return NULL;
        
        int m= left + (right-left)/2;
        TreeNode* node= new TreeNode(nums[m]);

        node->left = bst(nums, left, m-1);
        node->right = bst(nums, m+1, right);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        
        return bst(nums, 0, nums.size()-1);
    }
};
