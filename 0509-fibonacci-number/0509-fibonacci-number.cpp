class Solution {
public:
    int fn(int n,vector<int>&dp){
        if(n<=1)
        return n;

        if(dp[n]!=-1) return dp[n];

        return dp[n]=fn(n-1,dp)+fn(n-2,dp);
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        int ans=fn(n,dp);

        return ans;

        
    }
};