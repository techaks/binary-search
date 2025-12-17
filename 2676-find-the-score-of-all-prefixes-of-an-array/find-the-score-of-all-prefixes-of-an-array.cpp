class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        int currMax = 0;
        long long preSum = 0 ;
        for (int i = 0; i < n; i++) {
            currMax = max(currMax, nums[i]);
            preSum = preSum + currMax + nums[i];
            res[i] =  preSum;
        }
        return res;
    }
};