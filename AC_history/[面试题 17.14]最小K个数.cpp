//设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。 
//
// 示例： 
//
// 输入： arr = [1,3,5,7,2,4,6,8], k = 4
//输出： [1,2,3,4]
// 
//
// 提示： 
//
// 
// 0 <= len(arr) <= 100000 
// 0 <= k <= min(100000, len(arr)) 
// 
// Related Topics 堆 排序 分治算法 
// 👍 34 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
private:



public:

    // 方法一： 排序
    vector<int> smallestK1(vector<int> &arr, int k)
    {
        vector<int> ans;
        if (arr.empty()) return ans;
        sort(arr.begin(), arr.end());
        if (k > arr.size()) return arr;
        ans.insert(ans.begin(), arr.begin(), arr.begin() + k);
        return ans;
    }

    // 方法二： 大顶堆 保证里面最多只存 k 个数字
    // 如果大顶堆的size > k， 那么就将最大的删除掉
    vector<int> smallestK(vector<int> &arr, int k)
    {
        vector<int> ans(k);
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < arr.size(); ++i)
        {
            q.push(arr[i]);
            if (q.size() > k) q.pop();
        }
        for (int i = 0; i < k; ++i)
        {
            ans[k - i - 1] = q.top();
            q.pop();
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
