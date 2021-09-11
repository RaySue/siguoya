// 给定字典中的两个词，长度相等。写一个方法，把一个词转换成另一个词， 但是一次只能改变一个字符。每一步得到的新词都必须能在字典中找到。
//
// 编写一个程序，返回一个可能的转换序列。如有多个可能的转换序列，你可以返回任何一个。 
//
// 示例 1: 
//
// 输入:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot","dot","dog","lot","log","cog"]
//
//输出:
//["hit","hot","dot","lot","log","cog"]
// 
//
// 示例 2: 
//
// 输入:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//
//输出: []
//
//解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。 
// Related Topics 深度优先搜索 广度优先搜索 数组 字符串 
// 👍 27 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // BFS
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        int n = wordList.size();
        if (n==0) return {};
        unordered_map<string,int>ans;
        unordered_map<string,string>pre;
        std::queue<string>Q;
        Q.push(beginWord);


    }
};
//leetcode submit region end(Prohibit modification and deletion)
