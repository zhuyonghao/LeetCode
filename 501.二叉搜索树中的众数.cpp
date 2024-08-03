/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    // 用来存放结果数组
    vector<int> result;
    // 最大出现次数
    int maxCount = 0;
    // 单个元素出现次数
    int count = 1;
    // 双指针
    TreeNode *pre = nullptr;

    void traversal(TreeNode *cur)
    {
        // 终止条件
        if (cur == nullptr)
            return;
        // 左
        traversal(cur->left);

        // 中：处理
        if (pre != nullptr && pre->val == cur->val)
            count++;
        else if (pre != nullptr && pre->val != cur->val)
            count = 1;

        // 将元素放入result数组中
        if (count == maxCount)
            result.push_back(cur->val);
        if (count > maxCount)
        {
            // 更新maxCount
            maxCount = count;
            // 清空result数组
            result.clear();
            // 将该值存放
            result.push_back(cur->val);
        }

        // 更新pre指针
        pre = cur;

        // 右
        traversal(cur->right);
    }
    vector<int> findMode(TreeNode *root)
    {
        traversal(root);
        return result;
    }
};
// @lc code=end
