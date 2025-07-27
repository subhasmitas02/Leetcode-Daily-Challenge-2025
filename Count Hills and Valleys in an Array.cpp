class Solution {
public:
    int countHillValley(vector<int>& nums) {
       int n = nums.size(), count = 0, prev = 0;
       for(int i=1;i<n-1;i++)
       {
            if(nums[i] != nums[i+1])
            {
                if(nums[i] > nums[prev] && nums[i] > nums[i+1] || nums[i] < nums[prev] && 
                nums[i] < nums[i+1])
                {
                    count++;
                }
                prev = i;
            }
       }
       return count;
    }
};