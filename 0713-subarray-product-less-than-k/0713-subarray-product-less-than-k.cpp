class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int left = 0;
        int ansCount = 0;
        int subproduct = 1;

        for (int right = 0; right < nums.size(); right++) {
            subproduct *= nums[right];

            while (subproduct >= k && left <= right) {
                subproduct /= nums[left];
                left++;
            }

            ansCount += (right - left + 1);
        }

        return ansCount;
    }
};