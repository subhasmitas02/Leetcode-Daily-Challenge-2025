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


// 3) Tabulation Approach --------------------
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int row=triangle.size();
//         vector<vector<int>> dp(row, vector<int>(row,0));

//         for(int col=0;col<row;col++)
//         {
//             dp[row-1][col] = triangle[row-1][col];
//         }
//         for(int i=row-2; i>=0; i--)
//         {
//             for(int j=i;j>=0;j--)
//             {
//                 int down = dp[i+1][j];
//                 int diagonal = dp[i+1][j+1];
//                 dp[i][j] = triangle[i][j] + min(down, diagonal);
//             }
//         }
//         return dp[0][0];
//     }
// };

//TC -> O(n*n)
//SC -> O(n*n) for 2D DP matrix

//   2)Memoization------------------
//     int f(int i, int j, int sum, vector<vector<int>>& triangle, vector<vector<int>> &dp)
//     {
//         int n=triangle.size();
//         if(i==n-1) return triangle[n-1][j];

//         if(dp[i][j] != -1) return dp[i][j];

//         int down = f(i+1, j, sum, triangle, dp);
//         int diagonal = f(i+1, j+1, sum, triangle, dp);
//         sum = triangle[i][j] + min(down, diagonal);

//         return dp[i][j]=sum;
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int row=triangle.size(), sum=0;
//         vector<vector<int>> dp(row, vector<int>(row,-1));
//         return f(0,0,sum, triangle, dp);
//     }
// };

// //TC -> O(n*n)
// //SC -> O(n*n) for 2d dp matrix + O(n) for recursion stack space