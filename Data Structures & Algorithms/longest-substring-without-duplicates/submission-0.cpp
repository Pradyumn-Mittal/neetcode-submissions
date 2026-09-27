class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxL = 0;
        int freq[256] = {};
        int L = 0;

        for (int R = 0; R < s.length(); R++) {
            char c = s[R];
            freq[(unsigned char)c]++;

            while (freq[(unsigned char)c] > 1){
                --freq[(unsigned char)s[L++]];
            }

            maxL = max(maxL, R - L + 1);
        }

        return maxL;
    }
};
