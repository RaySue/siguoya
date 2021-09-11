//给定一个整数数据流和一个窗口大小，根据该滑动窗口的大小，计算其所有整数的移动平均值。 
//
// 示例: 
//
// MovingAverage m = new MovingAverage(3);
//m.next(1) = 1
//m.next(10) = (1 + 10) / 2
//m.next(3) = (1 + 10 + 3) / 3
//m.next(5) = (10 + 3 + 5) / 3
// 
//
// 
// Related Topics 设计 队列 
// 👍 31 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class MovingAverage
{
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : maxSize(size)
    {

    }

    double next(int val)
    {
        if (buffer.size() == maxSize)
        {
            pre -= buffer.front();
            buffer.pop();
            pre += val;
            buffer.push(val);
            return pre * 1.0 / maxSize;
        } else
        {
            pre += val;
            buffer.push(val);
            return pre * 1.0 / buffer.size();
        }

    }

private:
    int maxSize;
    int pre = 0;
    queue<int> buffer;

};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
//leetcode submit region end(Prohibit modification and deletion)
