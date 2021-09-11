//设计并实现一个 TwoSum 的类，使该类需要支持 add 和 find 的操作。 
//
// add 操作 - 对内部数据结构增加一个数。 
//find 操作 - 寻找内部数据结构中是否存在一对整数，使得两数之和与给定的数相等。 
//
// 示例 1: 
//
// add(1); add(3); add(5);
//find(4) -> true
//find(7) -> false
// 
//
// 示例 2: 
//
// add(3); add(1); add(2);
//find(3) -> true
//find(6) -> false 
// Related Topics 设计 哈希表 
// 👍 25 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class TwoSum
{
public:

    // 方法一：利用排序，加个flag，每次添加一个数之后flag = false，每次find之后flag=true，保证find之后再find不用重复sort，空间复杂度O(1) 时间复杂度O（N*logN）
    // 方法二：利用哈希表，空间复杂度 O(N),查找的时间复杂度O(N)

    /** Initialize your data structure here. */
    TwoSum()
    {

    }

    /** Add the number to an internal data structure.. */
    void add(int number)
    {
        data.push_back(number);
        record[number] = data.size() - 1;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value)
    {
        if (data.size() < 2) return false;
        for (int i = 0; i < data.size(); ++i)
        {
            if (record.count(value - data[i]))
            {
                if (record[value - data[i]] != i) return true;
            }
        }
        return false;
    }

private:
    vector<int> data;
    unordered_map<int, int> record;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
//leetcode submit region end(Prohibit modification and deletion)
