class Solution {
public:
    
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        // int cnt=0; int root=-1;
        int n=colors.length();
        unordered_map<char, char> nxt = {{'R', 'B'}, {'B', 'W'}, {'W', 'R'}};
        vector<int> id(n,0), od(n,0);
        for(int i=0; i<n-1; i++) {
            int u=edges[i][0], v=edges[i][1];
            if(colors[u]==colors[v])  return -1;
            if(nxt[colors[u]]==colors[v])  { id[v]++; od[u]++; }
            if(nxt[colors[v]]==colors[u])  { id[u]++; od[v]++; }

            if(od[u]>2 || od[v]>2)  return -1;
        } 

        int cnt=0, ans=-1;
        for(int i=0; i<n; i++) {
            if(id[i]==0) { cnt++; ans=i; }
        }

        if(cnt!=1)  return -1;
        return ans;  
        
    }
};