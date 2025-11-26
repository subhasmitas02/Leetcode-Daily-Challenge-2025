class Solution{
    public:
    void bfs(int row, int col, int rowSize, int colSize, vector<vector<int>> &copyImage, vector<vector<int>> &visited, int currColor, int newColor)
    {
        visited[row][col] = 1;
        copyImage[row][col]= newColor;
        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty())
        {
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};

            for(int i=0;i<4;i++)
            {
                int newRow = currRow + delrow[i];
                int newCol = currCol + delcol[i];

                if((newRow >= 0 && newRow < rowSize) && (newCol >= 0 && newCol < colSize) && (copyImage[newRow][newCol] == currColor) && !visited[newRow][newCol])
                {
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = 1;
                    copyImage[newRow][newCol]= newColor;
                }
                    
            }
        }

        
    }

    // void dfs(int row, int col, int rowSize, int colSize, vector<vector<int>> &copyImage, vector<vector<int>> &visited, int currColor, int newColor)
    // {
    //     visited[row][col] = 1;
    //     copyImage[row][col] = newColor;

    //     int delrow[] = {-1, 0, 1, 0};
    //     int delcol[] = {0, 1, 0, -1};

    //     for(int i=0;i<4;i++)
    //     {
    //         int newRow = row + delrow[i];
    //         int newCol = col + delcol[i];

    //         if((newRow >= 0 && newRow < rowSize) && (newCol >= 0 && newCol < colSize) && (copyImage[newRow][newCol] == currColor) && !visited[newRow][newCol])
    //             dfs(newRow, newCol, rowSize, colSize, copyImage, visited, currColor, newColor);
    //     }
    // }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        vector<vector<int>> copyImage(row, vector<int>(col, 0));

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                copyImage[i][j] = image[i][j];
            }
        }
        int currColor = image[sr][sc];
        vector<vector<int>> visited(row, vector<int>(col, 0));
        if(!visited[sr][sc])
            bfs(sr, sc, row, col, copyImage, visited, currColor, newColor);
        return copyImage;
    }
};


//tried dfs and bfs to solve