class Solution {
public
//----4) Space Optimization Approach---------------------------
    int uniquePaths(int m, int n) {
        vectorint prev(n,-1); 
        for(int r=0;rm;r++)
        {
            vectorint temp(n,-1); 
            for(int c=0;cn;c++)
            {
                if(r==0 && c==0) temp[c]=1;
                else
                {
                    int left=0, up=0;
                    if(c0) left = temp[c-1];
                    if(r0) up = prev[c];
                    temp[c] = left + up;
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};