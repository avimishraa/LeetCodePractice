#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (const auto& kv : knowledge) {
            mp[kv[0]] = kv[1];
        }

        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                string key = "";
                i++; // Skip '('
                while (i < n && s[i] != ')') {
                    key.push_back(s[i]);
                    i++;
                }
                // Check key in map
                if (mp.count(key)) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};