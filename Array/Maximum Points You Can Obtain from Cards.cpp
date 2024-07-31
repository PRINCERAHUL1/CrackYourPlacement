class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();

        for(int i=0; i<k; i++)
            sum += cardPoints[i];
        
        int maxSum = sum;

        for(int i=0; i<k; i++)
        {
            sum = sum - cardPoints[k-1-i] + cardPoints[n-1-i];
            maxSum = max(maxSum, sum);
        }
        return maxSum;

    }
};
