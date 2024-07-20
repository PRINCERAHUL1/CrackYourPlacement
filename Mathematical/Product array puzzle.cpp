class Solution{
  public:

    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        vector<long long int> res(n, 1);
        if(n <= 1)
            return res;
        
        long long left = 1;
        
        for(int i=0; i<n; i++)
        {
            res[i] = left;
            left *= nums[i];
        }
        
        long long right = 1;
        
        for(int i=n-1; i>=0; i--)
        {
            res[i] *= right;
            right *= nums[i];
        }
        
        return res;
    }
};
