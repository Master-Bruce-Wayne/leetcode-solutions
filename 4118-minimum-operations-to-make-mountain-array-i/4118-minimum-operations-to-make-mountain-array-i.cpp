
class Solution {
public:
    void helper(vector<int>& a, vector<vector<int>>& dp) {
        int n = a.size();
        int m = dp[0].size();

        for(int j = 1; j < m; j++) {
            dp[0][j] = min(dp[0][j-1], abs(a[0]-j));
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] = min(
                    dp[i][j-1],
                    dp[i-1][j-1] + abs(a[i]-j)
                );
            }
        }
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return -1;

        int m = *max_element(nums.begin(), nums.end()) + n;

        vector<vector<int>> l(n, vector<int>(m+1, 1e9));
        vector<vector<int>> r(n, vector<int>(m+1, 1e9));

        helper(nums, l);

        vector<int> rev(nums.rbegin(), nums.rend());
        helper(rev, r);

        int ans = 1e9;

        for(int i = 1; i < n-1; i++) {
            for(int j = 2; j < m; j++) {

                int left = l[i-1][j-1];
                int right = r[n-i-2][j-1];

                int temp = left + right + abs(nums[i]-j);

                ans = min(ans, temp);
            }
        }

        return ans;
    }
};
