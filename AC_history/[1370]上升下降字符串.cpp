// 给你一个字符串 s ，请你根据下面的算法重新构造字符串：
// 
// 从 s 中选出 最小 的字符，将它 接在 结果字符串的后面。
// 从 s 剩余字符中选出 最小 的字符，且该字符比上一个添加的字符大，将它 接在 结果字符串后面。
// 重复步骤 2 ，直到你没法从 s 中选择字符。 
// 从 s 中选出 最大 的字符，将它 接在 结果字符串的后面。 
// 从 s 剩余字符中选出 最大 的字符，且该字符比上一个添加的字符小，将它 接在 结果字符串后面。 
// 重复步骤 5 ，直到你没法从 s 中选择字符。 
// 重复步骤 1 到 6 ，直到 s 中所有字符都已经被选过。 
// 
//
// 在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。 
//
// 请你返回将 s 中字符重新排序后的 结果字符串 。 
//
// 
//
// 示例 1： 
//
// 输入：s = "aaaabbbbcccc"
//输出："abccbaabccba"
//解释：第一轮的步骤 1，2，3 后，结果字符串为 result = "abc"
//第一轮的步骤 4，5，6 后，结果字符串为 result = "abccba"
//第一轮结束，现在 s = "aabbcc" ，我们再次回到步骤 1
//第二轮的步骤 1，2，3 后，结果字符串为 result = "abccbaabc"
//第二轮的步骤 4，5，6 后，结果字符串为 result = "abccbaabccba"
// 
//
// 示例 2： 
//
// 输入：s = "rat"
//输出："art"
//解释：单词 "rat" 在上述算法重排序以后变成 "art"
// 
//
// 示例 3： 
//
// 输入：s = "leetcode"
//输出："cdelotee"
// 
//
// 示例 4： 
//
// 输入：s = "ggggggg"
//输出："ggggggg"
// 
//
// 示例 5： 
//
// 输入：s = "spo"
//输出："ops"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 500 
// s 只包含小写英文字母。 
// 
// Related Topics 排序 字符串 
// 👍 33 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:


    // 思路：利用计数排序的思想
    // 乍一看这道题比较复杂，仔细分析其实就是按照字符顺序，正序遍历，后续遍历字符串相加的问题而已
    // 1. 先构建计数桶 bucket O(N) O(1)
    // 2. 正序遍历计数桶，记录产生的字符串，对桶内个数减一 O(1) O(1)
    // 3. 逆序遍历计数桶，记录产生的字符串，对桶内个数减一 O(1) O(1)
    // Complexity：
    // Time: O(N)
    // Space: O(1)  （返回结果不计入）
    string sortString(string s)
    {
        string ans = "";
        vector<int> bucket(26, 0);
        for (int i = 0; i < s.size(); ++i)
        {
            bucket[s[i] - 'a']++;
        }
        for(;;)
        {
            int check = 0;  // 用于检查所有桶内为0的时候就跳出循环
            string tmp = "";
            for (int i = 0; i < bucket.size(); ++i)
            {
                if (bucket[i] == 0) continue;
                tmp += 'a' + i;
                bucket[i] --;
                check += bucket[i];
            }
            if (check == 0) break;
            check = 0;
            for (int i = bucket.size() - 1; i >= 0; --i)
            {
                if (bucket[i] == 0) continue;
                tmp += 'a' + i;
                bucket[i] --;
                check += bucket[i];
            }
            ans += tmp;
            if (check == 0) break;
        }
        return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
