class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            unordered_map<int,int> m;
            for(auto it:answers)
            {
                m[it]++;
            }
            int total=0;
            for(auto it:m)
            {
                total+= ceil((double)it.second/(it.first+1)) * (it.first+1);
            }
            return total;
        }
    };