class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_set[256]={0};
        int t_set[256]={0};
        for(int i=0;i<s.size();i++){
            if(s_set[s[i]]!=t_set[t[i]]) return false;
            s_set[s[i]]=i+1;
            t_set[t[i]]=i+1;
        }
        return true;
    }
};