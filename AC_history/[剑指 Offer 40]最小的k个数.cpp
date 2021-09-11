//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。 
//
// 
//
// 示例 1： 
//
// 输入：arr = [3,2,1], k = 2
//输出：[1,2] 或者 [2,1]
// 
//
// 示例 2： 
//
// 输入：arr = [0,1,2,1], k = 1
//输出：[0] 
//
// 
//
// 限制： 
//
// 
// 0 <= k <= arr.length <= 10000 
// 0 <= arr[i] <= 10000 
// 
// Related Topics 堆 分治算法 
// 👍 167 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 方法一: 排序
//    vector<int> getLeastNumbers(vector<int>& arr, int k)
//    {
//        sort(arr.begin(), arr.end());
//        vector<int > ans;
//        ans.assign(arr.begin(), arr.begin() + k);
//        return ans;
//    }


    // 方法二: 优先队列
    // 大顶堆，每次只存 k 个数字就可以
    vector<int> getLeastNumbers2(vector<int> &arr, int k)
    {
        if (k == 0) return {};
//        priority_queue<int, vector<int>, greater<int> > window; // 小顶堆
        priority_queue<int, vector<int>, less<int> > window;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (window.size() < k)
            {
                window.push(arr[i]);
            } else
            {
                if (arr[i] < window.top())
                {
                    window.pop();
                    window.push(arr[i]);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(window.top());
            window.pop();
        }
        return ans;
    }

    // 方法三: 分治算法 快速排序
private:
    vector<int> res;
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        if (arr.empty() || k == 0)
        { return {}; }
        return quickSelection(arr, 0, arr.size() - 1, k - 1); // 注意第 k 个数对应的下标是 k - 1
    }

    vector<int> quickSelection(vector<int> &arr, int left, int right, int index)
    {
        // partition函数将一个区间内所有小于下标为 j 的数放在 j 左边，大于下标为 j 的数放在 j 右边
        int j = partition(arr, left, right);

        if (j == index)
        { // 若 j 刚好等于 k - 1，将 arr[0] 至 arr[j] 输入 res
            for (int i = 0; i < j + 1; ++i)
            { res.push_back(arr[i]); }
            return res;
        }
        // 若 j 小于 k - 1，将区间变成 [j + 1, right]；反之，区间变成 [left, j - 1]
        return j < index ? quickSelection(arr, j + 1, right, index) : quickSelection(arr, left, j - 1, index);
    }

    int partition(vector<int> &arr, int left, int right)
    {
        int value = arr[left];
        int i = left, j = right + 1;

        while (true)
        {
            while (++i <= right && arr[i] < value); // 找到从左往右第一个大于等于 value 的下标
            while (--j >= left && arr[j] > value); // 找到从右往左第一个小于等于 value 的下标
            if (i >= j)
            { break; } // 如果找不到，说明已经排好序了，break
            swap(arr[i], arr[j]); // 如果找到了，交换二者
        }
        swap(arr[left], arr[j]); // arr[j]是小于 value 的，这一步使得所有小于下标为 j 的数都在 j 左边

        return j;
    }

    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
