// 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数 max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
//
// **若队列为空，pop_front 和 max_value 需要返回 -1 **
//
// 示例 1： 
//
// 输入: 
//["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
//[[],[1],[2],[],[],[]]
//输出: [null,null,null,2,1,2]
// 
//
// 示例 2： 
//
// 输入: 
//["MaxQueue","pop_front","max_value"]
//[[],[],[]]
//输出: [null,-1,-1]
// 
//
// 
//
// 限制： 
//
// 
// 1 <= push_back,pop_front,max_value的总操作数 <= 10000 
// 1 <= value <= 10^5 
// 
// Related Topics 栈 Sliding Window 
// 👍 167 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

// 一刷 2021.01.06
// 二刷 2021.01.07
// 三刷 2021.01.12
// 利用 queue 和 deque
// deque 充当 单调队列
// 思路：
// 1. 需要一个普通队列来存数据
// 2. 需要一个单调队列来存最大值，我们先分析一下 max_value 的情况
// 2.1 如果最后入队列的值 vx 比前面的都大，是不是我们在队列为空之前 max_value 都可以返回 vx 呢？ 答案是肯定的
// 2.2 如果 vx 在中间出现了后面出现的比 vx 小的数据在 单调队列中如何存放呢？ 答案是把前面较小的都压扁，汉诺塔式入队列
// 3. 所以双端队列是 从大到小排序的，后面只要出现比前面任何数字大的，就会把数字小的压扁
// 若队列为空，pop_front 和 max_value 需要返回 -1
// 5 1 2 3 4
// 如果最后一个入队列的数字最大，那么前面的都没用了，秉承这个思路
class MaxQueue
{
    // 队列的最大值
private:
    queue<int> dataQ;
    deque<int> maxQ;  // 单调队列

public:
    MaxQueue()
    {}

    void push_back(int value)
    {
        dataQ.push(value);
        while(!maxQ.empty() && value > maxQ.back())
        {
            maxQ.pop_back();
        }
        maxQ.push_back(value);
    }

    int max_value()
    {
        if (maxQ.empty()) return -1;
        return maxQ.front();
    }

    int pop_front()
    {
        if (dataQ.empty()) return -1;
        int ret = dataQ.front();
        dataQ.pop(); // 这个位置不要忘记
        if (ret == maxQ.front()) maxQ.pop_front();
        return ret;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
//leetcode submit region end(Prohibit modification and deletion)
