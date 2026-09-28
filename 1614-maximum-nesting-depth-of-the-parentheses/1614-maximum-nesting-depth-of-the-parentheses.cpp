class Solution {
public:
    int maxDepth(string s) {
        int counter=0;
        int maxcounter=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
            counter++;
            if(s[i]==')')
            counter--;

            maxcounter=max(counter,maxcounter);
        }

        return maxcounter;
        
    }
};