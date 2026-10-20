class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefMax(n + 1, 0);
        vector<int> suffMin(n + 1, 1e9);
        vector<int> prefDrop(n, 0);

        // Step 1: Prefix maximum
        for (int i = 0; i < n; i++) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }

        // Step 2: Suffix minimum
        for (int i = n - 1; i >= 0; i--) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        // Step 3: Count adjacent descents
        for (int i = 1; i < n; i++) {
            prefDrop[i] = prefDrop[i - 1]
                        + (nums[i - 1] > nums[i]);
        }

        int ans = 0;

        // Step 4: Check every divisor of n
        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool valid = true;

            // Step 5: Check every block of length k
            for (int start = 0; start < n; start += k) {
                int end = start + k - 1;

                int drops = prefDrop[end] - prefDrop[start];

                // Include the circular boundary
                if (nums[end] > nums[start]) {
                    drops++;
                }

                // Check circular order and global order
                if (drops > 1 || prefMax[start] > suffMin[start]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ans += k;
            }
        }

        return ans;
    }
};