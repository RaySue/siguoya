// 三合一。描述如何只用一个数组来实现三个栈。
//
// 你应该实现 push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。
// stackNum 表示栈下标，value表示压入的值。
//
// **构造函数会传入一个stackSize参数，代表每个栈的大小。**
//
// 示例1: 
//
//  输入：
//["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
//[[1], [0, 1], [0, 2], [0], [0], [0], [0]]
// 输出：
//[null, null, null, 1, -1, -1, true]
//说明：当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。
// 
//
// 示例2: 
//
//  输入：
//["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
//[[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
// 输出：
//[null, null, null, null, 2, 1, -1, -1]
// 
// Related Topics 设计 
// 👍 20 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

// 一刷 2020.12.30
// base解法 vector<stack<int>>
// 还是先要仔细读题，再coding
// 1. stackNum 表示的是三个stack的 index
// 2. 构造函数会传入一个stackSize参数，代表每个栈的大小，当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素
class TripleInOne1
{
private:

    vector <stack<int>> vs;
    int sz;

public:
    TripleInOne1(int stackSize)
    {
        sz = stackSize;
        for (int i = 0; i < 3; ++i)
        {
            stack<int> s;
            vs.push_back(s);
        }
    }

    void push(int stackNum, int value)
    {
        if (vs[stackNum].size() < sz)
        {
            vs[stackNum].push(value);
        }
    }

    int pop(int stackNum)
    {
        if (vs[stackNum].empty())
        {
            return -1;
        }
        int tmp = vs[stackNum].top();
        vs[stackNum].pop();
        return tmp;
    }

    int peek(int stackNum)
    {
        if (vs[stackNum].empty())
        {
            return -1;
        }
        return vs[stackNum].top();
    }

    bool isEmpty(int stackNum)
    {
        return vs[stackNum].empty();
    }
};


// 一刷 2020.12.30 更优的解法
// 仔细读题，你可以发现我们有 stackSize 来对每个栈进行限制，所以我们完全可以利用一个vector<int> 来完成这个事情
// 配合三个指针分别指向三个分区的最后一个元素的位置
// 解题步骤：
// 1. 先初始化我们的 vs 的长度(3 * sz)
// 2. push 之前我们需要先判断一下该 stackNum 的指针是否还有空间，如果没有空间，那么什么也不做，否则对 指针位置赋值后，指针后移（注意）
// 3. 由于push之后的指针都指向了下一个元素，所以 pop 的时候，我们需要先对指针进行左移一位，再pop
// 4. 同理 peek 的时候，也需要返回的是 当前指针的前一个位置
class TripleInOne
{
private:

    vector<int> vs;
    int pointers[3];
    int sz;

public:
    TripleInOne(int stackSize)
    {
        sz = stackSize;
        vs.resize(3 * sz);
        for (int i = 0; i < 3; ++i)
        {
            pointers[i] = sz * i;
        }
    }

    void push(int stackNum, int value)
    {
        if (pointers[stackNum] < (stackNum + 1) * sz)
        {
            vs[pointers[stackNum]] = value;
            pointers[stackNum]++;
        }
    }

    int pop(int stackNum)
    {
        if (pointers[stackNum] <= stackNum * sz) return -1;
        pointers[stackNum]--;
        int tmp = vs[pointers[stackNum]];
        return tmp;
    }

    int peek(int stackNum)
    {
        if (pointers[stackNum] <= stackNum * sz) return -1;
        int tmp = vs[pointers[stackNum] - 1];
        return tmp;
    }

    bool isEmpty(int stackNum)
    {
        return pointers[stackNum] <= stackNum * sz;
    }
};


/**
["TripleInOne", "push", "pop", "push", "push", "pop", "push", "push", "isEmpty", "pop", "peek", "push", "peek", "isEmpty", "peek", "pop", "push", "isEmpty", "pop", "peek", "peek", "pop", "peek"]
[[18], [2, 40], [2], [0, 44], [1, 40], [0], [1, 54], [0, 42], [0], [1], [1], [0, 56], [2], [0], [2], [2], [1, 15], [1], [1], [0], [2], [0], [0]]



*/








/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
//leetcode submit region end(Prohibit modification and deletion)
