class Solution {
public:
    bool checkString(string s) {
        string t =s;

        sort(s.begin(),s.end());
       for (int i =0;i<s.size();i++){
        if(s[i]!=t[i]) return false;
       }
       return true;
    }
};