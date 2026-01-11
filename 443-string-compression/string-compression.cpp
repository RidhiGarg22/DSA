class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;   // position to write compressed output
        int read = 0;    // position to read input

        while (read < n) {
            char curr = chars[read];
            int count = 0;

            // count consecutive characters
            while (read < n && chars[read] == curr) {
                read++;
                count++;
            }

            // write the character
            chars[write++] = curr;

            // write count if greater than 1
            if (count > 1) {
                string cnt = to_string(count);
                for (char c : cnt) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};
