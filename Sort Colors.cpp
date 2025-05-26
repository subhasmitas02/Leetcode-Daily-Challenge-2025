class Solution {
    public:
        void sortColors(vector<int>& nums) {
        //Using Dutch National Flag Algo (using 3 pointers as low, mid, high)----------------where only in one traversal we can sort the array.
    
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid], nums[high]);
                high--;
               
            }
            else
                mid++;
        }
    
        // in this algo time complexity -> O(N)
        // space complexity -> O(1)
    
    
    
    
    
    
    
    
    
    
    
    
    
    
            /* vector<int> ans;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0)
                    ans.push_back(nums[i]);
            }
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==1)
                    ans.push_back(nums[i]);
            }
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==2)
                    ans.push_back(nums[i]);
            }
            nums=ans;
            */
            
            
        }
    };