// 请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。
// 执行push、pop和min操作的时间复杂度必须为O(1)。
// 示例： MinStack minStack = new MinStack(); minStack.push(-2); minStack.push(0);
// minStack.push(-3); minStack.getMin();   --> 返回 -3. minStack.pop(); minStack.top
//();      --> 返回 0. minStack.getMin();   --> 返回 -2. Related Topics 栈 
// 👍 34 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

// 双栈法 优化就是 最小值栈不需要存储和数据栈相同长度的数据
// 单栈法 利用 minVal 遍历来维护最小值，但是在单栈中**更新最小值时候**要备份之前的最小值，因为最小值出栈之后你不知道下一个最小值是多少，所以需要存两次
class MinStack {

private:
    stack<int> s;
    stack<int> m;

public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x)
    {
        s.push(x);
        if (m.empty() || x <= m.top()) m.push(x);  // 只有当 x <= m.top()的时候才入栈即可，不用所有的最小值都入栈
    }
    
    void pop()
    {
        if (s.top() == m.top()) m.pop();
        s.pop();

    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//leetcode submit region end(Prohibit modification and deletion)
