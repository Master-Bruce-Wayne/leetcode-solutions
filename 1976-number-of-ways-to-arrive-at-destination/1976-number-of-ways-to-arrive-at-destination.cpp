#define ll long long
class Solution {
public:
int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        int ans=0;
        int m=roads.size();

        vector<vector<pair<int,int>>> adj(n);
        for(int i=0; i<m; i++) {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        set<pair<ll,ll>> st; vector<ll> d(n, 1e18), cnt(n, 0);
        st.insert({0,0}); d[0]=0; cnt[0]=1;

        while(!st.empty()) {
            auto it = *st.begin(); st.erase(st.begin());
            ll node=it.second, c=it.first;

            // if(c<d[node]) cnt[node]=1;
            // else cnt[node]++;

            for(auto x:adj[node]) {
                ll v=x.first, cost=x.second;
                if(d[v]<c+cost)  continue; 
                if(d[v]==c+cost) cnt[v]=(cnt[v]+cnt[node])%MOD;
                if(d[v]>c+cost) cnt[v]=cnt[node];

                d[v]=min(d[v], c+cost);
                st.insert({c+cost,v});
            }
        }


       return cnt[n-1];

    
    }
};