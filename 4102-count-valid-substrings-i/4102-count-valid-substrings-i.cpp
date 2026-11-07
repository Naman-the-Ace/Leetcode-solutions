class Solution {
public:
    long long countValidSubstrings(string s) {
      int n =s.size();
      long long total = 1LL*n*(n+1)/2;
      long long na = 0;

      int last =-1;
      for(int i =2;i<n;i++){
        if(s[i-2]=='a' && s[i-1]=='b' && s[i]=='c'){
            last = i-2;
        }
        na+=last+1;
      }  
      return total-na;
    }
};