class Solution {
public:

typedef pair<int,pair<int,int>>pp;
vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};

    int trapRainWater(vector<vector<int>>& h) {
        int m =h.size(),n=h[0].size();
        priority_queue<pp,vector<pp>,greater<>>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,false));

        for(int row=0;row<m;row++){
            for(int col:{0,n-1}){
                pq.push({h[row][col],{row,col}});
                vis[row][col]=true;
            }
        }
        
        for(int col=0;col<n;col++){
            for(int row:{0,m-1}){
                pq.push({h[row][col],{row,col}});
                vis[row][col]=true;
            }
        }
int water =0;
        while(!pq.empty()){
            pp p = pq.top();
            pq.pop();
            int ht = p.first,r= p.second.first,c=p.second.second;
            for(vector<int>&d:dir){
                int nr = r+d[0],nc = c+d[1];
                if(nr>=0&&nc>=0&&nr<m&&nc<n&&!vis[nr][nc]){
                    water+=max(ht-h[nr][nc],0);
                    pq.push({max(ht,h[nr][nc]),{nr,nc}});
                    vis[nr][nc]=true;
                }
            }
        }
        return water;
    }
};