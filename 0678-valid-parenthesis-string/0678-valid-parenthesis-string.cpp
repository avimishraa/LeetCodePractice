class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else { // c == '*'
                minOpen--;
                maxOpen++;
            }

            // More ')' than possible '(' and '*'
            if (maxOpen < 0) return false;

            // minOpen cannot be negative
            if (minOpen < 0) minOpen = 0;
        }

        return minOpen == 0;
    }
};