class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Check if current element is greater than the next (wrapping around at the end)
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            // If there's more than 1 drop point, it cannot be a rotated sorted array
            if (count > 1) {
                return false;
            }
        }
        
        return true;
    }
};