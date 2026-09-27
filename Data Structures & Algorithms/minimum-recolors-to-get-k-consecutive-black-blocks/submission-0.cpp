class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        int minCount = INT_MAX;
        int L= 0;

        for(int R = 0; R < blocks.size() ;R++) {
            if (blocks[R] == 'W') {
                count++;
            }
            while (R-L+1 > k) {
                if (blocks[L] == 'W') count--;
                L++;
            }
            if(R-L+1 == k)minCount = min(count, minCount);
        }
        return minCount;
    }
};