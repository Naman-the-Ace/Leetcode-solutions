class Solution {
public:

bool isValid(vector<vector<char>>& b,int r,int c,char num){
    for(int i =0;i<9;i++){
        if(b[r][i]==num) return false;
        if(b[i][c]==num) return false;

        int br = 3*(r/3)+i/3;
        int bc = 3*(c/3) +i%3;

        if(b[br][bc]==num) return false;
    }
    return true;
}
    bool solve(vector<vector<char>>& b){

        for(int r= 0;r<9;r++){
            for(int c=0;c<9;c++){
                if(b[r][c]=='.'){
                    for(char num = '1';num<='9';num++){
                        if(isValid(b,r,c,num)){
                            b[r][c]=num;
                            if(solve(b)) return true;
                            b[r][c]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;

    }
    void solveSudoku(vector<vector<char>>& b) {
        solve(b);
    }
};