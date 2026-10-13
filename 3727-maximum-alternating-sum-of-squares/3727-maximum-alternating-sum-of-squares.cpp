class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        sort(a.begin(),a.end(),[](int a,int b){
            return abs(a)>abs(b);
        });
        long long ans=0,l=0,r= a.size()-1;
        while(l<=r){
            ans+=(long long) a[l]*a[l++];
            if(l<=r) ans -=(long long)a[r]*a[r--];
        }
        return ans;
             
    }
};