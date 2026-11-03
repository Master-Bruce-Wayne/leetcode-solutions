class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int lo=1e9;
        for(auto x:nums)  lo=min(lo,x);

        int ans=0;
        for(int i=0; i<n; i++) ans+=(nums[i]-lo);

        return ans;
    }
};