class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        map<char, int> need;
        map<char, int> window;

        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int count = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            window[c]++;

            // This occurrence actually contributes to matching t
            if (need[c] > 0 && window[c] <= need[c]) {
                count++;
            }

            // We have a valid window
            while (count == t.size()) {
                
                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                // Removing this character makes the window invalid
                if (need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar]) {
                    count--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};