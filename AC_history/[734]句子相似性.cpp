// 给定两个句子 words1, words2 （每个用字符串数组表示），和一个相似单词对的列表 pairs ，判断是否两个句子是相似的。
//
// 例如，当相似单词对是 pairs = [["great", "fine"], ["acting","drama"], ["skills","talent"]]的时候，
// "great acting skills" 和 "fine drama talent" 是相似的。
//
// 注意相似关系是不具有传递性的。例如，如果 "great" 和 "fine" 是相似的，"fine" 和 "good" 是相似的，但是 "great" 和 "good" 未必是相似的。
//
// 但是，相似关系是具有对称性的。例如，"great" 和 "fine" 是相似的相当于 "fine" 和 "great" 是相似的。 
//
// 而且，一个单词总是与其自身相似。例如，句子 words1 = ["great"], words2 = ["great"], pairs = [] 是相似的
//，尽管没有输入特定的相似单词对。 
//
// 最后，句子只会在具有相同单词个数的前提下才会相似。所以一个句子 words1 = ["great"] 永远不可能和句子 words2 = ["doubleplus","good"] 相似。
//
// 
//
// 注：
// 
// words1 and words2 的长度不会超过 1000。 
// pairs 的长度不会超过 2000。 
// 每个pairs[i] 的长度为 2。 
// 每个 words[i] 和 pairs[i][j] 的长度范围为 [1, 20]。 
// 
//
// 
// Related Topics 哈希表 
// 👍 17 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    bool areSentencesSimilar(vector <string> &sentence1, vector <string> &sentence2, vector <vector<string>> &similarPairs)
    {
        if (sentence1.size() != sentence2.size()) return false;
        if (similarPairs.empty())
        {
            for (int i = 0; i < sentence1.size(); ++i)
            {
                if (sentence1[i] != sentence2[i]) return false;
            }
            return true;
        }
        // 利用unordered_map 嵌套 unordered_set
        unordered_map<string, unordered_set<string>> mp;
        for (vector<string> similarPair:similarPairs)
        {
            mp[similarPair[0]].insert(similarPair[1]);
            mp[similarPair[1]].insert(similarPair[0]);
        }
        for (int i = 0; i < sentence1.size(); ++i)
        {
            if (sentence1[i] != sentence2[i]
            && !mp[sentence1[i]].count(sentence2[i])
            && !mp[sentence2[i]].count(sentence1[i]))
                return false;
        }
        return true;
        // 利用unordered_map 嵌套 vector<string>
//        unordered_map <string, vector<string>> mp;
//        for (vector <string> sp: similarPairs)
//        {
//            if (mp.count(sp[0]))
//            {
//                mp[sp[0]].push_back(sp[1]);
//            } else
//            {
//                mp[sp[0]] = {sp[1]};
//            }
//            if (mp.count(sp[1]))
//            {
//                mp[sp[1]].push_back(sp[0]);
//            } else
//            {
//                mp[sp[1]] = {sp[0]};
//            }
//        }
//        for (int i = 0; i < sentence1.size(); ++i)
//        {
//            if (sentence1[i] != sentence2[i] &&
//                find(mp[sentence1[i]].begin(), mp[sentence1[i]].end(), sentence2[i]) == mp[sentence1[i]].end() &&
//                find(mp[sentence2[i]].begin(), mp[sentence2[i]].end(), sentence1[i]) == mp[sentence2[i]].end())
//                return false;
//        }
//        return true;
    }

    // 值得学习的简练的写法，嵌套Hash Map
    bool areSentencesSimilar2(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        unordered_map<string, unordered_map<string, int>> m;

        for (auto p: pairs) {
            m[p[0]][p[1]] = 1;
            m[p[1]][p[0]] = 1;
        }

        if (words1.size() != words2.size()) return false;

        for (int i = 0; i < words1.size(); i++) {
            if (words1[i] != words2[i] && m[words1[i]][words2[i]] != 1) return false;
        }

        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
