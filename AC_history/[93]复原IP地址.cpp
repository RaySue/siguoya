//给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。 
//
// 有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312"
// 和 "192.168@1.1" 是 无效的 IP 地址。 
//
// 
//
// 示例 1： 
//
// 输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 输入：s = "1111"
//输出：["1.1.1.1"]
// 
//
// 示例 4： 
//
// 输入：s = "010010"
//输出：["0.10.0.10","0.100.1.0"]
// 
//
// 示例 5： 
//
// 输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3000 
// s 仅由数字组成 
// 
// Related Topics 字符串 回溯算法 
// 👍 449 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:

    // 参考 java 代码，四层for循环，解决
//    public List <String> restoreIpAddresses(String s)
//    {
//        List <String> ret = new ArrayList<>();
//
//        StringBuilder ip = new StringBuilder();
//
//        for (int a = 1; a < 4; ++a)
//            for (int b = 1; b < 4; ++b)
//                for (int c = 1; c < 4; ++c)
//                    for (int d = 1; d < 4; ++d)
//                    {
//                        if (a + b + c + d == s.length())
//                        {
//                            int n1 = Integer.parseInt(s.substring(0, a));
//                            int n2 = Integer.parseInt(s.substring(a, a + b));
//                            int n3 = Integer.parseInt(s.substring(a + b, a + b + c));
//                            int n4 = Integer.parseInt(s.substring(a + b + c));
//                            if (n1 <= 255 && n2 <= 255 && n3 <= 255 && n4 <= 255)
//                            {
//                                ip.append(n1).append('.').append(n2).append('.').append(n3).append('.').append(n4);
//                                if (ip.length() == s.length() + 3) ret.add(ip.toString());  // 这里如果出现0或010这种，必定长度就不会相等了
//                                ip.
//                                delete (0, ip.length());
//                            }
//                        }
//                    }
//        return ret;
//    }

    // 参考代码 backtrack
    vector <string> res;

    vector <string> restoreIpAddresses(string s)
    {
        int n = s.size();
        string cur = s;
        helper(n, 0, -1, cur, s);
        return res;
    }

    void helper(int n, int pointnum, int lastpoint, string &cur, string &s)
    {
        //pointnum记录目前加了几个点了，lastpoint记录上一个点加的位置
        if (pointnum == 3)
        {
            //如果已经加了三个点了，并且最后一个点的右边表示的数小于255，则是正确IP地址
            if (valid(lastpoint + 1, n - 1, s))
            {
                res.push_back(cur);
            }
            return;
        }
        //从上一个.号的下一个位置开始查找
        for (int i = lastpoint + 1; i < n - 1; i++)
        {
            //如果字符串s从上一个.号到i位置表示的数小于等于255，则符合条件
            if (valid(lastpoint + 1, i, s))
            {
                //正常回溯法，注意这里要+pointnum，因为已经加入的.号也会占位
                cur.insert(cur.begin() + i + pointnum + 1, '.');
                helper(n, pointnum + 1, i, cur, s);
                cur.erase(pointnum + i + 1, 1);
            }
        }
        return;
    }

    bool valid(int left, int right, string &s)
    {
        int sum = 0;
        for (int i = left; i <= right; i++)
        {
            //处理0开头问题
            if (left != right and s[left] == '0') return false;
            //计算字符串s中left到right位表示的数的大小
            sum = sum * 10 + (s[i] - '0');
            if (sum > 255) return false;
        }
        return true;
    }


//    vector <string> restoreIpAddresses(string s)
//    {
//
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
