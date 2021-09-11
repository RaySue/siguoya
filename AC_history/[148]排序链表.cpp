//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 进阶： 
//
// 
// 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
//
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 5 * 104] 内 
// -105 <= Node.val <= 105 
// 
// Related Topics 排序 链表 
// 👍 930 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:

//    https://leetcode-cn.com/problems/sort-list/solution/shou-hua-tu-jie-gui-bing-pai-xu-148-lian-biao-pai-/
    // 一刷 2020.12.26 归并排序
    // 思路:
    // 1. 对链表一分为二, 双指针，而且需要 cut
    // 2. 对左半部分排序 l = sortList(head)
    // 3. 对右半部分排序 r = sortList(slow)
    // 4. 对已经排序好的 l 和 r merge一下即可

    // 三刷 2021.01.21 归并排序，唯手熟尔
    // 归并排序
    // 0. base case if (!head || !head->next) return head;
    // 1. 先对链表一分为二 (快慢指针)
    // 2. 递归对左部分和右部分调用 sortList
    // 3. 对有序的两部分链表进行 merge
    ListNode *sortList1(ListNode *head)
    {
        if (!head || !head->next) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *mid;
        while (fast != nullptr && fast->next != nullptr)
        {
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        mid->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        return merge(left, right);
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val)
        {
            l1->next = merge(l1->next, l2);
            return l1;
        } else
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }


    ListNode *sortList_debug(ListNode *head)
    {
        if (!head || !head->next) return head;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre;
        while (fast != nullptr && fast->next != nullptr)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
//        如果在 slow 之后断开，那么链表长度为 2 的情况永远断不开了
//        ListNode *next = nullptr;
//        if (slow != nullptr)
//        {
//            next = slow->next;
//            slow->next = nullptr;
//        }
//
//        ListNode *p = head;
//        while(p != nullptr)
//        {
//            cout << p->val << endl;
//            p = p->next;
//        }
//        cout << "---" << endl;
//        p = next;
//        while(p != nullptr)
//        {
//            cout << p->val << endl;
//            p = p->next;
//        }
//        cout << "===========" << endl;

//        return nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);
        return merge(left, right);
    }


    // ==================== 链表的快速排序 =====================
    // 链表的快速排序可用快慢指针实现
    // 快指针每次向后移动一位
    // 慢指针只有快指针指向值小于目标值时，向后移动一位，交换快慢指针的节点值（没有真正交换节点）
    // 迭代结束，小于目标值的值都被换到slow之前，大于目标值的都在slow之后
    // 为方便，每次都选第0节点值作为 pivot

    // 单链表 不能从尾部向头部方向遍历元素
    // 所以只能使用 快慢指针
    ListNode *partition(ListNode *begin, ListNode *end)
    {
        ListNode *slow = begin;
        ListNode *fast = begin->next;
        int pivot = begin->val;
        while (fast != end)
        {
            if (fast->val < pivot)
            {
                slow = slow->next;
                swap(slow->val, fast->val);
            }
            fast = fast->next;
        }
        swap(begin->val, slow->val);
        return slow;
    }

    void quicksort(ListNode *begin, ListNode *end)
    {
        if (begin == end) return;
        ListNode *pi = partition(begin, end);
        quicksort(begin, pi);  // [begin, pi)  左闭右开区间
        quicksort(pi->next, end);  // [pi->next, end)  左闭右开区间
    }



    // 快排链表
    // 快排是基于交换的排序算法，所以这里我只对单链表的值进行交换，并不对节点进行交换
    // 单链表无法使用左右双指针，所以只能使用快慢指针来代替解决问题
    // 首先首位置作为 pivot，slow 指针指向首位置，fast指针指向slow->next;
    // 然后 fast 向后遍历，如果遇到 fast->val < pivot，那么就将 slow=slow->next,然后再交换 slow 和 fast的值
    // 这样 slow 走过的位置都可以保证 slow 之前是小于 pivot 的
    // fast 到 end 结束
    ListNode *partition(ListNode *head, ListNode *tail)
    {
        int pivot = head->val;
        ListNode *slow = head;
        ListNode *fast = slow->next;
        while(fast != tail)
        {
            if (fast->val < pivot)
            {
                slow = slow->next;
                swap(slow->val, fast->val);
            }
            fast = fast->next;
        }
        swap(slow->val, head->val);
        return slow;
    }

    void quickSort(ListNode *head, ListNode *tail)
    {
        if (head == tail) return;
        ListNode *pi = partition(head, tail);
        quickSort(head, pi);
        quickSort(pi->next, tail);
    }

    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next) return head;
        quickSort(head, nullptr);
        return head;
    }

};
























//leetcode submit region end(Prohibit modification and deletion)
