class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=0;
        int s= nums.size();
        for(i=0;i<s;i++)
        {
            for(j=i+1;j<s;j++)
            {
                int t = nums[i] + nums[j];
                if(target == t)
                {
                    return {i, j};

                }
            }
        }
        return {};
    }
};
