
class Solution {
public:
    string decodeString(string s) {
        stack<int> countSt;
        stack<string> strSt;
        string curr = "";
        int k = 0;

        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                countSt.push(k);
                strSt.push(curr);
                k = 0;
                curr = "";
            } else if (c == ']') {
                int repeat = countSt.top(); countSt.pop();
                string prev = strSt.top(); strSt.pop();
                while (repeat--) prev += curr;
                curr = prev;
            } else {
                curr += c;
            }
        }
        return curr;
    }
};

