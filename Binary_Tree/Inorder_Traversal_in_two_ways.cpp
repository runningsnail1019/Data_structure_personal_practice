//METHOD ONE
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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode** base=(TreeNode**)malloc(sizeof(TreeNode*)*100);
        TreeNode** top=base;
        TreeNode* p=root;
        vector<int> result;
        do{
            while(p){
                *top=p;
                top++;
                p=p->left;
            }
            if(top!=base){
                top--;
                p=*top;
                result.push_back(p->val);
                p=p->right;
            }
        }while(p||top!=base);
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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode** base = (TreeNode**)malloc(sizeof(TreeNode*) * 100);
        TreeNode** top = base;
        TreeNode* p = root;
        vector<int> result;
        while (p != nullptr||top!=base) {
            if (p) {
                *top = p;
                top++;
                p = p->left;
            }
            else {
                top--;
                p = *top;
                result.push_back(p->val);
                p = p->right;

               
            }
        }
        return result;
    }
};
