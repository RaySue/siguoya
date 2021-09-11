// 假设 Andy 和 Doris 想在晚餐时选择一家餐厅，并且他们都有一个表示最喜爱餐厅的列表，每个餐厅的名字用字符串表示。
// 你需要帮助他们用最少的索引和找出他们共同喜爱的餐厅。
// 如果答案不止一个，则输出所有答案并且不考虑顺序。
// 你可以假设总是存在一个答案。
//
// 示例 1: 
//
// 输入:
//["Shogun", "Tapioca Express", "Burger King", "KFC"]
//["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
//输出: ["Shogun"]
//解释: 他们唯一共同喜爱的餐厅是“Shogun”。
// 
//
// 示例 2: 
//
// 输入:
//["Shogun", "Tapioca Express", "Burger King", "KFC"]
//["KFC", "Shogun", "Burger King"]
//输出: ["Shogun"]
//解释: 他们共同喜爱且具有最小索引和的餐厅是“Shogun”，它有最小的索引和1(0+1)。
// 
//
// 提示: 
//
// 
// 两个列表的长度范围都在 [1, 1000]内。 
// 两个列表中的字符串的长度将在[1，30]的范围内。 
// 下标从0开始，到列表的长度减1。 
// 两个列表都没有重复的元素。 
// 
// Related Topics 哈希表 
// 👍 87 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 题目至少读 3 遍再构思，当年李老师的话又在耳边响起
    //
    // 理解错误的点：
    // 1. 开始以为只是找到相同的餐厅呢
    // 2. 后来以为是找到一家索引绝对差最小的餐厅

    // 实际上是要找到餐相同的餐厅的索引和最小的所有餐厅（如果最小值有多个）
    // 思路：
    // 遍历一个列表，再遍历另一个列表，判断元素是否在列表中出现
    // 如果出现，那么下标之和是否小于 minIdx，如果小于，那么对之前的答案清空，然后添加新的元素
    // 如果出现，但是下标之和等于 minIdx，如果等于，那么就在之前答案的基础上在添加新的元素
    // Complexity:
    // Time: O(N * M)
    // Space: O(1)
    //
    // distance(.begin, find()); 获取搜索元素的下标
    vector <string> findRestaurant1(vector <string> &list1, vector <string> &list2)
    {
        vector <string> ans;
        int l1 = list1.size();
        int minIdx = INT_MAX;
        for (int i = 0; i < l1; ++i)
        {
            auto idx = distance(list2.begin(), find(list2.begin(), list2.end(), list1[i]));
            if (idx == list2.size()) continue;
            if (idx + i < minIdx)
            {
                minIdx = idx + i;
                ans.clear();
                ans.push_back(list1[i]);
            } else if (idx + i == minIdx)
            {
                ans.push_back(list1[i]);
            }
        }
        return ans;
    }


    // 方法二 使用 unordered_map
    // 思路：
    // 把 list1 装入 unordered_map<string, int> 存储 内容 和 下标
    // 遍历 list2 判断 list2 中的元素是否在list1中出现，如果出现，那么计算下标和
    // 如果下标和小于当前最小下标和，那么清空 ans ，填入新元素
    // 如果下标和等于当前的最小下标和，那么ans.push_back(元素）
    vector <string> findRestaurant(vector <string> &list1, vector <string> &list2)
    {

    }

};
//leetcode submit region end(Prohibit modification and deletion)
