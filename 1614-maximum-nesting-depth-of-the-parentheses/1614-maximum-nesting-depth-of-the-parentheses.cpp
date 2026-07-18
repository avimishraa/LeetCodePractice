class Solution {
public:
    int maxDepth(string s) {
        int counter=0;
        int maxcounter=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
            counter++;
            maxcounter=max(maxcounter,counter);
            }
            else if(s[i]==')')
            counter--;
        }

        return maxcounter;
    }
};