//给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。 
//
// 字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：text = "nlaebolko"
//输出：1
// 
//
// 示例 2： 
//
// 
//
// 输入：text = "loonbalxballpoon"
//输出：2
// 
//
// 示例 3： 
//
// 输入：text = "leetcode"
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= text.length <= 10^4 
// text 全部由小写英文字母组成 
// 
// Related Topics 哈希表 字符串 
// 👍 44 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 思路：
    // 1. 单词 balloon 的无重复字母为 5 个，我们利用长度为5的数组来存储每个字符出现的次数 O(1) O(1)
    // 2. 遍历 text 对字符对应位置进行计数 O(N) O(1)
    // 3. 由于l和o出现需要两次，则对其除以2
    // 4. 找到桶中的短板，就是可以拼成的个数
    int maxNumberOfBalloons(string text)
    {
        int count[5] = {0,0,0,0,0};
        for(int i = 0; i < text.size(); ++i)
        {
            if (text[i] == 'b') count[0]++;
            else if (text[i] == 'a') count[1]++;
            else if (text[i] == 'l') count[2]++;
            else if (text[i] == 'o') count[3]++;
            else if (text[i] == 'n') count[4]++;
        }
        count[2] = count[2] / 2;
        count[3] = count[3] / 2;
        int minVal = text.size();
        for (int i = 0; i < 5; ++i)
        {
            if (count[i] < minVal) minVal = count[i];
        }
        return minVal;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
