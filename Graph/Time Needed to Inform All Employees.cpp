class Solution {
public:

    vector<vector<int>> list;

    int dfs(int headID, vector<int> &informTime)
    {
        int maximum=0;

        for(auto i : list[headID])
            maximum = max(maximum, dfs(i, informTime));
        
        return informTime[headID] + maximum;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        list.resize(n);

        for(int i=0;i<(int)manager.size(); i++)
        {
            if(manager[i] != -1)
                list[manager[i]].push_back(i);
        }

        return dfs(headID, informTime);
    }
};
