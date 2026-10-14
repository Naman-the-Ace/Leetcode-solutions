class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum<1 || sum>num*9) return "";
        string ans(num,'0');
        for(int i=0;sum>0;i++){
            int a = min(9,sum);
            ans[i] = '0'+a;
            sum-=a;
        }
        return ans;
    }
};