class Solution {
public:
    int firstUniqChar(string s) {
        int ans=0;
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
                ans = i;
                break;
            }
            else{
                ans=-1;
            }
            

        }
       

        

        return ans;
    }
};