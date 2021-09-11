//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。 
//
// 示例: 
//
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出:
//[
//  ["ate","eat","tea"],  a:1 e:1 t:1
//  ["nat","tan"], a:1 t:1 n:1
//  ["bat"] a:1 b:1 t:1
//] 
//
// 说明： 
//
// 
// 所有输入均为小写字母。 
// 不考虑答案输出的顺序。 
// 
// Related Topics 哈希表 字符串 
// 👍 552 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 思路：
    // 互为字母异位词排序后一定相同
    // 那么就以排序后的字母异位词作为key，那么这道题就非常 easy 了
    /**
    Success:
    Runtime:60 ms, faster than 91.09% of C++ online submissions.
    Memory Usage:19.5 MB, less than 47.07% of C++ online submissions.
    */
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ret;

        unordered_map<string, vector<string>> record;

        for (int i = 0; i < strs.size(); ++i)
        {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            if (!record.count(cur))
            {
                record[cur] = {strs[i]};
            } else {
                record[cur].push_back(strs[i]);
            }
        }

        for (auto [k,v]: record)
        {
            ret.push_back(v);
        }

        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
