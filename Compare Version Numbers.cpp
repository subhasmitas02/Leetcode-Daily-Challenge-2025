class Solution {
public:
    vector<string> getTokens(string version)
    {
        vector<string> result;
        string token = "";
        stringstream ss(version);

        while(getline(ss, token, '.'))
            result.push_back(token);

        return result;
    }
    int compareVersion(string version1, string version2) {
        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);

        int n1 = v1.size(), n2 = v2.size(), i = 0;
    
        while(i<n1 || i<n2)
        {
            int a = i<n1 ? stoi(v1[i]) : 0;
            int b = i<n2 ? stoi(v2[i]) : 0;

            if(a < b) return -1;
            else if(a > b) return 1;
            else if(a == b)
                i++;
        }
        return 0;
    }
};