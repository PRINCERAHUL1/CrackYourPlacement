class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];

        while(low<high)
        {
            int mid=low+ (high-low)/2;
            int c=0;
            for(int i=0; i<n; i++)
                c += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            
            if(c<k)
                low=mid+1;
            else
                high=mid;
        }

        return low;
    }
};
