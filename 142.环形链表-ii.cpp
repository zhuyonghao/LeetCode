/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 定义快慢指针
        ListNode *fast = head;
        ListNode *slow = head;

        // fast, fast->next不为空
        while (fast != nullptr && fast->next != nullptr)
        {
            // fast走两步，slow走一步为了能够相遇
            fast = fast->next->next;
            slow = slow->next;

            // 如果相遇此时定义两个指针
            // 从起始点和相遇点开始走一定会相遇
            // x = (n - 1)(y + z) + z
            if (fast == slow)
            {
                ListNode *index1 = fast;
                ListNode *index2 = head;
                // 得到入口点
                while (index1 != index2)
                {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                // 返回入口点
                return index1;
            }
        }
        // 未找到
        return nullptr;
    }
};
// @lc code=end
