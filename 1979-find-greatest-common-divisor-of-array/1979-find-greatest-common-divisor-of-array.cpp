class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int b=nums[nums.size()-1];
        int rem=0;

        while(b!=0){
            rem=a%b;
            a=b;
            b=rem;
        }

        return a;
    }
};