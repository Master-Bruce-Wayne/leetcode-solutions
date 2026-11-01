class Solution {
public:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();

        vector<vector<int>> ans(n, vector<int>(n, 1e9));
        set<pair<int,pair<pair<int,int>, pair<int,int>>>> st;
        st.insert({grid[0][0], {{0,0},{-1,-1}}}); ans[0][0] = grid[0][0];

        while(!st.empty()) {
            auto it=st.begin(); 
            int m=it->first, x=it->second.first.first, y=it->second.first.second;
            int px=it->second.second.first, py=it->second.second.second;
            st.erase(st.begin()) ;
            
            // if(m>=ans[x][y])  continue;
            for(int j=0; j<4; j++) {
                int nx=x+dx[j], ny=y+dy[j];
                if(nx<0 || ny<0 || nx>=n || ny>=n) continue;
                if(nx==px && ny==py) continue;
                if(ans[nx][ny]<=max(m, grid[nx][ny])) continue;

                ans[nx][ny]=max(m,grid[nx][ny]);
                st.insert({ans[nx][ny], {{nx,ny}, {x,y}}});
            }
        }

        return ans[n-1][n-1];
    }
};