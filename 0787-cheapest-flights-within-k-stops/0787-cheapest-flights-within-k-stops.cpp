class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &it:f){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        pq.push({0,src,0});
   // vector<int>dist(n,1e9);
   vector<int>min_stops(n,INT_MAX);


        while(!pq.empty()){
            auto[cost,node,stops] =pq.top();
            pq.pop();
            if(node == dst) return cost;

            if(stops>=min_stops[node]) continue;
            min_stops[node]=stops;
            if(stops>k) continue;

            for(auto& [v,wt]:adj[node]){
                    pq.push({cost+wt,v,stops+1});
            }
        }
        return -1;
    }
};