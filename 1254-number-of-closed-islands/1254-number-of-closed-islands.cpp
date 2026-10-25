class Solution {
public:
int m,n;

bool f(vector<vector<int>>&grid,int i,int j){
    if(i<0 || j<0||i>=m||j>=n) return false;
    if(grid[i][j]) return true;
    grid[i][j]=1;
    return f(grid,i+1,j)&f(grid,i,j+1)&f(grid,i-1,j)&f(grid,i,j-1);
}
    int closedIsland(vector<vector<int>>& grid) {
        m =grid.size(),n=grid[0].size();
        int cnt= 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!grid[i][j]) cnt+=f(grid,i,j);
            }
        
        }
        return cnt;

    }
};