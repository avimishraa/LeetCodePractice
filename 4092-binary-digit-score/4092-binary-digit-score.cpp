class Solution {
public:
    int calculateBitOne(int n){
         int count=0;
        while(n>0){
            n=n&(n-1);
            count++;
        }

        return count;
    }
    int calculateScore(int a, int b) {
        int s1=calculateBitOne(a);
        int s2=calculateBitOne(b);

        if(s1>=s2)
        return s1*s2;
        else
        return s2/s1;
       
        
    }
};