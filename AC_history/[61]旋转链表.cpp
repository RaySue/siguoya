//给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。 
//
// 示例 1: 
//
// 输入: 1->2->3->4->5->NULL, k = 2
//输出: 4->5->1->2->3->NULL
//解释:
//向右旋转 1 步: 5->1->2->3->4->NULL
//向右旋转 2 步: 4->5->1->2->3->NULL
// 
//
// 示例 2: 
//
// 输入: 0->1->2->NULL, k = 4
//输出: 2->0->1->NULL
//解释:
//向右旋转 1 步: 2->0->1->NULL
//向右旋转 2 步: 1->2->0->NULL
//向右旋转 3 步: 0->1->2->NULL
//向右旋转 4 步: 2->0->1->NULL 
// Related Topics 链表 双指针 
// 👍 335 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/yi-wen-jie-jue-4-dao-sou-suo-xuan-zhuan-pai-xu-s-3/

// 二刷 2020.12.27
// 旋转问题
// 解法一： 使用额外的数组vector<int>，参考 189.旋转数组

// 解法二：
// 1. 先得到链表的总长度，与 k 做取模运算得到 k'
// 2. 找到倒数第 k 个位置的前一个元素作为 slow
// 3. 将slow->net 给 dummyHead， 断 slow->next = nullptr
// 4. ptr 指向 dummyHead 然后遍历到末尾，连接head 返回即可

// 解法三： 整体逆序，然后对前 k' 个元素再逆序
//

class Solution1
{
public:

    // 二刷 解法二 2020.12.27

    // 思路：
    // 1. 先找到倒数第 k 个节点
    // 2. 将后面的 k 个节点的首节点保存下来给 dummyHead，然后把后面的切断，即改变了head
    // 3. ptr = dummyHead, 遍历ptr到最后，连接 head
    int getLength(ListNode *head)
    {
        int ans = 0;
        while (head != nullptr)
        {
            ans++;
            head = head->next;
        }
        return ans;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0) return head;
        ListNode *ptr = head;
        int len = getLength(ptr);
        k %= len;
        if (k == 0) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        for (int i = 0; i < k; ++i) fast = fast->next;
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *dummyHead = slow->next;
        slow->next = nullptr;
        ptr = dummyHead;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = head;
        return dummyHead;
    }
};


class Solution
{
public:

    // 一刷 解法三 2020.12.27

    int getLength(ListNode *head)
    {
        int ans = 0;
        while (head != nullptr)
        {
            ans++;
            head = head->next;
        }
        return ans;
    }

    ListNode *reverse(ListNode *head)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            ListNode *buffer = cur->next;
            cur->next = pre;
            pre = cur;
            cur = buffer;
        }
        return pre;
    }

    // 1->2->3->4->5->NULL
    // 5->4->3->2->1
    // 4->5 1->2->3
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0) return head;
        ListNode *ptr = head;
        int len = getLength(ptr);
        k %= len;
        if (k == 0) return head;

        head = reverse(head);
        ptr = head;
        for (int i = 0; i < k - 1; ++i)
        {
            ptr = ptr->next;
        }
        ListNode *after = ptr->next;
        ptr->next= nullptr;
        after = reverse(after);
        head = reverse(head);
        ptr = head;
        while(ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = after;
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
