class Solution {
public:
    void dfs(int row, int col, int rowSize, int colSize, vector<vector<char>> &board, vector<vector<int>> &visited)
    {
        visited[row][col] = 1;
        board[row][col] = '*';

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i=0;i<4;i++)
        {
            int newRow = row + delrow[i];
            int newCol = col + delcol[i];

            if((newRow>=0 && newRow <rowSize) && (newCol >=0 && newCol <colSize) && !visited[newRow][newCol] && board[newRow][newCol] == 'O')
                dfs(newRow, newCol, rowSize, colSize, board, visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        for(int i=0;i<row;i++) // checking left & right borders
        {
            if(board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, row, col, board, visited);

            if(board[i][col-1] == 'O' && !visited[i][col-1])
                dfs(i, col-1, row, col, board, visited);
        }

        for(int j=0;j<col;j++) // checking top & bottom borders
        {
            if(board[0][j] == 'O' && !visited[0][j])
                dfs(0, j, row, col, board, visited);

            if(board[row-1][j] == 'O' && !visited[row-1][j])
                dfs(row-1, j, row, col, board, visited);
        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j] =='*')
                    board[i][j] = 'O';

                else if(board[i][j] =='O')
                    board[i][j] = 'X';
            }
        }
    }
};