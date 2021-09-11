//给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。 
//
// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。 
//
// 示例1: 
//
// 输入: pattern = "abba", str = "dog cat cat dog"
//输出: true 
//
// 示例 2: 
//
// 输入:pattern = "abba", str = "dog cat cat fish"
//输出: false 
//
// 示例 3: 
//
// 输入: pattern = "aaaa", str = "dog cat cat dog"
//输出: false 
//
// 示例 4: 
//
// 输入: pattern = "abba", str = "dog dog dog dog"
//输出: false 
//
// 说明: 
//你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。 
// Related Topics 哈希表 
// 👍 189 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 利用两个map
    bool wordPattern1(string pattern, string str)
    {
        unordered_map<char, string> match1;
        unordered_map<string, char> match2;
        vector <string> strVec;
        string tmp = "";
        str.push_back(' ');
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] == ' ')
            {
//                cout << tmp << endl;
                strVec.push_back(tmp);
                tmp.clear();
            } else
            {
                tmp += str[i];
            }
        }
        if (strVec.size() != pattern.size()) return false;
        for (int i = 0; i < pattern.size(); ++i)
        {
            if (!match1.count(pattern[i]) && !match2.count(strVec[i]))
            {
                match1[pattern[i]] = strVec[i];
                match2[strVec[i]] = pattern[i];
            } else
            {
                if (match1[pattern[i]] != strVec[i] || match2[strVec[i]] != pattern[i]) return false;
            }
        }
        return true;
    }

    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> rmap;
        stringstream ss(str); string s;

        for(char c : pattern)
        {
            // 利用 stringstream 来 去除中间的括号
            // 如果 map 中的字符对应的字符串不对，立即返回false
            if(!(ss >> s) || (map.count(c) && map[c] != s) || (rmap.count(s) && rmap[s] != c)) return false;
            map[c] = s; rmap[s] = c;
        }
        return (ss >> s) ? false : true;
    }


};
//leetcode submit region end(Prohibit modification and deletion)
