/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
//     TreeNode *searchBST(TreeNode *root, int val)
//     {
//         // 找到和没有找到
//         if (root == nullptr || root->val == val)
//             return root;

//         // 用result装结果
//         TreeNode *result = nullptr;

//         // 如果当前值比目标值要小向右搜索
//         if (root->val < val)
//             result = searchBST(root->right, val);
//         // 如果当前值比目标值大向左搜索
//         if (root->val > val)
//             result = searchBST(root->left, val);

//         return result;
//     }
// };

// 使用迭代法
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root != nullptr)
        {
            // 如果当前值比目标值小向右搜索
            if (root->val < val)
                root = root->right;
            // 如果当前值比目标值大向左搜索
            else if (root->val > val)
                root = root->left;
            // 找到了
            else
                return root;
        }
        // 没有找到
        return nullptr;
    }
};

// @lc code=end
