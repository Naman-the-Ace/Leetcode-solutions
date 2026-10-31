class Solution {
public:

int solve(int i,int sum,vector<int>&nums,int t){
    if(i==nums.size()){
        return sum==t?1:0;
    }

    int pos = solve(i+1,sum+nums[i],nums,t);
    int neg = solve(i+1,sum-nums[i],nums,t);

    return pos+neg;
}
    int findTargetSumWays(vector<int>& nums, int t) {
        return solve(0,0,nums,t);
    }
};