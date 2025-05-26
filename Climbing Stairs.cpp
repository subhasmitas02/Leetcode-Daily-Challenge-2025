class Solution {
    public:
        int climbStairs(int n) {
            int prev1=1, prev2=1, curr=0;
            for(int i=2;i<=n;i++)
            {
                curr=prev1+prev2;
                prev2=prev1;
                prev1=curr;
            }
            return prev1;
        }
    };
    
    // TC-> O(n)
    // SC-> O(1) - as not taking any extra dp array
    
    
    //--Approach-1---------------
    //     int climbStairs(int n) {
    //         int dp[n+1];
    //         for(int i=0;i<=n;i++) dp[i]=-1;
    //         dp[0]=1;
    //         dp[1]=1;
    //         for(int i=2;i<=n;i++){
    //             if(dp[i]==-1 && i>0) 
    //                 dp[i] = dp[i-1] + dp[i-2];
    //         }
    //         return dp[n];
    //     }
    // };
    
    // TC -> O(n)
    // SC -> O(n)