// 给出三个均为 严格递增排列 的整数数组 arr1，arr2 和 arr3。
// 返回一个由 仅 在这三个数组中 同时出现 的整数所构成的有序数组。 
//
//
// 示例： 
//
// 输入: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
//输出: [1,5]
//解释: 只有 1 和 5 同时在这三个数组中出现.
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr1.length, arr2.length, arr3.length <= 1000 
// 1 <= arr1[i], arr2[i], arr3[i] <= 2000 
// 
// Related Topics 哈希表 双指针 
// 👍 19 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 遍历一个数组，然后分别在两个数组进行二分查找，充分利用有序特性
    // Complexity:
    // Time: O(N*logN)
    // Space: O(1)
    vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
    {
        vector<int> ans;
        for (int i = 0; i < arr1.size(); ++i) // O(N) *
        {
            if (search(arr2, arr1[i]) && search(arr3, arr1[i]))  // O(logN)
            {
                ans.push_back(arr1[i]);
            }
        }
        return ans;
    }

    bool search(vector<int> &arr, int target)
    {
        int l = 0, r = arr.size() - 1, mid = 0;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (target < arr[mid])
            {
                r = mid - 1;
            } else if (target > arr[mid])
            {
                l = mid + 1;
            } else
            {
                return true;
            }
        }
        return false;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
