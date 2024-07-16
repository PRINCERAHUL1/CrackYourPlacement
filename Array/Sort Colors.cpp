class Solution {
public:
    void sortColors(vector<int>& nums) {
        int large=2;
        int* count = new int[large+1]();
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }

        int j=0;
        for(int i=0;i<large+1;i++)
        {
            while(count[i] > 0)
            {
                nums[j] = i;
                j++;
                count[i]--;
            }
        }
        
    }
};
