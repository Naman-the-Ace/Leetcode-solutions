class Solution {
public:

void solve(int s,vector<int>&c,vector<int>&sub,vector<vector<int>>&ans,int rem){
   if(rem==0){
    ans.push_back(sub);
    return;
   }

   for(int i =s;i<c.size();i++){

    if(i>s && c[i]==c[i-1]) continue;

    if(c[i]>rem) break;
    sub.push_back(c[i]);
    solve(i+1,c,sub,ans,rem-c[i]);
    sub.pop_back();

   }

}
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<vector<int>>ans;
        vector<int>sub;
         solve(0,c,sub,ans,t);
         return ans;
    }
};