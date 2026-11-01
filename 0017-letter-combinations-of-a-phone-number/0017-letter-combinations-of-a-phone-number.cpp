class Solution {
public:

    void f(string dig,vector<string>&res,string& temp,vector<string>&pad,int idx){

        if(idx==dig.size()){
            res.push_back(temp);
            return;
        }
        string val = pad[dig[idx]-'0'];
        for(int i =0;i<val.size();i++){
            temp.push_back(val[i]);
            f(dig,res,temp,pad,idx+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string dig) {
        vector<string> pad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp;
        vector<string>res;
        f(dig,res,temp,pad,0);
        return res;
    }
};