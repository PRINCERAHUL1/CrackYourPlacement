class Solution {
public:

    bool safe(int r, int c, int n, int m)
    {
        return (r>=0 && r<n && c>=0 && c<m);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ori = image[sr][sc];

        if(ori == color)
            return image;
        
        int n=image.size();
        int m=image[0].size();
        queue<pair<int, int>> q;
        
        image[sr][sc]=color;
        q.push({sr, sc});
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            vector<vector<int>> dir= {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for(int i=0; i<4; i++)
            {
                int newR = r+dir[i][0];
                int newC = c+dir[i][1];

                if(safe(newR, newC, n, m) && image[newR][newC] == ori)
                {
                    image[newR][newC] = color;
                    q.push({newR, newC});
                }
                
            }
        }

        return image;
    }
};
