class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int x) {
        int n =arr.size();
         int inf = n+1;

        vector<int>dp(n,inf);

        int l=0,sum=0,ans=inf;

        for(int r = 0;r<n;r++){
            sum+=arr[r];
            while(sum>x){
                sum-=arr[l];
                l++;
            }
            if(sum==x){
                int len =r-l+1;

                if(l>0 && dp[l-1]!=inf){
                    ans =min(ans,len+dp[l-1]);
                }
                dp[r]=len;
            }
            if(r>0){
                dp[r] = min(dp[r],dp[r-1]);
            }
        }

        return ans==inf?-1:ans;

    }
};