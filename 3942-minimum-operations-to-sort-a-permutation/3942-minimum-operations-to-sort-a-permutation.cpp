class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        auto get_state = [&](const vector<int>& arr) {
            int idx = -1;
            for (int i = 0; i < n; ++i) {
                if (arr[i] == 0) {
                    idx = i;
                    break;
                }
            }
            bool is_inc = true;
            for (int i = 0; i < n; ++i) {
                if (arr[(idx + i) % n] != i) {
                    is_inc = false;
                    break;
                }
            }
            if (is_inc) return make_pair(0, idx);

            for (int i = 0; i < n; ++i) {
                if (arr[i] == n - 1) {
                    idx = i;
                    break;
                }
            }
            bool is_dec = true;
            for (int i = 0; i < n; ++i) {
                if (arr[(idx + i) % n] != n - 1 - i) {
                    is_dec = false;
                    break;
                }
            }
            if (is_dec) return make_pair(1, idx);

            return make_pair(-1, -1);
        };

        auto target_state = get_state(nums);
        if (target_state.first == -1) return -1;

        vector<vector<int>> dist(2, vector<int>(n, -1));
        queue<pair<int, int>> q;

        q.push({0, 0});
        dist[0][0] = 0;

        while (!q.empty()) {
            auto [tp, shift] = q.front();
            q.pop();

            if (tp == target_state.first && shift == target_state.second) {
                return dist[tp][shift];
            }

            int next_shift = (shift + 1) % n;
            if (dist[tp][next_shift] == -1) {
                dist[tp][next_shift] = dist[tp][shift] + 1;
                q.push({tp, next_shift});
            }

            int next_tp = 1 - tp;
            int rev_shift = (n - shift) % n;
            if (dist[next_tp][rev_shift] == -1) {
                dist[next_tp][rev_shift] = dist[tp][shift] + 1;
                q.push({next_tp, rev_shift});
            }
        }

        return -1;
    }
};