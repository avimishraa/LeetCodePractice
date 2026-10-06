class Solution {
public:
    int minAddToMakeValid(string s) {
        int temp=0;
        int ans=0;
        for(char ch:s){
            if(ch=='(')
            temp++;
            else{
            temp--;
            if(temp<0){
                ans++;
                temp=0;
            }
            }
        }
        return temp+ans;
    }
};