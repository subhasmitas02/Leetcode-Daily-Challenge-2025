class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size(), max1=0;
        for(int i=0;i<n;i++)
            max1 = max(max1, arr[i]);

        vector<int> hash(max1+1, 0);
        for(int i=0;i<n;i++)
        {
            hash[arr[i]]++;
        }
        int largestLuckynum = -1;
        for(int i=1;i<hash.size();i++)
        {
            if(hash[i]==i){
                largestLuckynum = max(i, largestLuckynum);
            }
        }
        return largestLuckynum;

    }
};