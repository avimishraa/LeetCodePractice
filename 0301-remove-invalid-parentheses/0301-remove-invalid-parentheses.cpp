class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        
        // Calculate the number of misplaced '(' and ')'
        for (char c : s) {
            if (c == '(') {
                l++;
            } else if (c == ')') {
                if (l > 0) {
                    l--;
                } else {
                    r++;
                }
            }
        }
        
        vector<string> result;
        dfs(s, 0, l, r, result);
        return result;
    }

private:
    bool isValid(const string& str) {
        int count = 0;
        for (char c : str) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

    void dfs(const string& str, int start, int l, int r, vector<string>& result) {
        if (l == 0 && r == 0) {
            if (isValid(str)) {
                result.push_back(str);
            }
            return;
        }

        for (int i = start; i < str.length(); ++i) {
            // Skip duplicates to ensure unique results
            if (i > start && str[i] == str[i - 1]) continue;

            // Delete an extra ')'
            if (r > 0 && str[i] == ')') {
                string next = str.substr(0, i) + str.substr(i + 1);
                dfs(next, i, l, r - 1, result);
            }
            // Delete an extra '('
            else if (l > 0 && str[i] == '(') {
                string next = str.substr(0, i) + str.substr(i + 1);
                dfs(next, i, l - 1, r, result);
            }
        }
    }
};