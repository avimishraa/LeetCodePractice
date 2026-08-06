class Solution {
public:
    int smallestNumber(int n, int t) {
       int ans = 0;
        while(ans==0){
            int temp=n;
            int pro=1;
            while(temp!=0){
                int dig=temp%10;
                pro*=dig;
                temp=temp/10;
            }

            if(pro%t==0)
            ans=n;

            n++;
            
        }

        return ans;
    }
};