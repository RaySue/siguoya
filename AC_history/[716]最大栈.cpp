//设计一个最大栈，支持 push、pop、top、peekMax 和 popMax 操作。 
//
// 
//
// 
// push(x) -- 将元素 x 压入栈中。 
// pop() -- 移除栈顶元素并返回这个值。 
// top() -- 返回栈顶元素。 
// peekMax() -- 返回栈中最大元素。 
// popMax() -- 返回栈中最大的元素，并将其删除。如果有多个最大元素，只要删除最靠近栈顶的那个。 
// 
//
// 
//
// 样例 1: 
//
// MaxStack stack = new MaxStack();
//stack.push(5); 
//stack.push(1);
//stack.push(5);
//stack.top(); -> 5
//stack.popMax(); -> 5
//stack.top(); -> 1
//stack.peekMax(); -> 5
//stack.pop(); -> 1
//stack.top(); -> 5
// 
//
// 
//
// 注释: 
//
// 
// -1e7 <= x <= 1e7 
// 操作次数不会超过 10000。 
// 当栈为空的时候不会出现后四个操作。 
// 
//
// 
// Related Topics 设计 
// 👍 48 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

// base 解法 双栈法 push、pop、top、peekMax、popMax
// 此题的一个难点在于 popMax
// 1. sta 是正常的存储栈
// 2. maxSta 栈顶只存最大值，所以 push 方法注意一下
// 3. 这里只说popMax，因为其余的方法都与普通栈无异，popMax较为复杂，我们需要在 sta 中从栈顶开始找到最大值，并删除，把每个元素临时存储到tmpSta中，
// 找的过程也要一起删除 maxSta 对应的元素，找到sta 对应的最大值后，删除，然后将tmpSta的结果存储到sta和maxSta中即可
// base 解法 各个方法的复杂度分析
// push O(1)
// pop O(1)
// top O(1)
// peekMax O(1)
// popMax O(n)
//     // 这个函数，是难点
//    // 利用临时栈来存储数据
//    // 1. while 如果当前的栈顶元素不是最大值，那么两个栈同时 pop()，并利用 tmpStack 存sta的结果
//    // 2. 我们现在的栈顶元素就是最大值了，调用 this->pop 方法，两个栈同时删除最大值
//    // 3. 然后将 tmp栈 的结果存入到 sta，同时存入maxSta，这样就得到了顺序的最大值了
class MaxStack1
{

private:
    stack<int> sta;
    stack<int> maxSta;


public:
    /** initialize your data structure here. */
    MaxStack1()
    {

    }

    void push(int x)
    {
        sta.push(x);
        if (maxSta.empty()) maxSta.push(x);
        else
        {
            if (maxSta.top() > x) maxSta.push(maxSta.top());
            else maxSta.push(x);
        }
    }

    int pop()
    {
        int ret = sta.top();
        maxSta.pop();
        sta.pop();
        return ret;
    }

    int top()
    {
        return sta.top();
    }

    int peekMax()
    {
        return maxSta.top();
    }


    int popMax()
    {
        stack<int> tmpSta;
        int ret = this->peekMax();
        while (this->top() != ret)
        {
            tmpSta.push(this->pop());
        }
        this->pop();
        while (!tmpSta.empty())
        {
            this->push(tmpSta.top());
            tmpSta.pop();
        }
        return ret;
    }

};


// 之前的解法 popMax 的复杂度较高，导致最终的得分较低，如果对时间要求更严格，就不能用双栈 O(N) 来解决了
// 双链表 + tree map 解法
// 利用双链表在已知位置的情况下 删除 添加 都是 O(1) 的性质
// 以及 tree map 存储有序的性质，并利用 tree map 来存储双链表的位置，就可以达到所有操作的 O(1) 复杂度；
// 二刷 2021.01.07
class MaxStack
{
private:
    list<int> l;   // 双链表
    map<int, vector<list<int>::iterator>> mp;  // 结合 treemap

public:
    /** initialize your data structure here. */
    // 最大栈
    MaxStack()
    { }
    // end 是越界的, 所以 push_front , begin
    void push(int x)
    {
        l.push_front(x);
        mp[x].push_back(l.begin());
    }

    int pop()
    {
        int ret = l.front();
        mp[ret].pop_back();
        if (mp[ret].empty()) mp.erase(ret);
        l.pop_front();
        return ret;
    }

    int top()
    {
        return l.front();
    }

    int peekMax()
    {
        int ret = mp.rbegin()->first;
        return ret;
    }

    int popMax()
    {
        int ret = this->peekMax();
        auto it = mp[ret].back();
        l.erase(it);
        mp[ret].pop_back();
        if (mp[ret].empty()) mp.erase(ret);
        return ret;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
//leetcode submit region end(Prohibit modification and deletion)
