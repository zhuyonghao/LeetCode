/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // 返回类型和参数
    int getHeight(TreeNode *root)
    {
        // 终止条件
        if (root == nullptr)
            return 0;
        // 左
        int leftHeight = getHeight(root->left);
        // 左子树不平衡则返回-1
        if (leftHeight == -1)
            return -1;
        // 右
        int rightHeight = getHeight(root->right);
        // 右子树不平衡
        if (rightHeight == -1)
            return -1;
        // 如果左右高度差大于1则不平衡
        if (abs(rightHeight - leftHeight) > 1)
            return -1;
        // 返回高度
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode *root)
    {
        // 获取高度
        int height = getHeight(root);
        // 如果高度为-1则不平衡
        if (height == -1)
            return false;
        // 否则平衡
        return true;
    }
};
// @lc code=end
