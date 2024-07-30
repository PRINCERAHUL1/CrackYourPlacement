class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));;
        solve(res, board, 0, n);
        return res;
    }

    void solve(vector<vector<string>> &res, vector<string> &board, int row, int n)
    {
        if(n == row)
        {
            res.push_back(board);
            return;
        }

        for(int col = 0; col<n; col++)
        {
            if(safe(board, row, col, n))
            {
                board[row][col] = 'Q';
                solve(res, board, row+1, n);
                board[row][col] = '.';
            }
        }

    }

    bool safe(vector<string> &board, int row, int col, int n)
    {
        for(int i=0; i<row; i++)
        {
            if(board[i][col] == 'Q')
            {
                return false;
            }
        }

    int i=row;
	int j=col;
	while(i>=0 && j>=0)
	{
		if(board[i][j] == 'Q')
		{
			return false;
		}
		i--;
		j--;
	}
	
	i=row;
	j=col;
	while(i>=0 && j<n)
	{
		if(board[i][j] == 'Q')
		{
			return false;
		}
		i--;
		j++;
	}
	
	return true;
    }

};
