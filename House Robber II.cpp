class Solution {
    public:
        int findMaxSum(vector<int> &nums)
        {
            int prev1=nums[0], prev2=0, curr;
            for(int i=1;i<nums.size();i++)
            {
                int pick = nums[i];
                if(prev2>=0) pick+=prev2;
                int not_pick = 0 + prev1;
                curr = max(pick, not_pick);
                prev2=prev1;
                prev1=curr;
            }
            return prev1;
        }
        int rob(vector<int>& nums) {
            int n=nums.size();
            if(n==1) return nums[0]; //if having one element in array
            vector<int> temp1, temp2;
            for(int i=0;i<n;i++)
            {
                if(i!=0) temp1.push_back(nums[i]);
                if(i!=n-1) temp2.push_back(nums[i]);
            }
            return max(findMaxSum(temp1), findMaxSum(temp2));
        }
    };