class Solution {
public:
int m,n;

bool f(vector<vector<char>>& b, string w,int r, int c,int idx){
    if(idx==w.size()) return true;
    if(r<0||c<0||r>=m||c>=n||b[r][c]!=w[idx]) return false;

    char temp =b[r][c];
    b[r][c]='*';

    bool ans1= f(b,w,r+1,c,idx+1);
    bool ans2= f(b,w,r,c-1,idx+1);
    bool ans3= f(b,w,r,c+1,idx+1);
    bool ans4= f(b,w,r-1,c,idx+1);
    b[r][c]=temp;
    return ans1||ans2||ans3||ans4;
}
    bool exist(vector<vector<char>>& b, string w) {
        m =b.size(),n=b[0].size();
        int sz = w.size();
        // bool flag  = true
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(f(b,w,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};