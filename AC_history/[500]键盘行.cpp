//给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。 
//
// 
//
// 
//
// 
//
// 示例： 
//
// 输入: ["Hello", "Alaska", "Dad", "Peace"]
//输出: ["Alaska", "Dad"]
// 
//
// 
//
// 注意： 
//
// 
// 你可以重复使用键盘上同一字符。 
// 你可以假设输入的字符串将只包含字母。 
// Related Topics 哈希表 
// 👍 113 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

//    if(c>=97){
//        小写字母转大写
//        c=(char)(c-32);
//    }

    // 思路：
    // 1. 先记录每行的大小写字母
    // 2. 都添加到alphaMap中
    // 3. 然后对每个字母进行判断，如果同一个字母不在一行，那么就break换下一个
    // time  O(N*M))
    // space O(1)
    string line1 = "QWERTYUIOPqwertyuiop";
    string line2 = "ASDFGHJKLasdfghjkl";
    string line3 = "ZXCVBNMzxcvbnm";

    vector<string> findWords(vector<string>& words)
    {
        vector<string> ans;
        if (words.empty()) return ans;
        unordered_map<char, int> alphaMap;
        for (char a:line1) alphaMap[a] = 1;
        for (char b:line2) alphaMap[b] = 2;
        for (char c:line3) alphaMap[c] = 3;
        int count = 0;
        for (auto word:words)
        {
            for (char a:word)
            {
                if (count == 0) count = alphaMap[a];
                if (alphaMap[a] != count)
                {
                    count = -1;
                    break;
                }
            }
            if (count != -1)
            {
                ans.push_back(word);
            }
            count = 0;
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
