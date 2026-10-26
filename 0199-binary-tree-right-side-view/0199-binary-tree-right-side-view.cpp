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
    vector<int> rightSideView(TreeNode* root) {
          if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);

        vector<vector<int>>ans;
       
        vector<int>fin;
        while(!q.empty()){
            vector<int>res; 
            int n =q.size();
            for(int i =0;i<n;i++){
                TreeNode*temp =q.front();
                int val = temp->val;
                res.push_back(val);
                q.pop();
                if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
            }
            ans.push_back(res);
        }
        for(int i=0;i<ans.size();i++){
            fin.push_back(ans[i][0]);
        }
        return fin;
    }
};