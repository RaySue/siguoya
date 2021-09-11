// 给定一个字符串牌照 licensePlate 和一个字符串数组 words ，请你找出并返回 words 中的 最短补全词 。
//
// 如果单词列表（words）中的一个单词包含牌照（licensePlate）中所有的字母，那么我们称之为 补全词 。在所有完整词中，最短的单词我们称之为 最短补全词 。
//
// 单词在匹配牌照中的字母时要： 
//
// 
// 忽略牌照中的数字和空格。 
// 不区分大小写，比如牌照中的 "P" 依然可以匹配单词中的 "p" 字母。 
// 如果某个字母在牌照中出现不止一次，那么该字母在补全词中的出现次数应当一致或者更多。 
// 
//
// 例如：licensePlate = "aBc 12c"，那么它由字母 'a'、'b' （忽略大写）和两个 'c' 。可能的 补全词 是 "abccdef"
//、"caaacab" 以及 "cbca" 。 
//
// 题目数据保证一定存在一个最短补全词。**当有多个单词都符合最短补全词的匹配条件时取单词列表中最靠前的一个**。
//
// 
//
// 示例 1： 
//
// 输入：licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
//输出："steps"
//说明：最短补全词应该包括 "s"、"p"、"s" 以及 "t"。在匹配过程中我们忽略牌照中的大小写。
//"step" 包含 "t"、"p"，但只包含一个 "s"，所以它不符合条件。
//"steps" 包含 "t"、"p" 和两个 "s"。
//"stripe" 缺一个 "s"。
//"stepple" 缺一个 "s"。
//因此，"steps" 是唯一一个包含所有字母的单词，也是本样例的答案。 
//
// 示例 2： 
//
// 输入：licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
//输出："pest"
//说明：存在 3 个包含字母 "s" 且有着最短长度的补全词，"pest"、"stew"、和 "show" 三者长度相同，但我们返回最先出现的补全词 "pes
//t" 。
// 
//
// 示例 3： 
//
// 输入：licensePlate = "Ah71752", words = ["suggest","letter","of","husband","easy
//","education","drug","prevent","writer","old"]
//输出："husband"
// 
//
// 示例 4： 
//
// 输入：licensePlate = "OgEu755", words = ["enough","these","play","wide","wonder"
//,"box","arrive","money","tax","thus"]
//输出："enough"
// 
//
// 示例 5： 
//
// 输入：licensePlate = "iMSlpe4", words = ["claim","consumer","student","camera","
//public","never","wonder","simple","thought","use"]
//输出："simple"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= licensePlate.length <= 7 
// licensePlate 由数字、大小写字母或空格 ' ' 组成 
// 1 <= words.length <= 1000 
// 1 <= words[i].length <= 15 
// words[i] 由小写英文字母组成 
// 
// Related Topics 哈希表 
// 👍 36 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 一刷 2021.01.12
    // 忽略牌照中的数字和空格。
    // 当有多个单词都符合最短补全词的匹配条件时取单词列表中最靠前的一个
    // Complexity:
    // Time: O(N) 遍历一遍字符串
    // Space: O(1)
    //
    // 思路：
    // 关于 stable sort：
    // 我们在做排序的时候，会按照某个条件来排序，比如这个题目就是按照字符串的 size 进行排序的，
    // 那么两个字符串长度相同的时候，谁在前，谁在后，如果没有排序条件限制 sort 函数是根据快速排序，结果摆放的
    // 如果我们需要对 sort 之后相同 size 的字符串保持原有的位置，就需要使用 stable sort
    //
    // 1. 依然是计数排序的思想，当我们已知都是数字，或大小写字母的时候，我们需要利用 固定 size 的vector来代替 hash map
    // 2. 记录有几个非空桶 noZeros
    // 3. 对 words 关于字符串的 size 进行 stable_sort 排序
    // 4. 遍历 words 中的每个字符串，同样放入桶中，如果非空桶的元素个数 >= 原始桶 直接返回，满足 最短补全词
    string shortestCompletingWord(string licensePlate, vector <string> &words)
    {
        vector<int> bucket(26, 0);
        for (int i = 0; i < licensePlate.size(); ++i)
        {
            if (licensePlate[i] == ' ' || (licensePlate[i] >= '0' && licensePlate[i] <= '9')) continue;
            if (licensePlate[i] >= 'A' && licensePlate[i] <= 'Z') licensePlate[i] += 32;
            bucket[licensePlate[i] - 'a']++;
        }

        int nonZeros = 0;
        for (int i = 0; i < 26; ++i) if (bucket[i] != 0) nonZeros++;

        auto lambda = [&](string s1, string s2) -> bool { return s1.size() < s2.size(); };
        stable_sort(words.begin(), words.end(), lambda);
//        sort(words.begin(), words.end(), lambda);

        for (int i = 0; i < words.size(); ++i)
        {
            vector<int> tmpBuc(26, 0);
            for (int j = 0; j < words[i].size(); ++j)
            {
                tmpBuc[words[i][j] - 'a']++;
            }
            int count = 0;
            for (int p = 0; p < 26; ++p)
            {
                if (bucket[p] != 0 && bucket[p] <= tmpBuc[p]) count++;
            }
            if (count == nonZeros) return words[i];
        }
        return "";
    }
};
//leetcode submit region end(Prohibit modification and deletion)
