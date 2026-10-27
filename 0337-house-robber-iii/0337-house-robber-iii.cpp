// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:

// vector<int>dfs(TreeNode*root){
//     if(!root) return{0,0};

//     vector<int>l =dfs(root->left);
//     vector<int>r  =dfs(root->right);
//     int nonRob= max(l[0],l[1])+max(r[0],r[1]);
//     int rob = root->val+l[0]+r[0];

//     return {nonRob,rob};
// }

//     int rob(TreeNode* root) {
//         vector<int>dp=dfs(root);
//         return max(dp[0],dp[1]);
//     }
// };

class Solution {
public:
    pair<int, int> dfs(TreeNode* root){
        if(!root) return {0,0};
        pair<int, int> left=dfs(root->left);
        pair<int, int> right=dfs(root->right);
        int take=root->val+left.second+right.second;
        int skip=max(left.second, left.first)+max(right.first, right.second);
        return{take, skip};
    }
    int rob(TreeNode* root){
        pair<int, int> a=dfs(root);
        return max(a.first, a.second);
    }
};