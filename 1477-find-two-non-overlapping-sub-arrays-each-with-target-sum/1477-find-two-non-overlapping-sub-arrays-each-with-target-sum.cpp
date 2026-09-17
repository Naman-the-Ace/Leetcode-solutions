class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int x) {
        int n = arr.size();
         int ans = n+1;
         int s = 0; 

        vector<int>dp(n+1,n);

        for(int l = 0 , r = 0 ; r<n;r++){
            s+= arr[r];

            while(s>x) s-=arr[l++];

            dp[r+1] = dp[r];

            if(s==x){
                ans = min(ans,r-l+1+dp[l]);
                dp[r+1] = min(dp[r],r-l+1);
            }
        }
        return ans == n+1 ? -1 : ans;

    }
};