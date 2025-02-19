class Solution {
public:
    bool isPossible(vector<int>& target) {
        // Using MAX HEAP
        priority_queue<int> p(target.begin(), target.end());
        long long sum = 0;
        for (int i = 0; i < target.size(); i++)
            sum += target[i];
        while (p.top() != 1) {
            int top = p.top();
            p.pop();
            int remSum = sum - top;
            if (remSum <= 0 || remSum >= top)
                return false;
            if (top % remSum == 0 && remSum != 1)
                return false;
            top = top % remSum;
            p.push(top);
            sum = remSum + top;
        }
        return true;
    }
};