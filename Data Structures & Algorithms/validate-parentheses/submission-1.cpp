class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Opening bracket
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            // Closing bracket
            else {
                if (st.empty())
                    return false;

                if ((c == ')' && st.top() != '(') ||
                    (c == ']' && st.top() != '[') ||
                    (c == '}' && st.top() != '{')) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};