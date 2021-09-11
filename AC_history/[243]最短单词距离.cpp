//给定一个单词列表和两个单词 word1 和 word2，返回列表中这两个单词之间的最短距离。 
//
// 示例: 
//假设 words = ["practice", "makes", "perfect", "coding", "makes"] 
//
// 输入: word1 = “coding”, word2 = “practice”
//输出: 3
// 
//
// 输入: word1 = "makes", word2 = "coding"
//输出: 1
// 
//
// 注意: 
//你可以假设 word1 不等于 word2, 并且 word1 和 word2 都在列表里。 
// Related Topics 数组 
// 👍 30 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    // naive by hash_map
    // 时间复杂度：O(N) + O(n * m)
    // 空间复杂度：O(N)
    int shortestDistance(vector <string> &words, string word1, string word2)
    {
        if (words.empty()) return -1;
        unordered_map <string, vector<int>> mp;
        mp[word1] = {};
        mp[word2] = {};
        for (int i = 0; i < words.size(); ++i)
        {
            string word = words[i];
            if (mp.count(word))
            {
                mp[word].push_back(i);
            }
        }
        vector<int> idx1 = mp[word1];
        vector<int> idx2 = mp[word2];
        int minRange = INT_MAX;
        for (auto id1: idx1)
        {
            for (auto id2:idx2)
            {
                if (abs(id1 - id2) < minRange)
                {
                    minRange = abs(id1 - id2);
                }
            }
        }
        return minRange;
    }

    /**
     *
     * 这个题是应用双指针的典型题，如果不使用双指针，那么就需要额外的空间，那么空间复杂度就较高了
     *
     * @param words
     * @param word1
     * @param word2
     * @return
     */
    int shortestDistance2(vector <string> &words, string word1, string word2)
    {
        if (words.empty()) return -1;
        int minRange = words.size(), i1 = -1, i2 = -1;
        for(int i = 0; i < words.size();++i)
        {
            if(words[i] == word1)
            {
                i1 = i;
            } else if (words[i] == word2)
            {
                i2 = i;
            }
            if (i1 != -1 && i2 != -1)
            {
                int r = abs(i1 - i2);
                if (r < minRange) minRange = r;
            }
        }
        return minRange;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
