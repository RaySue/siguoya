//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。 
//
// 
//
// 示例 1： 
//
// 输入：head = [1,3,2]
//输出：[2,3,1] 
//
// 
//
// 限制： 
//
// 0 <= 链表长度 <= 10000 
// Related Topics 链表 
// 👍 73 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    // 方法一 利用 reverse 函数
    vector<int> reversePrint1(ListNode* head)
    {
        vector<int> ans;
        ListNode *ptr = head;
        while(ptr != nullptr)
        {
            ans.push_back(ptr->val);
            ptr = ptr->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // 方法二 利用 stack

    // 方法三 递归
    void dfs(ListNode *head, vector<int> &record)
    {
        if (!head) return;
        dfs(head->next, record);
        record.push_back(head->val);
    }

    vector<int> reversePrint(ListNode* head)
    {
        vector<int> ret;
        dfs(head, ret);
        return ret;
    }

};
//leetcode submit region end(Prohibit modification and deletion)
