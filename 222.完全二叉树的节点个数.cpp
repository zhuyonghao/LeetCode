/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
// class Solution
// {
// public:
//     // 返回类型和参数
//     int countNodes(TreeNode *root)
//     {
//         // 终止条件
//         if (root == nullptr)
//             return 0;
//         // 后序遍历
//         int left = countNodes(root->left);
//         int right = countNodes(root->right);
//         // 左边节点的数量+右边节点的数量加+身节点的数量
//         return left + right + 1;
//     }
// };

// 利用完全二叉树的特性
class Solution
{
public:
    // 返回类型和参数
    int countNodes(TreeNode *root)
    {
        // 终止条件
        if (root == nullptr)
            return 0;
        // 左子树为满二叉树
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftDepth = 0;
        int rightDepth = 0;
        // 左子树最左边深度
        while (left)
        {
            left = left->left;
            leftDepth++;
        }
        // 左子树最右边深度
        while (right)
        {
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth)
            return (2 << leftDepth) - 1;

        // 后序遍历返回值
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
// @lc code=end
