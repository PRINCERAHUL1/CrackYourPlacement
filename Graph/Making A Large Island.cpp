class Solution {
public:

    bool check(int i, int j, int r, int c)
    {
        if(i<0 || j<0 || i>=r || j>=c)
            return false;
        
        return true;
    }

    void dfs(int id, int i, int j, vector<vector<int>> &grid, int r, int c, int &count)
    {
        if(i<0 || j<0 || i>=r || j>= c)
            return;
        
        if(grid[i][j] > 1 || grid[i][j] == 0)
            return;
        
        grid[i][j] = id;
        dfs(id, i+1, j, grid, r, c, count);
        dfs(id, i-1, j, grid, r, c, count);
        dfs(id, i, j+1, grid, r, c, count);
        dfs(id, i, j-1, grid, r, c, count);

        count++;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        map<int, int> m;
        int id=2;
        int maxi=INT_MIN;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j] == 1)
                {
                    int count=0;
                    dfs(id, i, j, grid, r, c, count);
                    m.insert({id, count});
                    id++;
                }
            }
        }

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j] == 0)
                {
                    int sum=0;
                    set<int> s;
                    if(check(i-1, j, r, c) && grid[i-1][j]>1 && s.find(grid[i-1][j]) == s.end())
                    {
                        s.insert(grid[i-1][j]);
                        auto it = m.find(grid[i-1][j]);
                        sum += it->second;
                    }

                    if(check(i+1, j, r, c) && grid[i+1][j]>1 && s.find(grid[i+1][j]) == s.end())
                    {
                        s.insert(grid[i+1][j]);
                        auto it = m.find(grid[i+1][j]);
                        sum += it->second;
                    }

                    if(check(i, j+1, r, c) && grid[i][j+1]>1 && s.find(grid[i][j+1]) == s.end())
                    {
                        s.insert(grid[i][j+1]);
                        auto it = m.find(grid[i][j+1]);
                        sum += it->second;
                    }

                    if(check(i, j-1, r, c) && grid[i][j-1]>1 && s.find(grid[i][j-1]) == s.end())
                    {
                        s.insert(grid[i][j-1]);
                        auto it = m.find(grid[i][j-1]);
                        sum += it->second;
                    }

                    maxi = max(maxi, sum+1);
                }
            }
        }

        return (maxi==INT_MIN) ? r*c : maxi;
    }
};
