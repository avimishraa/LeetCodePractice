class Solution {
public:
    int maxProduct(int n) {

        vector<int> nums;
        while(n!=0){
            int digit=n%10;
            nums.push_back(digit);
            n=n/10;
        }

        int numsize=nums.size();
        int maxProduct = 0;

        if(numsize>=2){
            sort(nums.begin(),nums.end());
            maxProduct= nums[numsize-1]*nums[numsize-2];

        }
        else{
            maxProduct = n;
        }

        return maxProduct;

        
    }
};