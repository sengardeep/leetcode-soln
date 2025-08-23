class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl(heights.size(), -1); // Nearest Smallest on left
        vector<int> nsr(heights.size(),
                        heights.size()); // Nearest Smallest on right

        // NSL
        stack<int> st1;
        for (int i = 0; i < heights.size(); i++) {
            while ((!st1.empty()) && heights[st1.top()] >= heights[i])
                st1.pop();

            if (!(st1.empty()))
                nsl[i] = st1.top();
            st1.push(i);
        }

        // NSR
        stack<int> st2;
        for (int i = heights.size() - 1; i >= 0; i--) {
            while ((!st2.empty()) && heights[st2.top()] >= heights[i])
                st2.pop();

            if (!(st2.empty()))
                nsr[i] = st2.top();
            st2.push(i);
        }

        long long ans = INT_MIN;

        for (int i = 0; i < heights.size(); i++) {
            int maxWidth = nsr[i] - nsl[i] - 1;
            long long maxArea = heights[i] * maxWidth;
            ans = max(ans, maxArea);
        }

        return (int)ans;
    }
};