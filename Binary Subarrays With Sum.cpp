class Solution {
public:
    int numSubarraySumEqualGoal(vector<int> &nums, int goal)
    {
        if(goal < 0) return 0;
        int n = nums.size();
        int l=0, r=0, count = 0, sum = 0;

        while(r < n)
        {
            sum += nums[r];
            while(sum > goal)
            {
                sum -= nums[l];
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        return numSubarraySumEqualGoal(nums, goal) - numSubarraySumEqualGoal(nums, goal-1);
    }
};