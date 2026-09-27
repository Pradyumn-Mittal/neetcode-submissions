class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {};
        int L = 0;
        int maxFreq = 0;
        int maxL = 0;

        for (int R = 0; R < s.length(); R++) {
            freq[s[R] - 'A']++;

            maxFreq = max(maxFreq, freq[s[R] - 'A']);

            while ((R - L + 1) - maxFreq > k) {
                freq[s[L] - 'A']--;
                L++;
            }

            maxL = max(maxL, R - L + 1);
        }

        return maxL;
    }
};