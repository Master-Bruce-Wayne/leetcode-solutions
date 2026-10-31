
class Solution {
public:
    const int MOD = 1e9+7;
    int rec(int i, int j, int d, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        // 1->right, 2->down, 0->start
        if(i>=n || j>=m) return 0;
        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j][d]!=-1) return dp[i][j][d];

        int ans=0;
        if(grid[i][j]==0)  {
            ans=(ans+rec(i+1,j,2,dp,grid))%MOD;
            ans=(ans+rec(i,j+1,1,dp,grid))%MOD;
        }
        else{
            if(d==1) ans=(ans+rec(i+1,j,2,dp,grid))%MOD;
            else ans=(ans+rec(i,j+1,1,dp,grid))%MOD;
        }

        return dp[i][j][d] = ans%MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3,-1)));

        return rec(0,0,0,dp,grid);
    }
};