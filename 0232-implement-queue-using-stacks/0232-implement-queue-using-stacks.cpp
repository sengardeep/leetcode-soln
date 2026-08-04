class MyQueue {
public:
    stack<int> stack, temp;
    MyQueue() {}

    void push(int x) { stack.push(x); }

    int pop() {
        if (!temp.empty()) {
            int ans = temp.top();
            temp.pop();
            return ans;
        }
        while (!stack.empty()) {
            temp.push(stack.top());
            stack.pop();
        }
        int ans = temp.top();
        temp.pop();
        return ans;
    }

    int peek() {
        if (!temp.empty()) {
            int ans = temp.top();
            return ans;
        }
        while (!stack.empty()) {
            temp.push(stack.top());
            stack.pop();
        }
        int ans = temp.top();
        return ans;
    }

    bool empty() { return stack.empty() && temp.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */