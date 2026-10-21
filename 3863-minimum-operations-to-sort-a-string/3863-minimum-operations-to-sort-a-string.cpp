class Solution {
public:
    int minOperations(string s) {
        string str = s;
        sort(str.begin(), str.end());
            if(str==s)
            return 0;

        char mn = s[0];
        char mx = s[0];

        for (int i = 1; i < s.size(); i++) {
            if (s[i] < mn)
                mn = s[i];

            if (s[i] > mx)
                mx = s[i];
        }

        if (s[0] == mn || s[s.size() - 1] == mx)
    return 1;

    if(s.size()==2)
    return -1;

    bool mininPrefix=false;
    bool maxinSuffix=false;

    for(int i=0;i<s.size()-1;i++){
        if(s[i]==mn){
        mininPrefix=true;
        break;
        }
    }
    for(int i=1;i<s.size();i++){
        if(s[i]==mx){
        maxinSuffix=true;
        break;
        }
    }

    if(mininPrefix||maxinSuffix)
    return 2;


    return 3;


    }
};