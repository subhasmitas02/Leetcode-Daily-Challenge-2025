class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> leftarray(n, 0), rightarray(n,0);
        leftarray[0]=1;
        rightarray[n-1]=1;
        for(int i=1;i<n;i++)
        {
            if(ratings[i] <= ratings[i-1]) leftarray[i]=1;
            else leftarray[i]=leftarray[i-1]+1;   
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i] <= ratings[i+1]) rightarray[i]=1;
            else rightarray[i]=rightarray[i+1]+1;   
        }
        int mincandy=0;
        for(int i=0;i<n;i++)
        {
            mincandy += max(leftarray[i], rightarray[i]);
        }
        return mincandy;
        
    }
};