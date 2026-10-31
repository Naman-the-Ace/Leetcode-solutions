class Solution {
public:

void backtrack(vector<int>& nums,int s,vector<int>& sub,vector<vector<int>>& ans){
    if(s==nums.size()){
        ans.push_back(sub);
        return;
    }
    sub.push_back(nums[s]);
    backtrack(nums,s+1,sub,ans);
    sub.pop_back();
    backtrack(nums,s+1,sub,ans);
    
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>sub;
        backtrack(nums,0,sub,ans);
        return ans;


    }
};

// class Solution {
// public:

// void backtrack(vector<int>& nums,int s,vector<int>sub,vector<vector<int>>ans){
//     ans.push_back(sub);
//     for(int i = s;i<nums.size();i++){
//         sub.push_back(nums[i]);
//         backtrack(nums,s+1,sub,ans);
//         sub.pop_back();
//     //    backtrack(nums,s+1,sub,ans);
//     }
    
// }


//     vector<vector<int>> subsets(vector<int>& nums) {

//                  vector<vector<int>>ans;
//         vector<int>sub;
//         backtrack(nums,0,sub,ans);
//         return ans;   
//     }
// };

