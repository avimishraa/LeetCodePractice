class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> squared(n);
        for (int i = 0; i < n; ++i) {
            squared[i] = 1LL * nums[i] * nums[i];
        }
        
        sort(squared.begin(), squared.end());
        
        long long totalScore = 0;
        
        
        int mid = n / 2;
        for (int i = 0; i < n; ++i) {
            if (i < mid) {
                totalScore -= squared[i];
            } else {
                totalScore += squared[i];
            }
        }
        
        return totalScore;
    }
};