//给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其
//余元素是 emails 表示该账户的邮箱地址。 
//
// 现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为
//人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。 
//
// 合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按字符 ASCII 顺序排列的邮箱地址。账户本身可以以任意顺序返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：
//accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnn
//ybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Ma
//ry", "mary@mail.com"]]
//输出：
//[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  
//["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
//解释：
//第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
//第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
//可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
//['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的
//。
// 
//
// 
//
// 提示： 
//
// 
// accounts的长度将在[1，1000]的范围内。 
// accounts[i]的长度将在[1，10]的范围内。 
// accounts[i][j]的长度将在[1，30]的范围内。 
// 
// Related Topics 深度优先搜索 并查集 
// 👍 203 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    class Solution
    {
    public:
        vector <vector<string>> accountsMerge(vector <vector<string>> &accounts)
        {
            int size = accounts.size();
            // m保存各邮箱对应的旧账号序号
            unordered_map<string, int> m;
            vector<int> v(size);
            function<void(int, int)> set = [&v, &set](int child, int target)
            {
                if (v[child] == target)
                    return;
                if (v[child] != child)
                {
                    int temp = v[child];
                    v[child] = target;
                    set(temp, target);
                } else
                    v[child] = target;
            };
            function<int(int)> root = [&v, &root](int child)
            {
                if (v[child] != child)
                    v[child] = root(v[child]);
                return v[child];
            };
            for (int i = 0; i < size; ++i)
            {
                v[i] = i;
                for (int j = 1; j < accounts[i].size(); ++j)
                {
                    auto &s = accounts[i][j];
                    if (m.find(s) != m.end())
                        v[i] = min(root(m[s]), v[i]);
                    else
                        m[s] = i;
                }
                for (int j = 1; j < accounts[i].size(); ++j)
                {
                    if (m[accounts[i][j]] != i)
                        set(m[accounts[i][j]], v[i]);
                }
            }
            // f为从原始账号到合并后账号的映射
            vector<int> f(size);
            vector <vector<string>> answer;
            // 确定一共有多少个合并后账号及各账号名称
            for (int i = 0; i < size; ++i)
            {
                if (v[i] == i)
                {
                    f[i] = answer.size();
                    answer.push_back({});
                    answer[f[i]].push_back(accounts[i][0]);
                } else
                    f[i] = f[v[i]];
            }
            // 将每个邮箱加入对应账号
            for (auto &p:m)
                answer[f[p.second]].push_back(p.first);
            // 确保各账号组是有序的
            for (auto &a:answer)
                sort(a.begin() + 1, a.end());
            return answer;
        }
    };


};
//leetcode submit region end(Prohibit modification and deletion)
