class Solution {
public:

    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> b(n*n, -1);

        for(int i=n-1, c=0; i>=0; i--)
        {
            if((n-1-i)%2 == 0)
            {
                for(int j=0; j<n && c<b.size(); j++)
                {
                    if(board[i][j] != -1)
                        b[c] = board[i][j]-1;
                
                    c++;
                }
            }
            else
            {
                for(int j=n-1; j>=0 && c<b.size(); j--)
                {
                    if(board[i][j] != -1)
                        b[c] = board[i][j]-1;
                
                    c++;
                }
            }
        }

        vector<int> dist(n*n, INT_MAX);
        queue<int> q;

        q.push(0);
        dist[0]=0;

        while(!q.empty())
        {
            int cur=q.front();
            q.pop();

            for(int i=1; i<=6 && cur+i < n*n; i++)
            {
                int next=b[cur+i] != -1? b[cur+i] : cur+i;

                if(dist[next] == INT_MAX)
                {
                    dist[next] = dist[cur]+1;
                    q.push(next);
                }
            }
        }

        return dist[n*n -1] == INT_MAX ? -1 : dist[n*n -1];
    }
};
