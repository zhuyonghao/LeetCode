/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val) : val(val), next(nullptr) {}
    }; // 链表节点定义

    MyLinkedList()
    {
        size = 0;                    // 个数初始化为0
        dummyHead = new ListNode(0); // 初始化虚拟头节点
    }
    int get(int index)
    {
        // 判断是否有效
        if (index < 0 || index > size - 1)
            return -1;

        ListNode *cur = dummyHead->next;

        while (index)
        {
            cur = cur->next;
            index--;
        }

        return cur->val;
    }

    void addAtHead(int val)
    {
        ListNode *newNode = new ListNode(val);

        newNode->next = dummyHead->next;
        dummyHead->next = newNode;

        size++; // 个数加一
    }

    void addAtTail(int val)
    {
        ListNode *newNode = new ListNode(val);

        // ListNode *cur = dummyHead->next;
        // 写成这种形式需要判断头节点是否为空

        ListNode *cur = dummyHead;

        while (cur->next != nullptr)
        {
            cur = cur->next;
        }

        cur->next = newNode;

        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;

        // else if (index == size)
        //  addAtTail(val);
        // 使用虚拟头节点统一了形式
        // 下面的式子无论是头节点和尾节点

        ListNode *newNode = new ListNode(val);

        ListNode *cur = dummyHead;
        // 找到前一个节点的位置
        while (index)
        {
            cur = cur->next;
            index--;
        }

        newNode->next = cur->next;
        cur->next = newNode;

        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index > size - 1)
            return;

        ListNode *cur = dummyHead;

        while (index)
        {
            cur = cur->next;
            index--;
        }

        cur->next = cur->next->next;

        size--;
    }

private:
    int size;            // 个数
    ListNode *dummyHead; // 虚拟头结点
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
