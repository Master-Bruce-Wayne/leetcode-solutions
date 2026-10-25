class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        vis[i][j]=1;
        for(int k=0; k<4; k++) {
            int nx=i+dx[k], ny=j+dy[k];
            if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
                if(!vis[nx][ny] && !grid[nx][ny]) {
                    dfs(nx, ny, vis, grid);
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        int cnt1=0, cnt2=0;
        for(int i=0; i<n; i++) {
            if(!vis[i][0] && !grid[i][0]) dfs(i,0,vis,grid);
            if(!vis[i][m-1] && !grid[i][m-1]) dfs(i,m-1,vis,grid);
        }

        for(int i=0; i<m; i++) {
            if(!vis[0][i] && !grid[0][i])  dfs(0,i,vis,grid);
            if(!vis[n-1][i] && !grid[n-1][i])  dfs(n-1,i,vis,grid);
        }

        for(int i=1; i<n-1; i++) {
            for(int j=1; j<m-1; j++) {
                if(!vis[i][j] && !grid[i][j]) { cnt2++; dfs(i,j,vis,grid); }
            }
        }

        return cnt2;
    }
};