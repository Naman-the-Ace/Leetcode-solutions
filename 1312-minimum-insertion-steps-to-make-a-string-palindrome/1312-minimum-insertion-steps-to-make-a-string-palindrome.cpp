class Solution {
public:
int n;
int t[501][501];
    int solve(string &s,int l, int r){
        if(t[l][r]!=-1) return t[l][r];
       if(l>=r) return 0;

       else if(s[l]==s[r]){
        return t[l][r]= solve(s,l+1,r-1);
       }
       
        return t[l][r]= 1+min(solve(s,l,r-1),solve(s,l+1,r));
       
   // return 0;
    }
    int minInsertions(string s) {  

        n=s.length();
        memset(t,-1,sizeof(t));
        return solve(s,0,n-1);
        
    }
};