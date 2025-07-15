class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = 0;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                int ele = heights[st.top()];
                st.pop();
                int nse = i, pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, ele*(nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty())
        {
            int ele = heights[st.top()];
            st.pop();
            int nse = n, pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, ele*(nse - pse - 1));
        }

        return maxArea;
    }
};