class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = INT_MAX;

        for(int n : prices) {
            minprice = min(minprice, n);
            maxprofit = max(maxprofit, n - minprice);
        }

        return maxprofit;
    }
};
