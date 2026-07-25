class Solution {
public:
    string longestPalindrome(string s) {
    if (s.length() <= 1) return s;
    
    int start = 0, maxLen = 0;
    
    for (int i = 0; i < s.length(); i++) {
        // Odd length palindromes (e.g., "aba")
        int l = i, r = i;
        while (l >= 0 && r < s.length() && s[l] == s[r]) { l--; r++; }
        if (r - l - 1 > maxLen) { start = l + 1; maxLen = r - l - 1; }
        
        // Even length palindromes (e.g., "abba")
        l = i; r = i + 1;
        while (l >= 0 && r < s.length() && s[l] == s[r]) { l--; r++; }
        if (r - l - 1 > maxLen) { start = l + 1; maxLen = r - l - 1; }
    }
    
    return s.substr(start, maxLen);
    } 
};