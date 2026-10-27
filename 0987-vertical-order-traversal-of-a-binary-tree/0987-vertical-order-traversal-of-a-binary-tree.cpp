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

//  Left child → (level + 1, col - 1)
// Right child → (level + 1, col + 1)

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return{};
        map<int,vector<pair<int,int>>>mp;
        queue<tuple<TreeNode*,int,int>>q;

        q.push({root,0,0});
        while(!q.empty()){
            auto[curr,level,col] =q.front();
            q.pop();

            mp[col].push_back({level,curr->val});

            if(curr->left){
                q.push({curr->left,level+1,col-1});
            }
            
            if(curr->right){
                q.push({curr->right,level+1,col+1});
            }

        }
    vector<vector<int>>lvls;
    for(auto &p:mp){
        sort(p.second.begin(),p.second.end());
        vector<int>ans;
        for(auto &a:p.second){
            ans.push_back(a.second);
        }
        lvls.push_back(ans);
    }
    return  lvls;

    }
};