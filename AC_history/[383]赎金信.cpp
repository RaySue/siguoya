//给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面
//的字符构成。如果可以构成，返回 true ；否则返回 false。 
//
// (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。) 
//
// 
//
// 注意： 
//
// 你可以假设两个字符串均只含有小写字母。 
//
// canConstruct("a", "b") -> false
//canConstruct("aa", "ab") -> false
//canConstruct("aa", "aab") -> true
// 
// Related Topics 字符串 
// 👍 113 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 方法一： 利用 hash map
    // space O(m)
    // time O(n)
    bool canConstruct1(string ransomNote, string magazine)
    {
        if (ransomNote.empty() && magazine.empty()) return true;
        if (magazine.empty() || ransomNote.size() > magazine.size()) return false;
        unordered_map<char, int> magazineBase;
        for (char a:magazine) magazineBase[a]++;
        for (int i = 0; i < ransomNote.size(); ++i)
        {
            if (magazineBase.count(ransomNote[i]))
            {
                if (magazineBase[ransomNote[i]] < 1) return false;
                magazineBase[ransomNote[i]]--;
            } else
            {
                return false;
            }
        }
        return true;
    }

    // 方法二： 利用 count
    // O(n * m)
    //
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.empty() && magazine.empty()) return true;
        if (magazine.empty() || ransomNote.size() > magazine.size()) return false;
        for (char t : ransomNote)
        {
            int a = count(ransomNote.begin(), ransomNote.end(), t);
            int b = count(magazine.begin(), magazine.end(), t);
//            cout << t << " " << a << " " << b << endl;
            if (a > b) return false;
        }
        return true;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
