class Solution {
public:
    int scoreOfParentheses(string s) {
        int nested=0;
        int score=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
            nested++;
            else {
                nested--;
            if(s[i-1]=='(')
            score+=(1<<nested);
            }
        }

        return score;
        
    }
};