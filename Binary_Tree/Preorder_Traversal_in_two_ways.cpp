//METHOD ONE
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode** base = (TreeNode**)malloc(sizeof(TreeNode*) * 100);
        TreeNode** top = base;
        TreeNode* p = root;
        while (p != nullptr) {
            result.push_back(p->val);
            if (p->right) {

                *top = p->right;

                top++;
            }

            if (p->left) {

                p = p->left;
            } else if (top != base) {
                top--;
                p = *top;
            } else {
                p = nullptr;
            }
        }
        return result;
    }
};



//METHOD TWO
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode** base = (TreeNode**)malloc(sizeof(TreeNode*) * 100);
        TreeNode** top = base;
        TreeNode* p = root;
        do{
            while(p){
                result.push_back(p->val);
                *top=p;
                top++;
                p=p->left;
            }
            if(top!=base){
                top--;
                p=*top;
                p=p->right;
            }
        }while(p!=nullptr||top!=base);
        return result;
    }
};
