class Solution {
public:
    int numSubarraysEqual(vector<int> &nums, int k) 
    {
        int n = nums.size();
        int l = 0, r = 0, count = 0, ans = 0;
        while(r < n)
        {
            if(nums[r] % 2 != 0)
                count++;
            while(count > k)
            {
                if(nums[l] % 2 != 0)
                    count--;
                l++;
            }
            ans += r-l+1;   // Add the number of valid subarrays ending at r
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int> &nums, int k) {
        return numSubarraysEqual(nums, k) - numSubarraysEqual(nums, k-1);
    }
};