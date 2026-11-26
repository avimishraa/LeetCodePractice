class Solution {
public:
    bool canAliceWin(int n) {
        int stones=10;
        bool isaliceturn=true;
        while(stones>0){
            if(n<stones){
                return !isaliceturn;
            }
            n-=stones;
            stones--;
            isaliceturn=!isaliceturn;
        }

        return !isaliceturn;
    }
};