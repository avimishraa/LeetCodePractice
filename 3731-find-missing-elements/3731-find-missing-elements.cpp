class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int current = nums[0];
        for(int i=0;i<nums.size();i++){
            while(current<nums[i]){
                ans.push_back(current);
                current++;
            }
            current++;
        }

        return ans;
    }
};