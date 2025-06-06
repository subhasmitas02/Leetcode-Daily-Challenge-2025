class Solution {
public:
// 4)Space Optimization ----------------------------------------
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size(), col=matrix[0].size(), minSum=INT_MAX;
        vector<int> prev(col,0);
        for(int j=0;j<col;j++)         // base case filling the last row
        {
            prev[j] = matrix[row-1][j];
        }

        for(int i=row-2;i>=0;i--)     //filling the rest 
        {
            vector<int> temp(col,0);
            for(int j=col-1;j>=0;j--)
            {
                int down=INT_MAX, right_diagonal=INT_MAX, left_diagonal=INT_MAX;
                down = prev[j];
                if(j<col-1) right_diagonal = prev[j+1];
                if(j>0) left_diagonal = prev[j-1];
                temp[j] = matrix[i][j] + min({down, right_diagonal, left_diagonal});
            }
            prev = temp;
        }
        for(int j=0;j<col;j++)
        {
            minSum = min(minSum, prev[j]);
        }
        return minSum;
    }
};
// TC -> O(m*n)
// SC -> O(n)