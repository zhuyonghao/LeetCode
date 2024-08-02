/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder)
    {
        // 后序数组为0，空节点
        if (postorder.size() == 0)
            return nullptr;

        // 后序数组最后一个元素为节点元素
        int rootValue = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootValue);
        if (postorder.size() == 1)
            return root;

        // 寻找中序数组位置作切割点
        int index = 0;
        for (; index < postorder.size(); index++)
        {
            if (inorder[index] == rootValue)
                break;
        }

        // 切中序数组
        // 左闭右开[0,index)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        // [index + 1, end)
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        // postOrder舍弃末尾元素
        postorder.resize(postorder.size() - 1);

        // 切后序数组
        // 根据切过的中序数组大小分割后序数组
        // [0,leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size, end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        // 递归处理左区间后区间
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        // 如果中序和后序大小为0则直接返回nullptr
        if (inorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        return traversal(inorder, postorder);
    }
};
// @lc code=end
