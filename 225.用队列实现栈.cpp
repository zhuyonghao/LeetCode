/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack
{
public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        size_t size = q.size() - 1;
        // 将前size-1个元素移到元素后面
        while (size--)
        {
            q.push(q.front());
            q.pop();
        }
        int result = q.front();
        q.pop();
        return result;
    }

    int top()
    {
        return q.back();
    }

    bool empty()
    {
        return q.empty();
    }

private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
