class Solution {
public:
    int minMoves(vector<int>& nums) {
       int ans = 0,maxm = *max_element(nums.begin(),nums.end());
      for(int i:nums) ans+=maxm-i;
        return ans;
    }
};