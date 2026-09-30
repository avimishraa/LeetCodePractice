class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        // Extract words from string s
        while (ss >> word) {
            words.push_back(word);
        }

        // Must have equal lengths
        if (pattern.length() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.length(); ++i) {
            char c = pattern[i];
            string w = words[i];

            // Check character to word mapping consistency
            if (charToWord.count(c) && charToWord[c] != w) {
                return false;
            }
            // Check word to character mapping consistency
            if (wordToChar.count(w) && wordToChar[w] != c) {
                return false;
            }

            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};