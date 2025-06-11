class Solution {
public:
// 4) Space Optimization Approach ----------------------------------
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), totalSum=0;
        for(int i=0;i<n;i++) totalSum += nums[i];
        if((totalSum + target)<0 || (totalSum+target)%2!=0) return 0;

        int targetdiff = (totalSum + target)/2;
        vector<int> prev(targetdiff+1, 0);

        // Base case initialization
        prev[0] = 1;  // There is 1 way to make sum 0 (by picking no elements)

        if (nums[0] == 0) {
            prev[0] = 2; // 2 ways to make sum 0 with nums[0] = 0: {} and {0}
        } else if (nums[0] <= targetdiff) {
            prev[nums[0]] = 1; // One way to make sum nums[0] if nums[0] <= targetdiff
        }

        for(int i=1;i<n;i++)
        {
            vector<int> temp(targetdiff + 1, 0);
            for(int j=0;j<=targetdiff;j++)
            {
                int notTake = prev[j];
                int take = 0;
                if(nums[i]<=j) take = prev[j-nums[i]];
                temp[j] = take + notTake;
            }
            prev = temp;
        }
        return prev[targetdiff];
    }
};
//TC -> O(n*targetdiff) + O(n) for calculating totalSum
//SC -> O(targetdiff)


// 3) Tabulation Approach ----------------------------------
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size(), totalSum=0;
//         for(int i=0;i<n;i++) totalSum += nums[i];
//         if((totalSum + target)<0 || (totalSum+target)%2!=0) return 0;

//         int targetdiff = (totalSum + target)/2;
//         vector<vector<int>> dp(n, vector<int>(targetdiff+1, 0));

//         // Base case initialization
//         dp[0][0] = 1;  // There is 1 way to make sum 0 (by picking no elements)

//         if (nums[0] == 0) {
//             dp[0][0] = 2; // 2 ways to make sum 0 with nums[0] = 0: {} and {0}
//         } else if (nums[0] <= targetdiff) {
//             dp[0][nums[0]] = 1; // One way to make sum nums[0] if nums[0] <= targetdiff
//         }

//         for(int i=1;i<n;i++)
//         {
//             for(int j=0;j<=targetdiff;j++)
//             {
//                 int notTake = dp[i-1][j];
//                 int take = 0;
//                 if(nums[i]<=j) take = dp[i-1][j-nums[i]];
//                 dp[i][j] = take + notTake;
//             }
//         }
//         return dp[n-1][targetdiff];
//     }
// };
//TC -> O(n*targetdiff) + O(n) for calculating totalSum
//SC -> O(n*targetdiff)



// // 2) Memoization Approach ----------------------------------
//     int f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
//     {
//         if(ind==0)
//         {
//             if(target==0 && nums[0]==0) return 2;
//             if(target==0 || nums[0]==target) return 1;
//             else return 0;
//         }

//         if(dp[ind][target]!=-1) return dp[ind][target];

//         int notTake = f(ind-1, target, nums, dp);
//         int take = 0;
//         if(nums[ind]<=target) take = f(ind-1, target-nums[ind], nums, dp);
//         return dp[ind][target] = take + notTake;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size(), totalSum=0;
//         for(int i=0;i<n;i++) totalSum += nums[i];
//         if((totalSum + target)<0 || (totalSum+target)%2!=0) return 0;

//         int targetdiff = (totalSum + target)/2;
//         vector<vector<int>> dp(n, vector<int>(targetdiff+1, -1));
//         return f(n-1, (totalSum+target)/2, nums, dp);
//     }
// };
//TC -> O(n*targetdiff) + O(n) for calculation totalSum  
//SC -> O(n*targetdiff) + O(n) for recursion stack space 


//  1) Recursive Approach ----------------------------------
//     int f(int ind, int target, vector<int> &nums)
//     {
//         if(ind==0)
//         {
//             if(target==0 && nums[0]==0) return 2;
//             if(target==0 || nums[0]==target) return 1;
//             else return 0;
//         }
//         int notTake = f(ind-1, target, nums);
//         int take = 0;
//         if(nums[ind]<=target) take = f(ind-1, target-nums[ind], nums);
//         return take + notTake;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n = nums.size(), totalSum=0;
//         for(int i=0;i<n;i++) totalSum += nums[i];
//         if(totalSum<0 || (totalSum+target)%2!=0) return 0;
//         return f(n-1, (totalSum+target)/2, nums);
//     }
// };

// TC -> O(2^n) + O(n) for calculating totalSum
// SC -> O(n) recursion stack space 