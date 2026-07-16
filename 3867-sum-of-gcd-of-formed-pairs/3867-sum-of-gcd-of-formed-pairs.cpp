class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int mx = 0;

        // Construct prefixGcd
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);

            int a = nums[i];
            int b = mx;

            while (b != 0) {
                int rem = a % b;
                a = b;
                b = rem;
            }

            prefixGcd.push_back(a);
        }

        // Sort the prefixGcd array
        sort(prefixGcd.begin(), prefixGcd.end());

        long long sum = 0;
        int left = 0;
        int right = prefixGcd.size() - 1;

        // Pair smallest with largest
        while (left < right) {
            int a = prefixGcd[left];
            int b = prefixGcd[right];

            while (b != 0) {
                int rem = a % b;
                a = b;
                b = rem;
            }

            sum += a;   // a is the gcd

            left++;
            right--;
        }

        return sum;
    }
};