class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;

        for(int i=0;i<n;i++){
            int freq[26]={0};

            for(int j=i;j<n;j++){
                int freqMax=0;
                int freqMin=INT_MAX;
                freq[s[j]-'a']++;

                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                    freqMax=max(freq[k],freqMax);
                    freqMin=min(freq[k],freqMin);
                    }

                    
                }
                ans+=freqMax-freqMin;


            }
        }

        return ans;
    }
};