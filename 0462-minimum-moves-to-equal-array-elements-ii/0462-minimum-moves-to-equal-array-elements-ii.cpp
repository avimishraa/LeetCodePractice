class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int med=0;
        int sum=0;
        int n=nums.size();

        int ans=0;

        if(n%2!=0){
            med=nums[n/2];
            for(int i=0;i<n;i++){
            ans+=abs(med-nums[i]);
            }
        }
        else{
            med=(nums[n/2]+nums[n/2-1])/2;
            for(int i=0;i<n;i++){
            ans+=abs(med-nums[i]);
            }
        }
        

        return ans;
    }
};