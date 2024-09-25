class Solution {
public:

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    bool boundary(int i, int j, int r, int c)
    {
        return (i<r && j<c && i>=0 && j>=0);
    }

    void dfs(int i, int j, int r, int c, vector<vector<int>> &grid)
    {
        if(i>=r || j>=c || i<0 || j<0 || grid[i][j]==0 || grid[i][j]==2)
            return;
        
        grid[i][j]=2;

        for(int x=0; x<4; x++)
        {
            int newi=i+dx[x];
            int newj=j+dy[x];
            dfs(newi, newj, r, c, grid);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int, int>> q;

        int change=0;
        bool b=false;

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j])
                {
                    dfs(i, j, r, c, grid);
                    b=true;
                    break;
                }
            }

            if(b)
                break;
        }

        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
               if(grid[i][j]==2)
                q.push({i,j});
            }
        }

        while(!q.empty())
        {
            change++;

            int s=q.size();

            while(s--)
            {
                auto temp=q.front();
                q.pop();

                for(int x=0; x<4; x++)
                {
                    int newi=temp.first+dx[x];
                    int newj=temp.second+dy[x];
                    
                    if(boundary(newi, newj, r, c))
                    {
                        if(grid[newi][newj]==0)
                        {
                            grid[newi][newj]=2;
                            q.push({newi, newj});
                        }

                        if(grid[newi][newj]==1)
                            return change-1;
                    }
                }
            }
        }

        return 0;
    }
};
