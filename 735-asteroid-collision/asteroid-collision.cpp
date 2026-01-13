class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && a < 0 && st.back() > 0) {
                if (abs(st.back()) < abs(a)) {
                    st.pop_back();          // right-moving asteroid explodes
                    continue;
                } else if (abs(st.back()) == abs(a)) {
                    st.pop_back();          // both explode
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;       // current asteroid explodes
                    break;
                }
            }

            if (!destroyed)
                st.push_back(a);
        }

        return st;
    }
};
