class Solution {
public:


bool check(vector<string>&b,int row,int col){
    for(int i = row,j=col;i>=0 &&j>=0;i--,j--){
        if(b[i][j]=='Q') return false;
    }

    for(int i = row,j=col;i>=0&&j<b.size();i--,j++){
        if(b[i][j]=='Q') return false;
    }
    return true;
}
void f(int row,vector<string>& b,vector<bool>&cols,vector<vector<string>>& ans){
    if(row==b.size()){
        ans.push_back(b);
        return;
    }
    for(int i=0;i<b.size();i++){
        if(cols[i]) continue;
        if(check(b,row,i)){
            b[row][i]='Q';
            cols[i]=true;
            f(row+1,b,cols,ans);
            b[row][i]='.';
            cols[i]=false;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>b(n,string(n,'.'));
        vector<bool>cols(n,false);
        vector<vector<string>>ans;

        f(0,b,cols,ans);
        return ans;
    }
};