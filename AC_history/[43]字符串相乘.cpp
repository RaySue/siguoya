//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。 
//
// 示例 1: 
//
// 输入: num1 = "2", num2 = "3"
//输出: "6" 
//
// 示例 2: 
//
// 输入: num1 = "123", num2 = "456"
//输出: "56088" 
//
// 说明： 
//
// 
// num1 和 num2 的长度小于110。 
// num1 和 num2 只包含数字 0-9。 
// num1 和 num2 均不以零开头，除非是数字 0 本身。 
// 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。 
// 
// Related Topics 数学 字符串 
// 👍 523 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 思路：正常的乘法逻辑，计算num1与num2的个位相乘，再计算num1与num2的十位相乘，...，所有的结果相加
    // 1. 注意边界情况，当一个数为0的时候，直接返回 0
    // 2. 计算num1与num2的所有元素相乘的结果并相加
    // 2.1 多位数与一位数的乘法 string multiply(string &nums, char n);
    // 2.2 字符串的加法 string add(string &nums1, string &nums2);
    // Complexity:
    // Time: O(N * M)
    // Space: O(N)

    // 多位数与一位数的乘法
    // 注意：
    // 1. 倒序遍历 nums
    // 2. 倒序添加到 res 中 res = to_string(tmp % 10) + res;
    // 3. 遍历结束的时候, 如果 carry > 0, 别忘了把 carry 进位
    // Complexity:
    // Time: O(N)
    // Space: O(1)  (返回结果空间不计入)

    // 字符串相加
    // 注意：
    // 1. 倒序遍历 nums
    // 2. 倒序添加到 res 中 res = to_string(tmp % 10) + res;
    // 3. 相等的部分遍历相加结束后，需要带 carry 加到较长字符串的部分，得到结果
    // 4. 遍历结束的时候, 如果 carry > 0, 别忘了把 carry 进位

    // 字符串相乘
    string multiply(string &nums, char n) {
        string res = "";
        int p = nums.size() - 1, carry = 0, target = n - '0';
        while (p >= 0 || carry > 0) {
            int n1 = p >= 0? nums[p--] - '0': 0;
            int tmp = n1 * target + carry;
            carry = tmp / 10;
            res = to_string(tmp % 10) + res;
        }
        return res;
    }
    string add(string &nums1, string &nums2) {
        string res = "";
        if (nums1.empty()) return nums2;
        if (nums2.empty()) return nums1;
        int p1 = nums1.size() - 1, p2 = nums2.size() - 1, carry = 0;
        while (p1 >= 0 || p2 >= 0 || carry > 0) {
            int n1 = p1 >= 0 ? nums1[p1--] - '0': 0;
            int n2 = p2 >= 0 ? nums2[p2--] - '0': 0;
            int tmp = n1 + n2 + carry;
            carry = tmp / 10;
            res = to_string(tmp % 10) + res;
        }
        return res;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string ans = "";
        int carry = 0;
        for (int i = num2.size() - 1; i >= 0; --i) {
            string res = multiply(num1, num2[i]);
            for (int j = 0; j < carry; ++j) res.push_back('0');
            carry++;
            ans = add(ans, res);
        }
        return ans;
    }

    // -----------------------------------------------------------------------

    // 方法二， 利用数组记录 num1 和 num2 中每两位的乘积结果，然后再对所有的结果进行累加



};
//leetcode submit region end(Prohibit modification and deletion)
