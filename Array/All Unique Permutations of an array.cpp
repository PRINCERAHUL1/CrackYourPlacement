class Solution {
  public:
    void permutation(int i, int n, vector<int> r, vector<vector<int>> &answer, vector<int> &arr, bool u[]) 
    {
        if (i == n) 
        {
            answer.push_back(r);
            return;
        }
        
        for (int j = 0; j < n; j++) {
            if (!u[j]) 
            {
                if (j > 0 && arr[j] == arr[j - 1] && !u[j - 1])
                    continue;
                    
                r.push_back(arr[j]);
                u[j] = true;
                permutation(i + 1, n, r, answer, arr, u);
                u[j] = false;
                r.pop_back();
            }
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
        vector<vector<int>> answer;
        vector<int> r;
        bool u[n];
        
        for (int i = 0; i < n; i++)
            u[i] = false;
        
        sort(arr.begin(), arr.end());
        
        permutation(0, n, r, answer, arr, u);
        
        return answer;
    }
};
