class Solution {
public:
//4) Space Optimization Approach-------
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int rowSize=obstacleGrid.size(), colSize= obstacleGrid[0].size();
      vector<int> prev(colSize, -1);
      for(int i=0;i<rowSize;i++)
      {
        vector<int> temp(colSize, -1);
        for(int j=0;j<colSize;j++)
        {
            if(i>=0 && j>=0 && obstacleGrid[i][j]==1){   // for obstacle case
                temp[j]=0; 
                continue;
            } 
            if(i==0 && j==0) temp[j]=1;
            else{
                int left =0, up=0;
                if(i>0) up = prev[j];
                if(j>0) left = temp[j-1];
                temp[j]=up+left;
            }
        }
        prev = temp;
      }
      return prev[colSize-1]; 
    }
};