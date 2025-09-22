class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size(), maxFrequency = 0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        {
            maxFrequency = max(maxFrequency, it.second);
        }
        int count = 0;
        for(auto it:mp)
        {
            if(it.second == maxFrequency)
                count++;
        }
        return count*maxFrequency;
    }
};