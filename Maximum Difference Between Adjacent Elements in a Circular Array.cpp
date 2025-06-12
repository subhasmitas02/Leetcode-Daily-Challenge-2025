class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size(), maxdiff = 0;
        for(int i=1;i<n;i++)
        {
            maxdiff = max(maxdiff, abs(nums[i]-nums[i-1])); 
        }
        maxdiff = max(maxdiff, abs(nums[n-1]-nums[0]));
        return maxdiff;
    }
};