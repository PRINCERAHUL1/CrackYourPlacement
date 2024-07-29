class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefix = 0, res = 0;

        vector<int> count(k);
        count[0] = 1;

        for (int i=0; i<n; i++) {
            prefix = (prefix + nums[i] % k + k) % k;
            res += count[prefix];
            count[prefix]++;
        }

        return res;
    }
};
