// 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，
// 那么中位数就是所有数值排序之后位于中间的数值。
// 如果从数据流中读出偶数个数值，那么中位数就是所有数
// 值排序之后中间两个数的平均值。
//
// 例如， 
//
// [2,3,4] 的中位数是 3 
//
// [2,3] 的中位数是 (2 + 3) / 2 = 2.5 
//
// 设计一个支持以下两种操作的数据结构： 
//
// 
// void addNum(int num) - 从数据流中添加一个整数到数据结构中。 
// double findMedian() - 返回目前所有元素的中位数。 
// 
//
// 示例 1： 
//
// 输入：
//["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
//[[],[1],[2],[],[3],[]]
//输出：[null,null,null,1.50000,null,2.00000]
// 
//
// 示例 2： 
//
// 输入：
//["MedianFinder","addNum","findMedian","addNum","findMedian"]
//[[],[2],[],[3],[]]
//输出：[null,null,2.00000,null,2.50000] 
//
// 
// 1 2 3 4 5 0
//   1  2  3  4  5
//
//
// 限制： 
//
// 
// 最多会对 addNum、findMedian 进行 50000 次调用。 
// 
//
// 注意：本题与主站 295 题相同：https://leetcode-cn.com/problems/find-median-from-data-strea
//m/ 
// Related Topics 堆 设计 
// 👍 82 👎 0


//leetcode submit region begin(Prohibit modification and deletion)


// 我的思路： 插入排序
// 每次新来一个元素，从头到尾判断，该元素需要插在哪里
// 正常逻辑求取中位数


//class MedianFinder1
//{
//
//private:
//
//    vector<int> nums;
//
//public:
//    /** initialize your data structure here. */
//    MedianFinder()
//    {
//
//    }
//
//    // 所有元素向后移动模型
//    void addNum(int num)
//    {
//        if (nums.empty()) nums.push_back(num);
//        else if (num > nums.back()) nums.push_back(num);
//        else
//        {
//            for (int i = 0; i < nums.size(); ++i)
//            {
//                if (num <= nums[i])
//                {
//                    nums.push_back(0);
//                    for (int j = nums.size() - 2; j >= i; --j)
//                    {
//                        nums[j + 1] = nums[j];
//                    }
//                    nums[i] = num;
//                    break;
//                }
//            }
//        }
//    }
//
//    double findMedian()
//    {
//        int half = nums.size() / 2;
//        if ((nums.size() & 1) == 0)
//        {
//            return (nums[half - 1] * 1.0 + nums[half] * 1.0) / 2;
//        } else
//        {
//            return nums[half];
//        }
//    }
//};

// 双堆思路：左手大顶堆，右手小顶堆
//
class MedianFinder
{

private:

    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;


public:
    /** initialize your data structure here. */
    MedianFinder()
    {

    }

    // 当两个堆的 size 相同时
    // 左手添加 num， 右手添加左手的top (最大值)，左手 pop
    // 当两个堆的 size 不同时
    // 右手添加 num， 左手添加右手的top (最小值)，右手 pop
    // 保证 左手的最大值 小于 右手的最小值，就将数据流一分为 2 了
    // 这样就非常方便 动态求取中位数


    void addNum(int num)
    {
        // 先入小顶堆
        if (maxHeap.size() == minHeap.size())
        {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else
        {
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }

    double findMedian()
    {
        if (minHeap.size() != maxHeap.size()) return minHeap.top();
        else
        {
            return (minHeap.top() * 1.0 + maxHeap.top() * 1.0) / 2;
        }
    }


};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
//leetcode submit region end(Prohibit modification and deletion)
