class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            
            for(int j=i+1; j<n-2;j++)
            {
                if(j>i+1 && nums[j] == nums[j-1])
                    continue;
            
                int k = j+1;
                int l = n-1;
                long int s = nums[i] + nums[j] ;
                long int r = target - s;
                
                while(k<l)
                {
                    if(r == nums[k] + nums[l])
                    {
                        vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                        res.push_back(quad);
                        
                        while(k<l && nums[k] == nums[k+1])
                            k++;
                        while(k<l && nums[l] == nums[l-1])
                            l--;
                        
                        k++;
                        l--;
                    }
                    else if(nums[k] + nums[l] < r)
                        k++;
                    else
                        l--;
                }
            }
        }

        return res;
    }
};
