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

int f(TreeNode* node,int mx){
    if(!node) return 0;
    int ans = node->val>=mx;
    mx = max(mx,node->val);
    ans+=f(node->left,mx);
    ans+=f(node->right,mx);
    return ans;
}
    int goodNodes(TreeNode* root) {
        // int ans =0;
        // queue<pair<TreeNode*,int>>q;
        // if(!root) return 0;
        // q.push({root,root->val});
        // while(!q.empty()){
        //     auto [node,maxSoFar] = q.front();q.pop();
        //     if(node->val>=maxSoFar) ans++;

        //     int maxSoFar = max(maxSoFar,node->val);
        //     if(node->left) q.push({node->left,maxSoFar});
        //     if(node->right) q.push({node->right,maxSoFar});
        // }
        // return ans;

        return f(root,INT_MIN);
    }
};

//TC = O(N),SC= O(h)