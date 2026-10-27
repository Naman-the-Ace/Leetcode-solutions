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

    pair<bool,int> f(TreeNode*node){
        if(!node) return {true,0};
        auto[lbal,lh] = f(node->left);
        auto[rbal,rh] =f(node->right);

        bool isBal = lbal&&rbal&&abs(lh-rh)<=1;
        return {isBal,1+max(lh,rh)};
    }
    bool isBalanced(TreeNode* root) {
        return f(root).first;
    }
};