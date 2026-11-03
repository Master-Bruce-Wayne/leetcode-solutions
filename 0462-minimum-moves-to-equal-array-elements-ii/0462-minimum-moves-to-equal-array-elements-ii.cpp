class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum=0, n=nums.size();
        for(auto x:nums) sum+=x;
        sort(nums.begin(), nums.end());
        int m1=sum/n, m2;

        if(n&1)  m2=nums[n/2];
        else  m2=(nums[n/2-1]+nums[n/2])/2;

        long long t1=0,t2=0,t3=0;
        for(int i=0; i<n; i++) {
            t1+=abs(nums[i]-m1); t2+=abs(nums[i]-m2); //t3+=abs(nums[i]-m3);
        }
        
        return min(t1,t2);
    }
};