class Solution {
public
   long long count = 0;
   void merge(vectorint &nums, int low, int mid, int high)
   {
        int n = nums.size();
        int left = low, right = mid + 1;
        vectorint temp;

        while(left = mid && right= high)
        {
            if(nums[left] = nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                count += (mid - left + 1);     as nums[left]  nums[right] that time
                temp.push_back(nums[right]);
                right++;
            }
        }

        if remaining from left part
        while(left = mid)
        {
            temp.push_back(nums[left]);
            left++;
        }

        if remaining from right part
        while(right = high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for(int i=low; i=high; i++)
        {
            nums[i] = temp[i-low];
        }

   }
   void mergeSort(vectorint &nums, int low, int high)
   {
         edge case
        if(low = high) return;

        int mid = (low + high)  2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
   }
   long long int numberOfInversions(vectorint nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return count;
    }
};