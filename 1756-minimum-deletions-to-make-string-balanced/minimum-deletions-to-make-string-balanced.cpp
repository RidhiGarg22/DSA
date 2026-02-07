class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        int cnta=0, cntb=0;
        for(int i=n-1;i>=0;i--){
            cntb+=(s[i]=='b');
        }

        int minDelete=INT_MAX;
        for(int i=0;i<=n;i++){
            
            minDelete=min(minDelete,n-cnta-cntb);
            cnta+=(s[i]=='a');
            cntb-=(s[i]=='b');
        }
        return minDelete;
    }
};