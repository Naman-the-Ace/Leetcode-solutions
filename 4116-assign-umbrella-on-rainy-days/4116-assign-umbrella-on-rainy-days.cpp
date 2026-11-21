class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        vector<string>ans;

        int n = rain.size();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(i+1<n and rain[i] == rain[i+1] and rain[i] == 1) {
                if(cnt >= 0) {
                    ans.push_back("Alice");
                    cnt--;
                } else {
                    ans.push_back("Bob");
                    cnt++;
                }
            } else if(rain[i] == 1) {
                ans.push_back("Bob");
                cnt++;
            } else if(i+1<n and rain[i] == rain[i+1] and rain[i] == 1) {
                ans.push_back("Alice");
                cnt--;
            } else {
                ans.push_back("None");
            }
        }

        return ans;
    }
};