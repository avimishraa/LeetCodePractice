class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int left=0;
        int right=0;
        while(left<word1.size()&&right<word2.size()){
            if(left<=right){
                ans+=word1[left];
                left++;
            }
            else if(right<left){
                ans+=word2[right];
                right++;
            }
        }
        while(left<word1.size()){
            ans+=word1[left];
            left++;
        }

        while(right<word2.size()){
            ans+=word2[right];
            right++;
        }

        return ans;
    }
};