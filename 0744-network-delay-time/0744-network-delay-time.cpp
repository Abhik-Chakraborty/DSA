class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            graph[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto it = pq.top();
            int time = it.first;
            int node = it.second;
            pq.pop();

            if(time > dist[node]){
                continue;
            }

            for(auto iter : graph[node]){
                int nextNode = iter.first;
                int weight = iter.second;
                int newDist = time + weight;

                if(newDist < dist[nextNode]){
                    dist[nextNode] = newDist;
                    pq.push({newDist, nextNode});
                }
            }
        }
        int maxTime = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};