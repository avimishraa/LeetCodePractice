class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char> mp(s.begin(),s.end());
        return mp.size();
    }
};