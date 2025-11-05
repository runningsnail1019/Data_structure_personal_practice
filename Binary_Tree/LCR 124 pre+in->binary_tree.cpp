/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deduceTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) {//先判断存在性
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 0;

        while (1) {
            if (inorder[i] == preorder[0]) {
                break;
            }
            i++;
        }
        vector<int> leftpre;//替代切片操作
        vector<int> leftin;
        vector<int> rightpre;
        vector<int> rightin;
        int temp;
        for (int j = 1; j <= i && j < preorder.size(); j++) {
            leftpre.push_back(preorder[j]);
            leftin.push_back(inorder[j - 1]);
        }
        for (int j = i + 1; j < preorder.size(); j++) {
            rightpre.push_back(preorder[j]);
            rightin.push_back(inorder[j]);
        }
        if (leftpre.size() != 0)
            root->left = deduceTree(leftpre, leftin);//递归
        if (rightpre.size() != 0)
            root->right = deduceTree(rightpre, rightin);
        return root;
    }
};
