class Solution {
    public:
        int rob(vector<int>& nums) {
            int prev1=nums[0], prev2=0, curr;
            for(int i=1;i<nums.size();i++)
            {
                int pick = nums[i];
                if(i-2>=0) pick += prev2;
                
                int not_pick = 0 + prev1;
                curr = max(pick, not_pick);
                prev2=prev1;
                prev1=curr;
            }
            return prev1;
        }
    };