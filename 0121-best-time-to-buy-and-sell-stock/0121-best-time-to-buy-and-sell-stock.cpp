class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxprofit=0;

        for(int i=0;i<prices.size();i++){
            minPrice=min(prices[i],minPrice);
            maxprofit=max(maxprofit,abs(prices[i]-minPrice));
        }

        return maxprofit;
    }
};