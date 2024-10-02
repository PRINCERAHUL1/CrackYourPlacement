class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0;
        int res=0;

        for(auto n:nums)
        {
            if(c == 0)
                res = n;
            
            if(n != res)
                c--;
            else
                c++;
        }

        return res;
    }
};
