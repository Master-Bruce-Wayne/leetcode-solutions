class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(int x, int y, long long& sum, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vis[x][y]=1; sum+=grid[x][y];
        for(int i=0; i<4; i++) {
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] && !vis[nx][ny]) {
                dfs(nx,ny,sum, vis, grid);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        int ans=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j])  {
                    long long sum=0;
                    dfs(i,j,sum,vis,grid);
                    if(sum%k==0) ans++;
                }
            }
        }

        return ans;
    }
};