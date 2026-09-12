class Solution {
public:
    int minDays(int n) {
        int inf =1e9+7;
        vector<int>dp(n+1,inf);

        dp[0]=-1;
        for(int i=0;i<=n;i++){
            if(dp[i]==inf) continue;
            for(int k =1; ;k++){
                int points = k*(k+1)/2;
                if(i+points>n) break;
                dp[i+points] = min(dp[i+points],dp[i]+k+1);
            }
        }
        return dp[n];
    }
};