class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int c = 0;
        int low = 0;
        int high = n-1;

        while(low <= high)
        {
            c += abs(nums[high] - nums[low]);

            low++;
            high--;
        }

        return c;
    }
};
