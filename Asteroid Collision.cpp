class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> res;

        for(int i=0;i<n;i++)
        {
            if(asteroids[i] > 0)       // if +ve elements
                res.push_back(asteroids[i]);
            else                       // if -ve elements
            {
                while(!res.empty() && res.back() > 0 && res.back() < abs(asteroids[i]))
                    res.pop_back();
                if(!res.empty() && res.back() > 0 && res.back() == abs(asteroids[i]))
                    res.pop_back();
                else if(res.empty() || res.back() < 0)
                    res.push_back(asteroids[i]);
            }
        }
        return res;
    }
};
