class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len <= n; l++) {
                int r = l + len - 1;
                cost[l][r] = INT_MAX;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int blocks = len / d;
                    int changes = 0;

                    for (int i = 0; i < d; i++) {
                        for (int j = 0; j < blocks / 2; j++) {
                            int x = l + i + j * d;
                            int y = l + i + (blocks - 1 - j) * d;

                            if (s[x] != s[y]) {
                                changes++;
                            }
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);
                }
            }
        }

        const int INF = 1e9;

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));

        dp[0][0] = 0;

        for (int groups = 1; groups <= k; groups++) {
            for (int i = 1; i <= n; i++) {

                for (int j = 0; j < i - 1; j++) {

                    if (dp[groups - 1][j] == INF)
                        continue;

                    dp[groups][i] = min(
                        dp[groups][i],
                        dp[groups - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};