class Solution {
public:
//   4)Space Optimization Approach ---------
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<int> prev(row,0);

        for(int col=0;col<row;col++)
        {
            prev[col] = triangle[row-1][col];
        }
        for(int i=row-2; i>=0; i--)
        {
            vector<int> temp(row,0);
            for(int j=i;j>=0;j--)
            {
                int down = prev[j];
                int diagonal = prev[j+1];
                temp[j] = triangle[i][j] + min(down, diagonal);
            }
            prev = temp;
        }
        return prev[0];
    }
};

//TC -> O(n*n)
//SC -> O(n) 