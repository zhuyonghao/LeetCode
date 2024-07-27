/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
public:
    MyQueue()
    {
    }

    void push(int x)
    {
        stackIn.push(x);
    }

    int pop()
    {
        // 当出栈为空时，将进栈元素移到出栈，否则顺序错误
        if (stackOut.empty())
        {
            // 将进栈元素移空
            while (!stackIn.empty())
            {
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int result = stackOut.top();
        stackOut.pop();
        return result;
    }

    int peek()
    {
        int result = pop();
        stackOut.push(result);
        return result;
    }

    // 两者都为空时，队列才为空
    bool empty()
    {
        return stackOut.empty() && stackIn.empty();
    }

private:
    stack<int> stackIn;
    stack<int> stackOut;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
