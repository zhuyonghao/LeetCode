/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
// 向左遍历找到第一个最大深度的值
class Solution
{
public:
    // 用来记录最大深度
    int maxDepth = INT_MIN;
    // 存放结果
    int result = 0;

    void traversal(TreeNode *root, int depth)
    {
        // 终止条件：遇到叶子节点
        if (root->left == nullptr && root->right == nullptr)
        {
            // 如果深度更大更新
            if (depth > maxDepth)
            {
                result = root->val;
                maxDepth = depth;
            }
            return;
        }
        // 左
        if (root->left)
        {
            depth++;
            traversal(root->left, depth); // traversal(root->left, depth + 1)
            // 回溯到根节点
            depth--;
        }
        // 右
        if (root->right)
        {
            depth++;
            traversal(root->right, depth); // traversal(root->right, depth + 1)
            // 回溯到根节点
            depth--;
        }
        return;
    }

    int findBottomLeftValue(TreeNode *root)
    {
        traversal(root, 0);
        return result;
    }
};
// @lc code=end
