class Solution {
public:

void solve(vector<vector<int>>&ans,
        vector<int>&sub,
        vector<bool>&used,
        vector<int>&nums){
            if(sub.size()==nums.size()){

             ans.push_back(sub);
            return;
            }
            for(int i = 0;i<nums.size();i++){
                if(used[i]) continue;
                used[i]=1;
                sub.push_back(nums[i]);
                solve(ans,sub,used,nums);
                sub.pop_back();
                used[i]=0;
            }

        }

    vector<vector<int>> permute(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>>ans;
        vector<int>sub;
        vector<bool>used(n,0);
        solve(ans,sub,used,nums);
        return ans;

    }
};