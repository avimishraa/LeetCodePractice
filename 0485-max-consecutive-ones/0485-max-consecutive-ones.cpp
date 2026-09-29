class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxcnt = 0;
        for (int i = 0; i < nums.size(); i++) {

            cnt++;

            if (nums[i] != 1)
                cnt = 0;

            maxcnt = max(cnt, maxcnt);
        }

        return maxcnt;
    }
};