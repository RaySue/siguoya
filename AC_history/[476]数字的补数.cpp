//
// 给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。
//
// 
// 00000...101
// 00000...010
//
// 示例 1: 
//
// 输入: 5
//输出: 2
//解释: 5 的二进制表示为 101（没有前导零位），其补数为 010。所以你需要输出 2 。
// 
//
// 示例 2: 
//
// 输入: 1
//输出: 0
//解释: 1 的二进制表示为 1（没有前导零位），其补数为 0。所以你需要输出 0 。
// 
//
// 
//
// 注意: 
//
// 
// 给定的整数保证在 32 位带符号整数的范围内。 
// 你可以假定二进制数不包含前导零位。 
// 本题与 1009 https://leetcode-cn.com/problems/complement-of-base-10-integer/ 相同 
// 
// Related Topics 位运算 
// 👍 184 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    // 思路：
    // 1. 先找到最高位的 1
    // 2. 然后最高位的 1 之前的所有数都置 1 (1 << last - 1 -> ~last)
    // 3. 结果与原数取并，那么得到的就是最高位的1之前的所有数都是 1
    // 4. 然后对第3步的结果取反，就得到了最终的结果
    int findComplement(int num)
    {
        if (num == 0) return 1;
        if (num == INT_MIN) return INT_MIN + 1;
        if (num == INT_MAX && num == INT_MAX - 1) return 0;
        int last = 0;
        int num_bak = num;
        for (int i = 0; i < 32; ++i)
        {
            if (num & 1)
            {
                last = i;
            }
            num >>= 1;
            if (num == 0) break;
        }
        num = num_bak;
        last = (1 << last) - 1; //  000000...0111
        last = ~last; // 111111...1000
        num = num | last; // 11111...1101
        // ~num // 00000...0010
        return ~num;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
