/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    void traversal(TreeNode *cur, vector<int> &vec)
    {
        // 终止条件
        if (cur == nullptr)
            return;
        // 左中右
        traversal(cur->left, vec);
        vec.push_back(cur->val);
        traversal(cur->right, vec);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        // 用来存放结果的数组
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
// @lc code=end
