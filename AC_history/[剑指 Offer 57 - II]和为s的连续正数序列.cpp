// 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
//
// 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。 
//
// 
//
// 示例 1： 
//
// 输入：target = 9
//输出：[[2,3,4],[4,5]]
// 
//
// 示例 2： 
//
// 输入：target = 15
//输出：[[1,2,3,4,5],[4,5,6],[7,8]]
// 
//
// 
//
// 限制： 
//
// 
// 1 <= target <= 10^5 
// 
//
// 
// 👍 192 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 利用双端队列 + 滑动窗口
    // Complexity：
    // time: O(N)
    // Space: O(N)
    vector<vector<int>> findContinuousSequence1(int target)
    {
        vector<vector<int> > ans;
        int l = 1, r = 1, windowSum = 0;
        deque<int> window;
        while(r < target)
        {
            window.push_back(r);
            windowSum += r;
            r ++;
            while(windowSum >= target)
            {
                if (windowSum == target)
                {
                    vector<int> tmp;
                    tmp.assign(window.begin(), window.end());
                    ans.push_back(tmp);
                }
                window.pop_front();
                windowSum -= l;
                l ++;
            }
        }
        return ans;
    }


    // 由于是连续的，我们可以考虑不用双端队列
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int> > ans;
        int l = 1, r = 1, window = 0, half = target / 2 + 1;

        while (r <= half)
        {
            window += r;
            r++;
            while(window >= target)
            {
                if (window == target)
                {
                    vector<int> tmp;
                    for (int i = l; i < r; ++i)
                    {
                        tmp.push_back(i);
                    }
                    ans.push_back(tmp);
                }
                window -= l;
                l++;
            }
        }
        return ans;
    }



};
//leetcode submit region end(Prohibit modification and deletion)
