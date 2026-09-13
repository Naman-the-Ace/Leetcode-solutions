class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans =0;
        int n =img1.size();
        // for(int i =0;i<n;i++){
        //     for(int j =0;j<n;j++){
        //         if(i+1>=n||j+1>=n) continue;
        //         if(img1[i+1][j+1]==img2[i][j]){
        //             cnt++;
        //         }
        //     }
        // }

        for(int dr = -(n-1);dr<=n-1;dr++){
            for(int dc = -(n-1);dc<=n;dc++){
                int cnt= 0;
                for(int i =0;i<n;i++){
                    for(int j =0;j<n;j++){
                        int nr = dr+i;
                        int nc= dc+j;

                        if(nr<n&&nc<n&&nr>=0&&nc>=0){
                            if((img1[nr][nc]==1) &&(img2[i][j]==1)) cnt++;
                        }
                    }
                }
                ans =max(ans,cnt);
            }
        }
        return ans;
    }
};