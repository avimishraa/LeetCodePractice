class Solution {
public:
    bool isValid(string s) {
    stack<char> st;
    
    for (char c : s) {
        // Push expected closing brackets onto the stack
        if (c == '(') st.push(')');
        else if (c == '{') st.push('}');
        else if (c == '[') st.push(']');
        // If stack is empty or top doesn't match current closing bracket
        else if (st.empty() || st.top() != c) return false;
        else st.pop();
    }
    
    // Valid if all open brackets were properly closed
    return st.empty();
}
};