class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            // adj[v].push_back({u, w}); // If graph is undirected
        }

        // {distance, {count, node}}
        set<pair<int, pair<int,int>>> st;

        // dist[node][count]
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));

        dist[0][1] = 0;
        st.insert({0, {1, 0}});

        while (!st.empty()) {
            auto it = *st.begin();
            st.erase(st.begin());

            int wt = it.first;
            int cnt = it.second.first;
            int node = it.second.second;

            if (wt != dist[node][cnt]) continue;

            for (auto x : adj[node]) {
                int v = x.first;
                int wt2 = x.second;

                int newCnt;

                if (labels[node] == labels[v]) {
                    newCnt = cnt + 1;
                } else {
                    newCnt = 1;
                }

                if (newCnt > k) continue;

                int newDist = wt + wt2;

                if (newDist < dist[v][newCnt]) {
                    dist[v][newCnt] = newDist;
                    st.insert({newDist, {newCnt, v}});
                }
            }
        }

        int ans = *min_element(dist[n - 1].begin(), dist[n - 1].end());

        return ans == 1e9 ? -1 : ans;
    }
};