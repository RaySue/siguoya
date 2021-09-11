//给定一个整数，编写一个算法将这个数转换为十六进制数。对于负整数，我们通常使用 补码运算 方法。 
//
// 注意: 
//
// 
// 十六进制中所有字母(a-f)都必须是小写。 
// 十六进制字符串中不能包含多余的前导零。如果要转化的数为0，那么以单个字符'0'来表示；对于其他情况，
// 十六进制字符串中的第一个字符将不会是0字符。
// 给定的数确保在32位有符号整数范围内。 
// 不能使用任何由库提供的将数字直接转换或格式化为十六进制的方法。 
// 
//
// 示例 1： 
//
// 
//输入:
//26
//
//输出:
//"1a"
// 
//
// 示例 2： 
//
// 
//输入:
//-1
//
//输出:
//"ffffffff"
// 
// Related Topics 位运算 
// 👍 97 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    //    在C/C++中，0x开头的数字是十六进制数字，后面跟的数字都要按照十六进制理解，
    //    0xf就是十六进制数字f，转换为10进制数字就是15
    //
    //    思路：int是32位二进制存储，转换成16进制就该有8位 每次让num向右移位4位，
    //    并和0xf(二进制的00000000 00000000 00000000 00001111)做与运算，即只计算当前四位有效位
    //    即可得到本四位的十六进制表示。 由于负数右移动不能保证最终num==0，因此限制右移动的次数不超过8.


    string toHex(int num)
    {
        if (num == 0) return "0";
        string hex = "0123456789abcdef";
        int resSize = 0;  //右移动的次数
        string res = "";
        while (num && resSize < 8)//32位转换成16进制就是八位
        {
            res = hex[num & 0xf] + res;  // 逆序相加
            num >>= 4;
            resSize++;
        }
        return res;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
