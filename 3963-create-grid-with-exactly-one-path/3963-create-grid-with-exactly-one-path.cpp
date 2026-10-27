class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m);
        for(int i=0; i<m; i++) ans[i]+='.';
        for(int i=0; i<m-1; i++) {
            for(int j=0; j<n-1; j++) ans[i]+='#';
        }

        for(int i=0; i<n-1; i++) ans[m-1]+='.';

        return ans;
    }
};