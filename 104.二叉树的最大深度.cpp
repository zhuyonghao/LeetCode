/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    // 参数和返回类型
    int maxDepth(TreeNode *root)
    {
        // 如果传递到根节点返回0
        if (root == nullptr)
            return 0;
        // 后序遍历：左右中
        // 左子树的最大深度
        int left = maxDepth(root->left);
        // 右子树的最大深度
        int right = maxDepth(root->right);
        // 中: 处理
        int height = max(left, right) + 1;
        // 返回
        return height;
    }
};
// @lc code=end
