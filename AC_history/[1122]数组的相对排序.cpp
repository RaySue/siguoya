//
// 给你两个数组，arr1 和 arr2，
//
// 
// arr2 中的元素各不相同 
// arr2 中的每个元素都出现在 arr1 中 
// 
//
// 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末
//尾。 
//
// 
//
// 示例： 
//
// 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
//输出：[2,2,2,1,4,3,3,9,6,7,19]
// 
//
// 
//
// 提示： 
//
// 
// arr1.length, arr2.length <= 1000 
// 0 <= arr1[i], arr2[i] <= 1000 
// arr2 中的元素 arr2[i] 各不相同 
// arr2 中的每个元素 arr2[i] 都出现在 arr1 中 
// 
// Related Topics 排序 数组 
// 👍 105 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 思路：
    // 1. 先对arr1进行排序，Time:O(nlogn) Space:O(1)
    // 2. 利用桶排序的思想，先把arr2中出现的每个元素作为一个桶 unordered_map Time:O(m) Space:O(m)
    // 3. 把arr1中所有的元素放到相应的桶中，如果没有找到对应的桶，那么就放在 -1 桶中 Time:O(n)  Space:O(n)
    // 4. 按照 arr2 的顺序遍历 桶 中的元素，依次extend到ans中，最后把-1桶中的元素放入ans中 Time:O(m), Time:O(n)
    // Complexity:
    // Time: O(nlogn)
    // Space: O(n)
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2)
    {
        vector<int> ans;
        unordered_map<int, vector<int>> bucket;
        sort(arr1.begin(), arr1.end());
        for (int a:arr2) bucket[a] = {};
        bucket[-1] = {};
        for (int i = 0; i < arr1.size(); ++i)
        {
            if (bucket.count(arr1[i]))
            {
                bucket[arr1[i]].push_back(arr1[i]);
            } else {
                bucket[-1].push_back(arr1[i]);
            }
        }
        for (int i = 0; i < arr2.size(); ++i)
        {
            ans.insert(ans.end(), bucket[arr2[i]].begin(), bucket[arr2[i]].end());
        }
        ans.insert(ans.end(), bucket[-1].begin(), bucket[-1].end());
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
