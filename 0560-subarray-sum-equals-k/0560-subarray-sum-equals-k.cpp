class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int>mp;
        int sum = 0;
        int cnt=0;
        for(int i:nums){
            sum+=i;
            if(sum==k) cnt++;
            if(mp.count(sum-k)) cnt+=mp[sum-k];
            if(mp.count(sum)) mp[sum]++;
            else mp[sum]++;
        }
        return cnt;
    }
};