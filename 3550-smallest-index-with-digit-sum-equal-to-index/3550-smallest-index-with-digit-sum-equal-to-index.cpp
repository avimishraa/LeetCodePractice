class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            int sum=0;
            while(n>=1){
                int dig=n%10;
                sum+=dig;
                n=n/10;


            }
            if(sum==i)
            return i;
        }

        return -1;
    }
};