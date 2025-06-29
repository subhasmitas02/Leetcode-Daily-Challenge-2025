class Solution {
public:
    int INF=1e9+7;

    int solve(vector<int> &dp, int x){
        if(x==0) return 0;
        if(x==1) return dp[1]=1;
        if(dp[x]!=-1) return dp[x];
        return dp[x]=(2*solve(dp,x-1)+1)%INF;
    }

    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        if(nums[0]>target) return 0;
        vector<int> dp(n+1,-1);
        for(int i=0;i<n;i++){
            int x=nums[i];
            int ind=upper_bound(nums.begin(),nums.end(),target-x)-nums.begin();
            if(ind-1<i) break;
            else cnt=(cnt+solve(dp,ind-i-1))%INF;
            if(2*x <= target) cnt++;
        }
        return cnt;
    }
};