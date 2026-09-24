class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> mp(candyType.begin(),candyType.end());
        int candyCanEat=candyType.size()/2;
        if(mp.size()>=candyCanEat)
        return candyCanEat;
        

        return mp.size();
        
    }
};