class Solution {
public:
    int findPair(int n, int x, vector<int> &arr) {
        sort(arr.begin(), arr.end());
        
        int left = 0, right = 1;
        
        while (right < n)
        {
            int diff = abs(arr[right] - arr[left]);
            
            if (diff == x)
                return 1;
            else if (diff < x)
                right++;
            else
            {
                left++;
                if (left == right)
                    right++;
            }
        }
        
        return -1;
    }
};
