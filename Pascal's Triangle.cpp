class Solution {
public:
    vector<int> generateRow(int r)
    {
        vector<int> ans;
        int temp =1;
        ans.push_back(temp);
        for(int i=1;i<r;i++)
        {
            temp *= r-i;
            temp /= i;
            ans.push_back(temp);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++)
        {
            vector<int> temp = generateRow(i);
            ans.push_back(temp);
        }
        return ans;
    }
};